#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int,int> PII;
vector<PII> segs;
int merge(vector<PII> &segs)
{
    int sum = 0;
    vector<PII> res;
    sort(segs.begin(),segs.end());
    int st = -1e6, ed = -1e6;
    for (auto seg : segs)
    {
        if (ed < seg.first)
        {
            if (st != -1e6) res.push_back({st,ed}),sum += ed - st + 1;;
            st = seg.first;
            ed = seg.second;
        }
        else ed = max(ed,seg.second);
    }
    if (st != -1e6) res.push_back({st,ed}),sum += ed - st + 1;
    segs = res;
    return sum;
}

int L,m;
int main()
{
    cin >> L >> m;
    for (int i = 0; i < m; i ++)
    {
        int l, r;
        cin >> l >> r;
        segs.push_back({l,r});
    }
    int ans = 0;
    ans += L - merge(segs) + 1;
    cout << ans;
    return 0;
}