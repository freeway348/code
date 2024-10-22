#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
char a[1010][1010]; 
int main()
{
    int t;
    cin >> t;
    memset(a, 0, sizeof a);
    while( t --)
    {
        int n,k;
        cin >> n >> k;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                cin >> a[i][j];
        for (int i = k; i <= n; i += k)
        {
            for (int j = k; j <= n; j += k)
                cout << a[i][j];
            cout << endl;
        }
    }

    return 0;
}