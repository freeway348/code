// 做法一：map 映射
// #include <iostream>
// #include <algorithm>
// #include <map>

// using namespace std;
// typedef long long LL;
// const int N = 2e5 + 10;

// int n;
// LL c;
// LL p[N];
// map<LL,int> a;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> c;
//     for (int i = 0; i < n; i ++)
//     {
//         cin >> p[i];
//         a[p[i]] ++;
//         p[i] -= c;
//     }
//     sort(p,p + n);
//     LL res = 0;
//     for (int i = 0; i < n; i ++)
//         res += a[p[i]];
//     cout << res;
//     return 0;
// }

// 做法二：二分
