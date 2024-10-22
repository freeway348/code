#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int a[N],b[N];
struct node
{
    LL val;
    int x;
    int y;
    bool operator <(const node &M)const 
    {
        return M.val < val;
    }
};
priority_queue<node> heap;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    for (int i = 0; i < n; i ++)
        cin >> b[i];
    for (int i = 0; i < n; i ++)
        heap.push({a[i] + b[0], i, 0});
    for(int i = 0; i < n; i ++)
    {
        auto t = heap.top();
        heap.pop();
        t.y ++;
        cout << t.val << ' ';
        heap.push({a[t.x] + b[t.y], t.x, t.y});
    }
    return 0;
}