#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
vector<int> p;
struct Range
{
    int ts,id;
    bool operator< (const Range &w) const
    {
        return ts < w.ts;
    }
}range[N];
int cnt[N];
bool st[N];
int main()
{
    
    int n,d,k;
    int ans = 0;
    cin >> n >> d >> k;
    for (int i = 1; i <= n; i ++)
    {
        int a,b;
        cin >> a >> b;
        range[i] = {a,b};
    }
    sort(range + 1,range + n + 1);
    for (int i = 1, j = 1; i <= n;i ++)//i先走,j随后
    {
        cnt[range[i].id] ++;
        while(range[i].ts - range[j].ts >= d)
        {
            cnt[range[j].id] --;
            j ++;
        }
        if (cnt[range[i].id] >= k) st[range[i].id] = true;
    }
    for (int i = 1;i <= 1e5;i ++) if (st[i]) cout << i <<'\n';
    return 0;
}