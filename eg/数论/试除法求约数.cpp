//�Գ�����һ����������Լ��(����)
//ʱ�临�Ӷ��� ����n(��n)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> get_divisors(int n)
{
    vector<int> res;
    for (int i = 1; i <= n / i; i ++)
    {
        if (n % i == 0) 
        {
            res.push_back(n % i);
            if (n / i != i) res.push_back(n / i);
        }
    }
    sort(res.begin(),res.end());
    return res;
}

int main()
{
    int n;
    cin >> n;
    auto res = get_divisors(n);
    for (auto t : res)
        cout << t << ' ';
    cout << endl;
    return 0;
}