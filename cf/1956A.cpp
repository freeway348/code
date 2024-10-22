#include <iostream>
#include <algorithm>

using namespace std;

int p[100010];

int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        int k,q;
        cin >> k >> q;
        for (int i = 0; i < k; i ++)
            cin >> p[i];
        sort(p, p + k);
        while(q --)
        {
            int x;
            cin >> x;
            cout << min(p[0] - 1,x) << ' '; 
        }
        cout << endl;
    }

    return 0;
}