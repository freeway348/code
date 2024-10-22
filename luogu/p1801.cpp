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
priority_queue<int> bheap; // �����
priority_queue<int,vector<int>, greater<int> > sheap; // С����
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
            bheap.push(a[idx]); // ѡ���� idx С���������뵽С���� sheap    
            sheap.push(bheap.top());
            bheap.pop();
        }
        cout << sheap.top() << endl;
        bheap.push(sheap.top()); // ��ǰ idx С���������ڴ���� bheap ��
        sheap.pop();
    }

    return 0;
}