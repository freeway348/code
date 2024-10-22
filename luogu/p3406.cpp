#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 1e5 + 10;
int a[N],b[N],c[N];
int f[N];

int n,m;

int main()
{
    cin >> n >> m;
    int l, r;
    cin >> l;
    for (int i = 1; i < m; i ++) // ���
    {
        cin >> r;
        if (l < r)
        {
            f[l] ++;
            f[r] --;
        }
        else if (l > r)
        {
            f[r] ++;
            f[l] --;
        }
        l = r;
    }
    
    for (int i = 1; i < n; i ++) // ǰ׺��    n - 1 ��Ʊ(�ӵ� i վ���� i + 1 վ)
        f[i] += f[i - 1];

    for (int i = 1; i < n; i ++)
        cin >> a[i] >> b[i] >> c[i];
    
    long long sum = 0;
    for (int i = 1; i < n; i ++)
        sum += min((long long)a[i] * f[i], (long long)c[i] + (long long)b[i] * f[i]);
    cout << sum;
    return 0;
}