#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct node
{
    int a,b,c;
    int x;
    int val;

    bool operator <(const node &M)const 
    {
        return val > M.val;
    }

};

priority_queue<node> heap; // 本质上重载运算符就替代了greater函数的作用，从而将大根堆改建成小根堆
int n,m;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        heap.push({a,b,c,1,a + b + c});
    }

    for (int i = 0; i < m; i ++)
    {
        auto t = heap.top();
        heap.pop();
        cout << t.val << ' ';
        heap.push({t.a,t.b,t.c,++t.x,t.x*t.x*t.a+t.x*t.b+t.c});
    }
    return 0;
}