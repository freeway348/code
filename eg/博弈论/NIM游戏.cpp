// ��Ŀ��NIM��Ϸ
// ������(xor �� ^) �κ����� 0 ��������䱾��

// �� n ��ʯ�ӣ�ÿ i ���� ai ��ʯ�ӣ�ÿ�ο��Դ�ĳһ����ȡ�����ɸ����Ⱥ�������ȡ�������ʯ�ӿ�ȡ������
// ���������� n ��ʯ�ӵ���������������� a1  xor  a2 xor . . .   xor  xn)�����粻Ϊ 0 �������ֱ�ʤ���������ֱذ�
// �ָ���һ�� x ��������������һλ 1 �ڵ� k λ������ a1 ~ an �б�Ȼ����һ���� ai, ��� k λ�� 1
// x �����жѵ�ʯ�Ӹ���ȫ������õ��Ľ��
// ���� ai xor x < ai
// ÿ�δ� ai ������ ai - (ai xor x) ��ʯ�ӣ���� i ���е�ʯ�Ӿʹ� ai ����� ai xor x ��
// ����������ɵõ���  a1 xor a2 xor �� ai xor x xor �� xor an = x xor x = 0;

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int res = 0;
    while(n --)
    {
        int x;
        cin >> x;
        res ^= x;
    }
    if (res) cout << "����ʤ��" << '\n';
    else cout << "NO" << '\n';
    return 0;
}