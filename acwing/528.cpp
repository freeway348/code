#include <iostream>
#include <utility>

using namespace std;
const int N = 1010;
pair<pair<int,int>,int> p[N];

int main()
{
    int t;
    cin >> t;
    while (t --)
    {
        int n,h,r;
        cin >> n >> h >> r; 
        for (int i = 0; i < n; i ++)
        {
            cin >> p[i].first.first >> p[i].first.second >> p[i].second;
            
        }

    }
    return 0;
}