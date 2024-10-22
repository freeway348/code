#include <iostream>
#include <algorithm>

using namespace std;

char a[100010];

int main()
{
    int n,t;
    cin >> n >> t;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    while(t --)
    {
        int i = 1;
        while(i < n)
        {
            if (a[i] == 'B' && a[i + 1] == 'G')
            {
                swap(a[i],a[i + 1]);
                i ++;
            }
            i ++;
        }
    }
    for (int i = 1; i <= n; i ++)
        cout << a[i]; 
    return 0;
}