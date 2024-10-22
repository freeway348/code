// ��Ŀ���ٶ���һ�����޳������ᣬ������ÿ�������ϵ�������0�� (acwing �����)

// ���ڣ��������Ƚ��� n �β�����ÿ�β�����ĳһλ��x�ϵ�����c��

// ������������ m ��ѯ�ʣ�ÿ��ѯ�ʰ�����������l��r������Ҫ���������[l, r]֮����������ĺ͡�

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
const int N = 3e5 + 10; // ��Ŀ�涨��Χ�� 1 ~ 1e5 ֮�ڣ��������Ǵ�Ĳ���1 �Ͳ��� 2 һ���� x��l��r ����λ���������Դ洢�ռ�����������������������
int n,m;
int s[N],a[N]; // s �����ǰ׺�ͣ�a �������� c
typedef pair<int,int> PII;
vector<PII> adds,query;
vector<int> alls;

int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid; // �ҵ�alls �е�һ���� x �����
        else l = mid + 1;
    }
    return r + 1; // ���ش� 1 ��ʼ��������Ȼ����Ϊ�±�
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
    {
        int x,c;
        cin >> x >> c;
        adds.push_back({x,c});
        alls.push_back(x);
    }
    for (int i = 0; i < m; i ++)
    {
        int l,r;
        cin >> l >> r;
        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }
    // ȥ��
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    
    // ��
    for (auto item : adds)
    {
        int x = find(item.first); //����ɢ�����ֵ
        a[x] += item.second;
    }

    // ��ǰ׺��
    for (int i = 1; i <= alls.size(); i ++) s[i] = s[i - 1] + a[i]; // ��Ϊfind ���ص��� 1 ~ alls.size() ��Χ���±꣬����һ���� alls.size() ��

    // ѯ��
    for (auto item : query)
    {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}