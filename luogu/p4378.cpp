#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
LL tr[N];
int n;
LL a[N],b[N];

LL lowbit(LL x)
{
    return x & -x;
}

void add(LL x, LL c)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

LL query(LL x)
{
    LL res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    memcpy(b,a,sizeof a);
    sort(b + 1, b + n + 1);
    LL bend = unique(b + 1, b + n + 1) - (b + 1);
    LL ans = 0;
    for (int i = 1; i <= n; i ++) // �� i ����
    {
        int x = lower_bound(b + 1, b + bend + 1, a[i]) - b;
        ans = max(ans, i - query(x)); // query(x) : �� x ֮ǰ�м����� x С�ġ������� x ֮ǰ�ͼ����------������ԣ��ٿ����Ƿ�����ͬ��ֵ�������� i - query(x) �������մ�
        add(x,1);
    }
    cout << ans << endl;
    return 0;
}