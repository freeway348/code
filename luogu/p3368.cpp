//做法1
// #include <iostream>

// using namespace std;

// const int N = 5e5 + 10;
// int n,m;
// int tr[N], a[N];

// int lowbit(int x)
// {
//     return x & -x;
// }

// void add(int x, int c)
// {
//     for (int i = x; i <= n; i +=lowbit(i)) tr[i] += c;
// }

// int query(int x)//前缀和 ， 求第 x 个数的和
// {
//     int res = 0;
//     for (int i = x; i; i -= lowbit(i))
//         res += tr[i];
//     return res;
// }

// int main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i ++)
//     {
//         cin >> a[i];
//         add(i, a[i] - a[i - 1]);//求差分
//     }
//     while (m --)
//     {
//         int a;
//         cin >> a;
//         if (a == 1)
//         {
//             int x, y, k;
//             cin >> x >> y >> k;
//             add(x, k);
//             add(y + 1, -k);
//         }
//         else if (a == 2)
//         {
//             int x;
//             cin >> x;
//             cout << query(x) << '\n';
//         }
//     }
//     return 0;
// }

//做法2
#include <iostream>

using namespace std;

const int N = 5e5 + 10;
int n,m;
int tr[N], ans[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i <= n; i +=lowbit(i)) tr[i] += c;
}

int query(int x)//前缀和 ， 求前 x 个数的变化值
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
        int a;
        cin >> a;
        if (a == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            add(x, k);
            add(y + 1, -k);//差分数组记录变化的值
        }
        else if (a == 2)
        {
            int k;
            cin >> k;
            cout << ans[k] + query(k) << '\n';
        }
    }
    return 0;
}
