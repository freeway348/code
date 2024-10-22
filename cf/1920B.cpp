// 因为 alice 想要最大化数组之和，但是，bob 想要最小化数组之和，所以bob一定会将数组中前 x 个最大值取反，而ailice 想要尽可能最大化数组之和，就要尽量减少损失，所以需要将前 k 个最大值去掉，这样损失就能减少一半左右
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        int n,k,x;
        int a[200010] = {0};
        cin >> n >> k >> x;
        for (int i = 1; i <= n; i ++)
            cin >> a[i];

        sort(a + 1, a + n + 1, greater<int>() ); // 从大到小
        
        for (int i = 1; i <= n; i ++)
            a[i] += a[i - 1]; // 计算前缀和
        
        int vmax = - 1e9;

        for (int i = 0; i <= k; i ++) // 假设 alice 删除 i 个元素，求最大值 
        {
            int b;
            if (i + x > n)
                b = a[n] - a[i];
            else 
                b = a[i + x] - a[i];
            vmax = max(vmax, a[n] - a[i] - 2 * b);
        }

        cout << vmax << '\n';
    }
}