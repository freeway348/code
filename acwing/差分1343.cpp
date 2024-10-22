#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;
pair<int,int> q[5010];
int p[N];

int main()
{
    int n;
    cin >> n;
    int vmax = 0,vmin = 0,end = -1;//vmax ------work;    vmin --------- not work
    for (int i = 1; i <= n; i ++)
    {
        cin >> q[i].first >> q[i].second;
        end = max(q[i].second,end);
        p[q[i].first] ++;
        p[q[i].second] --;
        //考虑到区间[100,200]与区间[201,300]之间的不工作时间为 1 ，所以以下写法会导致第200秒与第201秒被算成连通的
        // p[q[i].first] ++;
        // p[q[i].second + 1] --;
    }
    sort(q + 1,q + n + 1);
    for (int i = 1; i <= end; i ++)
        p[i] += p[i - 1];
    int l = q[1].first, r = q[1].first;
    for (int i = q[1].first + 1; i <= end; i ++)
    {
        if (p[i - 1] && !p[i])//因为记录的是时刻，而求的是时间间隔
        {
            r = i;
            vmax = max(vmax, r - l);
            l = i;
        }
        else if (!p[i - 1] && p[i])
        {
            r = i;
            vmin = max(vmin, r - l);
            l = i;
        }
    }

    cout << vmax << ' ' << vmin;
    return 0;
}
