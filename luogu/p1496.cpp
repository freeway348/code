#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<long long, long long> PII;
vector<PII> segs;
long long k;

void merge(vector<PII> &segs)
{
    vector<PII> res;
    sort(segs.begin(),segs.end());
    long long st = k - 1, ed = k - 1;//扫描区域为正无穷到负无穷
    for (auto seg : segs)
    {
        if (ed < seg.first)//无交集
        {
            if (st != k - 1) res.push_back({st,ed});
            st = seg.first;
            ed = seg.second;
        }
        else ed = max(ed, seg.second);//有交集
    }
    if (st != k - 1) res.push_back({st,ed});//如果传入的segs数组不为空，则将最后一个区间加入到res中
    segs = res;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        long long l, r;
        k = min(k, l);
        cin >> l >> r;
        segs.push_back({l,r});
    }
    merge(segs);
    long long sum = 0;
    for (auto s : segs)
    {
        sum += s.second - s.first;
    }
    cout << sum << endl;
    return 0;
}