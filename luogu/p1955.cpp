#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e7 + 10;
int p[N];
int g[N];
int n,t;
int cnt = 1;

struct node
{
    int x,y,z;
    bool operator< (const node & M)const 
    {
        return M.z < z; // �� z �Ӵ�С����
    } 

}a[N];

int find(int x) // �ҵ����鼯�Ķ���
{
    if (p[x] != x) return find(p[x]);
    return p[x];
}

int main()
{
    cin >> t;
    while(t --)
    {
        memset(g, 0, sizeof g);
        memset(a, 0, sizeof a);
        for (int i = 1; i <= N; i ++)   p[i] = i;
        bool flag = false;
        cin >> n;
        for (int i = 1; i <= n; i ++)
        {
            cin >> a[i].x >> a[i].y >> a[i].z;
            g[cnt ++] = a[i].x;
            g[cnt ++] = a[i].y;

        }
        sort(g, g + cnt);
        int bend = unique(g, g + cnt) - g;
        for (int i = 1; i <= n; i ++)
        {
            a[i].x = lower_bound(g, g + bend, a[i].x) - g;
            a[i].y = lower_bound(g, g + bend, a[i].y) - g;
        }

        sort(a + 1, a + 1 + n); // �������Ƚ����㡶��ȡ����������кϲ����ٸ��ݡ�����ȡ����������в���

        for (int i = 1; i <= n; i ++)
        {
            p[a[i].x] = find(p[a[i].x]);
            p[a[i].y] = find(p[a[i].y]);
            if (a[i].z == 1) 
            {
                if (p[a[i].x] != p[a[i].y])
                    p[find(a[i].x)] = p[a[i].y]; // �Ѳ��鼯 A �Ķ���ָ�� ���鼯 B �Ķ��㣬����һ��Ѱ�Ҳ��鼯 A ��Ԫ�صĶ���ʱ���Ϳ����������ҵ����鼯 B �Ķ��㣬������������ 
            }
            else if (a[i].z == 0)
            {
                if (p[a[i].x] == p[a[i].y])
                    flag = true;
            }
        }
        if (!flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}