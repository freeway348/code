#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e6 + 10, M = 2e6 + 10;

int n,m;
char p[N],s[M];// p ---- 短字符串; s --------- 长字符串; ne----------- next 数组
int ne[N];

int main()
{
    cin >> s + 1 >> p + 1;// 下标从 1 开始
    n = strlen(p + 1);
    m = strlen(s + 1);

    // 求next数组（前缀和后缀的匹配数）
    for (int i = 2, j = 0; i <= n; i ++) // 长字符串长度为 m,从 i 开始，匹配字符串长度为n，从 j 开始
    {
        while (j && p[i] != p[j + 1]) j = ne[j]; // 如果 j 没退到起点，并且前后缀不匹配，则按 next 数组回退到 ne[j] 的位置
        if (p[i] == p[j + 1]) j ++;
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= m; i ++)
    {
        while(j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++;
        if (j == n) // 匹配成功
        {
            cout << i - n + 1 << endl; // 输出匹配成功时，长字符起始位置
            j = ne[j]; // 假如在 s 数组中途就匹配成功了，但我们仍需要往后找看看有没有其他匹配字符串，而此时 j 已经走到结尾了，所以需要回退一步
        }
    }
    for (int i = 1; i <= n; i ++)
        cout << ne[i] << ' ';

    return 0;
}