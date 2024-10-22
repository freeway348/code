#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int N = 2e5 + 10;
int n,m;
int idx;
priority_queue<int> bheap; // 大根堆
priority_queue<int,vector<int>, greater<int> > sheap; // 小根堆
int a[N];
int u[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= m; i ++)
        cin >> u[i];
    
    for (int i = 1; i <= m; i ++)
    {
        while(idx < u[i])
        {
            idx ++;
            bheap.push(a[idx]); // 选出第 idx 小的数，加入到小根堆 sheap    
            sheap.push(bheap.top());
            bheap.pop();
        }
        cout << sheap.top() << endl;
        bheap.push(sheap.top()); // 把前 idx 小的数都放在大根堆 bheap 中
        sheap.pop();
    }

    return 0;
}