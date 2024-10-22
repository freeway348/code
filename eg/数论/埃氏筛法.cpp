//�� 1 ~ n �ж��ٸ�����
//ʱ�临�Ӷ�Ϊ O(nlglgn)
#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int prime[N], cnt;
bool st[N];

void is_prime(int n)
{
    for (int i = 2; i <= n; i ++)
    {
        if (!st[i])
        {
            prime[cnt ++] = i;
            for (int j = i + i; j <= n; j += i)
                st[j] = true;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    is_prime(n);
    cout << cnt << endl;
    return 0;
}