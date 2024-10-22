#include <iostream>
using namespace std;
#define N 100010
int n,k;
int path[N];
int st[N];

void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n;i ++) cout << path[i] << ' ';
        cout << '\n';
        return ;//不写return的话会继续执行下面的for循环进而导致死循环
    }

    for (int i = 1; i <= k;i ++)
    {
        // if (st[i] != k)
        // {
        //     path[u] = i;
        //     st[i] ++;
        //     dfs(u + 1);
        //     st[i] = 0;
        // }
        // 如果这样写只能通过一个测试点，第二个测试点会WA,但如果把st[i] != k的判断条件改为st[i] != k + 1，则可通过
        // 初步猜测是在某种情况下会导致st[i]==k的情况下仍能进入循环
        // 例如，若n = 5,k = 4时，此时我们需要满足条件：五元组，且元素均不大于4，但此时可能出现1 1 1 1 1 
        // 这就导致了st[1]最大能到达5，但我们的判断条件为st[i] != k，此时k = 4，也就是说，第五个 1 无法存储进path并输出
        //最优解是写下面两行代码即可
        path[u] = i;
        dfs(u + 1);
        
    }
}

int main()
{
    cin >> n >> k;
    dfs(0);
    return 0;
}