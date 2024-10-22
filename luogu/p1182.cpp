#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;
int n,m;
LL a[100010];

bool check(int x)
{
    LL res = 0, num = 0; // num --- ����������������; res �� �����
    for (int i = 1; i <= n; i ++)
        if (res + a[i] <= x) res += a[i]; // �������Ͳ����� x���ͼ�����
        else res = a[i], num ++;
    return num < m; // num 
}

int main()
{
    LL l = 0,r = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
    }
    while(l < r)
    {
        int mid = (LL) l + r >> 1;
        if (check(mid)) r = mid; // ������
        else l = mid + 1;
    }
    cout << l;
    return 0;
}