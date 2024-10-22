#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
int mid;
int x;
int n;
priority_queue<int, vector<int>, greater<int> > s_heap;
priority_queue<int, vector<int>> g_heap;

int main()
{
    cin >> n;
    cin >> x;
    mid = x;
    cout << mid << endl;


    for (int i = 2; i <= n; i ++)  
    {
        cin >> x;
        // 令大根堆堆顶元素是第一个小于 mid 的元素，小根堆堆顶元素是第一个大于等于 mid 的元素
        if (x < mid)
            g_heap.push(x);
        else s_heap.push(x);
        
        if (i % 2 == 1) // 如果输入为奇数个
        {
            while(s_heap.size() != g_heap.size()) // 当两个堆内元素数量不相等时，将元素数多的堆中的元素转移到另一个堆中，直到两边的堆元素数量相等
            {
                if (s_heap.size() > g_heap.size()) // 说明 mid 太小了，需要更新
                {
                    g_heap.push(mid);
                    mid = s_heap.top();
                    s_heap.pop();
                    
                }
                else 
                {
                    s_heap.push(mid);
                    mid = g_heap.top();
                    g_heap.pop();
                    
                }
            }
            cout << mid << endl;
        }
        
    
    }
    return 0;
}