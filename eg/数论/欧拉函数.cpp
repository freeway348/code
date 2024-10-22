// φ(n) 表示 1 ~ n 中与 n 互质的数的个数
//φ(n) = n * ((p1 - 1) / p1) * ((p2 - 1) / p2) * …… * ((pk - 1) / pk); 其中，p1 ~ pk都是质数
#include <iostream>

using namespace std;
typedef long long LL;

int main()
{
    int n;
    cin >> n;
    while(n --)
    {
        int a;
        cin >> a;
        LL res = a;
        for (int i = 2; i <= a / i; i ++)
        {
            if (a % i == 0)
            {
                res = res * (i - 1) / i;
                while (a % i == 0)
                    a /= i;
            }
        }
        if (a > 1) res = res * (a - 1) / a;
        cout << res << endl;
    }
    return 0;
}