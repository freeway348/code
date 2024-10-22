//双指针
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int p[N];

int main()
{
    int n,L;
    cin >> n >> L;
    for (int i = 1; i <= n; i ++)
        cin >> p[i];
    sort(p + 1, p + n + 1,greater<int>());//从大到小排序
    int res = 0;
    for (int h = 1,r = n; h <= n; h ++)//枚举每一个h
    {
        while(r > 0 && p[r] < h ) r --;// 找到最后一个满足 p[r] >= h 条件的值
        if (p[h] >= h - 1 && h - r <= L)//如果p[h] > h - 1，就不需要引用论文，满足条件；如果p[h] == h - 1,则判断是否能引用 h - r 篇论文来将前 h 个论文的引用数提高到 h
            res = h;//越往后学术指数h（这里用res存）就越高
    }
    cout << res;
    return 0;
}