#include <iostream>

using namespace std;
int h[100][100];

int main()
{
    for (int i = 1; i <= 3; i ++)
        for (int j = 1; j <= 3; j ++)
            cin >> h[i][j];
    for (int i = 1; i <= 3; i ++)   
        cout << h[i] << '\n';
    return 0;
}