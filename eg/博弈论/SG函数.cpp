// ����һ�� MEX ����
// MEX���㣺�� S Ϊһ���Ǹ��������ϣ����� MEX(S) Ϊ��������ڼ��� S ����С�Ǹ�����������, ���磺S = {1,2,3}���� MEX(S) = 0
// SG���������� x ���յ㣬���� SG��x�� = 0���� x �����յ㣬�� x ����һ���ص��� y1��y2 , ���� , yn , �� SG(x) = MEX{SG(y1),SG(y2),����,SG(yn)}
// ʵ��SG����------�ü��仯����
// ������ֵ� SG(x) = 0,��˵���߲����յ㣬���ֱذܣ��� SG(X) != 0, ��˵��һ�����ߵ��յ㣬���ֱ�ʤ

// ��Ŀ������ n ��ʯ�ӣ�����ÿ�οɴ��� n ��ʯ����ѡһ������ȡʯ�ӣ�����ȡ���������޶��ģ������Ǹ��������ּ��� S �е�����

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <cstring>
using namespace std;

const int N = 110, M = 10010;
int s[N],f[M];//s ����--------���ּ��ϣ� f ���� ----------- sg����ֵ
int n,m;

int sg(int x)
{
    if (f[x] != -1) return f[x];
    unordered_set<int> S;
    for (int i = 0; i < m; i ++) // ��ÿһ��ʯ�ӵ�sg����
    {
        int sum = s[i];
        if (x >= sum) S.insert(sg(x - sum));//�ݹ�ö�ʯ�ӵ����п���ֵ��sgֵ
    }
    for (int i = 0; ; i ++)
        if (!S.count(i))//MEX�����ҳ� S ��û�е���С��Ȼ��
            return f[x] = i;// ��sgֵ���� f ���鲢����
}

int main()
{
    cin >> m;
    for(int i = 0; i < m; i ++)
        cin >> s[i];
    cin >> n;
    memset(f, -1, sizeof f);
    int res = 0;
    for (int i = 0; i < n; i ++)
    {
        int x;
        cin >> x;
        res ^= sg(x);//��ö�ʯ�ӵ�sg����
    }
    if (res) cout << "���ֱ�ʤ" << endl;
    else cout << "���ֱذ�" << endl;
    return 0;
}
