#include <iostream>

using namespace std;

int t;

int main()
{
    cin >> t;
    while(t --)
    {
        int n;
        int ans = 0;
        cin >> n;
        while(n >= 4)
        {
            ans ++;
            n -= 4;
        }
        if (n) ans ++;
        cout << ans << endl;
    }
    return 0;
}