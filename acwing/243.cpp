#include <iostream>

using namespace std;

const int N = 5e5 + 10;
int n,m;
int tr[N], ans[N];// tr维护差分数组，Tr维护正常数组前缀和
int p[N];
int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i <= n; i +=lowbit(i)) tr[i] += c;
}

int query(int x)//前缀和 ， 求变化值
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}


int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        cin >> ans[i];
        
    }
    while (m --)
    {
        char op[2];
        cin >> op;
        if (op[0] == 'C')
        {
            int x, y, k;
            cin >> x >> y >> k;
            add(x, k);
            add(y + 1, -k);//差分数组记录变化的值
        }
        else if (op[0] == 'Q')
        {
            int k,z;
            cin >> k >> z;
            int res = 0;
            for (int i = k; i <= z; i ++)
            {
                res += query(i) + ans[i];
            }
            cout << res << '\n';
        }
    }
    return 0;
}