//ѡ����1��n������ȫ����
#include <iostream>
using namespace std;
#define ll long long
#define N 100010
int n,p[N];
bool st[N];
int path[N];
void dfs(int u)
{
    //��u = 0��ʱ�����ڵ�1��ȡ��������1 ~ n��,��0����һ��Ԫ�ض�ûȡʱ�����������u = n - 1ʱ˵���Ѿ�ÿ�㶼ȡ���ˣ���ʱ������Ҳû������ȡ��,����
    //�ݹ����������u == n
    if (u == n)
    {
        for (int i = 0;i < n; i ++) cout << path[i] << ' ';//path����洢��0��n-1��·��
        cout << endl;
        return;
    }
    for (int i = 1; i <= n;i ++) //�жϵ�i�������ڸ�·�����Ƿ�ȡ��
    {
        if (! st[i])//��ΪҪ���ȫ���У�����st���������ȷ��ÿ��������ȡ��һ��
        {
            st[i] = true;
            path[u] = i;
            dfs(u + 1);
            st[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}