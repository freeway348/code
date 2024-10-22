#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e5 + 10;
int t;
int n,m,p;
int a[N];
int pos;

int main()
{
    cin >> t;
    while(t --)
    {
        cin >> n >> m >> p;
        for (int i = 1; i <= m; i ++)
            cin >> a[i];
        sort(a + 1, a + 3);
        cin >> pos;
        if (pos < a[1])
        {
            cout << a[1] - 1 << endl;
        }
        else if (pos > a[2])
        {
            cout << n - a[2] << endl;
        }
        else 
        {
            cout << (a[2] - a[1]) / 2 << endl;
        }
    }

    return 0;
}