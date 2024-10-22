//选出从1到n的数字全排列
#include <iostream>
using namespace std;
#define ll long long
#define N 100010
int n,p[N];
bool st[N];
int path[N];
void dfs(int u)
{
    //当u = 0的时候是在第1层取（层数是1 ~ n）,第0层是一个元素都没取时的情况，而当u = n - 1时说明已经每层都取完了，这时再往下也没有数可取了,所以
    //递归结束条件是u == n
    if (u == n)
    {
        for (int i = 0;i < n; i ++) cout << path[i] << ' ';//path数组存储从0到n-1的路径
        cout << endl;
        return;
    }
    for (int i = 1; i <= n;i ++) //判断第i个数字在该路径中是否被取过
    {
        if (! st[i])//因为要输出全排列，所以st数组仅用来确保每个数仅被取到一次
        {
            st[i] = true;
            path[u] = i;
            dfs(u + 1);
            st[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}