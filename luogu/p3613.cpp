#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int n,q;
map<int, map<int, int>> g;


int main()
{
    cin >> n >> q;
    while(q --)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int i,j,k;
            cin >> i >> j >> k;
            g[i][j] = k;
        }
        else if ( x == 2)
        {
            int i,j;
            cin >> i >> j;
            cout << g[i][j] << endl;
        }
    }
    return 0;
}
