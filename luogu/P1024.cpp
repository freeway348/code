#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const double eps = 1e-3;//记得设为double
double a,b,c,d;
double l,r,mid;

double f(double x)
{
    return a*x*x*x + b*x*x + c*x + d;
}

int main()
{
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    for (int i = -100; i <= 100; i ++)
    {
        l = i, r = i + 1.0;
        if (f(l) == 0) 
        {
            printf("%.2lf ",l);
            continue;
        }
        if (f(l) * f(r) < 0) // 堪根公式
        {
            while(r - l > eps)
            {
                mid = (l + r) / 2;
                if (f(l) * f(mid) < 0) r = mid; // 如果 l ~ mid 没翻转符号，则更新 r
                else l = mid;
            }
            printf("%.2lf ",l);
        }
    }
    return 0;
}