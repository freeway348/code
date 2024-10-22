// ���⣺ acwing ��������
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100010, M = 2 * N;
int n;
int h[N],e[M],ne[M],idx; // h ------- �ڽӱ��ͷ�ڵ㣬 idx ------- ָ����һ���㣬 e ------- ��ǰָ���ֵ, ne --------- ��һ���ڵ��ֵ
bool st[N];// �洢һ�±�������ֵ
int ans = N; 

void add(int a, int b) // �� a ����Ӧ���ڽӱ��в���һ�� b ��ͷ�巨��-------- ����һ�� a ָ�� b �ı�
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

// ����� u Ϊ����������  �������
int dfs(int u)
{
    st[u] = true;
    int sum = 1; // �� u Ϊ�ڵ�������ڵ�����
    int res = 0; // res Ϊɾȥ�ڵ� u ֮��ÿ����ͨͼ�����ֵ
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i]; // ��ǰ�ڵ��ֵ
        if (! st[j]) // ���û������
        {
            // s Ϊ���� j �Ľڵ�����
            int s = dfs(j); // ���� j Ϊ������ڽӱ�������±�����ֱ������������·�����һ���ڵ� 
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}

int main()
{
    cin >> n;
    memset(h, -1 ,sizeof h);
    for (int i = 0; i < n - 1; i ++) // n ���㣬 n - 1 ����
    {
        int a,b;
        cin >> a >> b;
        add(a,b);
        add(b,a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}