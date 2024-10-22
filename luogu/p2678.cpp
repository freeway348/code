#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

const int N = 5e4 + 10;
int L,n,m;
int p[N];

bool check(int x)
{
    int hh = 0;
    int ans = 0; // ȡ�ߵ�ʯ����
    for (int i = 1; i <= n; i ++)
        if (x > p[i] - p[hh]) // ���磺ԭ��ÿһ������Ϊ��2,2,4,1���� x ȡ 3 ʱ����һ�λὫ��һ�� 2 ��ʯ���õ�����ֵ��Ϊ�� 4��4, 1
            ans ++;
        else hh = i;
    return ans <= m;
}

int main()
{

    cin >> L >> n >> m;
    for (int i = 1; i <= n; i ++) // ����� 0�� ����㵽��һ��ʯ�Ӵ��� p[1]
        cin >> p[i];
    p[++n] = L;
    // ���ǵ�ֱ�Ӽ��������ȼ���ÿһ���ļ������㣬�����������ﲻ��ԭ������д��� 
    int l = 1, r = L;
    while(l < r)
    {
        int mid = l + r + 1 >> 1; // �����Ծ����
        if (check(mid)) l = mid; // ����õ���̾�������ֵ mid ��Ҫ�Ĳ��������� M ����˵�� ȡ����,̫���ˣ������ǿ��н⣬������Ҫ����ǿ��н�����ֵ
        else r = mid - 1;
    }
    cout << l;
    return 0;
}