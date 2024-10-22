#include <iostream>
#include <cstring>
using namespace std;
const int N = 2e5+3,null = 0x3f3f3f3f;
typedef long long ll;
int p[N];

int find (int x)
{
    int k = (x % N + N) % N;//防止会出现负数
    while(p[k] != x && p[k] != null)
    {
        k ++;
        if (k == N) k = 0;
    }
    return k;
}

int main()
{
    int n,x;
    char op[2];
    cin >> n;
    memset(p,0x3f,sizeof p);
    for (int i = 0; i < n ; i++)
    {
        cin >> op >> x;
        int k = find(x);
        if (op[0] == 'Q')
        {
            if(p[k] != null) cout << "Yes" << '\n';
            else cout << "No" << '\n';
        }
        else 
        {
            p[k] = x;
        }
    }
    return 0;
}