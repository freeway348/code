//stl下的sort函数的正序与倒序排序
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

int main()
{
    int oo[10] = {1,3,4,6,8,2,5,11,35,25};
    sort(oo,oo + 10);
    for (int i = 0; i < 10; i ++)
        cout << oo[i] << ' ';
    cout << '\n';
    sort(oo,oo + 10, greater<int>());
    for (int i = 0; i < 10; i ++)
        cout << oo[i] << ' ';
    return 0;
}