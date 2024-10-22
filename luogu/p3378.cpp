#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int N = 1e6 + 10;
priority_queue<int, vector<int>, greater<int>> heap;
int n;

int main()
{
    cin >> n;
    while(n --)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int y;
            cin >> y;
            heap.push(y);
        }
        else if (x == 2)
        {
            int t = heap.top();
            cout << t << endl;
        }
        else if (x == 3)
            heap.pop();
    }

    return 0;
}