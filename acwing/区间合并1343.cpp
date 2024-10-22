#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> PII;
vector<PII> segs;

void merge(vector<PII> &segs)
{
    vector<PII> res;
    sort(segs.begin(),segs.end());
    int st = -2e9, ed = -2e9;//扫描区域为正无穷到负无穷
    for (auto seg : segs)
    {
        if (ed < seg.first)//无交集
        {
            if (st != -2e9) res.push_back({st,ed});
            st = seg.first;
            ed = seg.second;
        }
        else ed = max(ed, seg.second);//有交集
    }
    if (st != -2e9) res.push_back({st,ed});//如果传入的segs数组不为空，则将最后一个区间加入到res中
    segs = res;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        int l, r;
        cin >> l >> r;
        segs.push_back({l,r});
    }
    merge(segs);
    int vmin = 0,vmax = 0;
    for (int i = 0; i < segs.size(); i ++)//合并区间后，总区间数可能减少
    {
        vmin = max(vmin, segs[i].second - segs[i].first);
        if (i > 0) vmax = max(vmax, segs[i].first - segs[i - 1].second);
    }
    cout << vmin << ' ' << vmax;
    return 0;
}