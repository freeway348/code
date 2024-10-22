#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long LL;

double culi(int a,int b, int c, int x, int y, int z)
{
    double res = 0.0;
    res = (double)sqrt((a - x) * (a - x) + (b - y) * (b - y) + (c - z) * (c - z));
    return res;
}

struct node
{
    int a,b,c;
    bool operator< (const node & M)const
    {
        return M.c > c;
    }
}p[2000010];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        cin >> p[i].a >> p[i].b >> p[i].c;
    }
    sort(p, p + n);
    double sum = 0;
    for (int i = 0; i < n - 1; i ++)
    {
        sum += culi(p[i].a, p[i].b, p[i].c, p[i + 1].a, p[i + 1].b, p[i + 1].c);
    }
    printf("%.3lf",sum);
    return 0;
}