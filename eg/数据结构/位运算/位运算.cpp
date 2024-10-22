//求某个数的二进制有多少个“1” 
#include <iostream>
using namespace std;
int ft(int x)
{
    int ans=0;
    for (int i=31;i>=0;i--)
        if ((x >> i &1)) ans ++;
    return ans;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        int x;
        cin >> x;
        cout << ft(x) << " ";
    }
}
