#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char a[ 00010];

int main()
{
    char sta[2], end[2];
    cin >> sta;
    cin >> end;
    int res = 0;
    int hh = 0;
    while(end[0] < sta[0] && end[1] < sta[1]) // 当终点在起点左上角时
    {
        sta[0]--;
        sta[1]--;
        res ++;
        
    }
    return 0;
}