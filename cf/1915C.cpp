#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;

// long long ������������� 9e18

bool check(LL x)
{
    LL l = 1, r = 1e9;
    // ��� r = x ���򵱴��� 2e5 �� 1e9 �������ķ��飬��ӵõ��������������� 2e14, �����һ��midȡ�� l + r >> 1, �� mid = 1e14, mid * mid = 1e28 > 2e14
    // �����⵼���� mid ������ long long �����Χ���ޣ��������������
    while(l <= r)
    {
        LL mid = l + r >> 1;
        if (mid * mid == x) return true;
        if (mid * mid > x) r = mid - 1;
        else l = mid + 1; 
    }
    return false;
}

int main()
{
    // ��ֹ����������ʱTLE
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        cin >> n;
        LL s = 0;
        for (int i = 1; i <= n; i ++)
        {
            LL x;
            cin >> x;
            s += x;
        }
        if (check(s)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}