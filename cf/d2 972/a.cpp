#include <iostream>
#include <algorithm>

using namespace std;

int n,t;

int main()
{
    char q[5] = {'a','e','i','o','u'};
    cin >> t;
    while(t --)
    {
        cin >> n;
        int x,y;
        x = n / 5;
        y = n % 5;
        for (int i = 0; i < 5; i ++)
        {
            for (int j = 1; j <= x; j ++)
            {
                cout << q[i];
            }
            if (y)
            {
                y --;
                cout << q[i];
            }
        } 
        cout << endl;
        
    }
    return 0;
}