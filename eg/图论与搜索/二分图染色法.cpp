// ����ͼ-----------���ҽ���ͼ�в��������������еı�����������
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10, M = 2e6 + 10; // N -------- �� �� M --------- �� ������ͼ�����Ա�������)
int idx,e[M],ne[M],h[N];
int color[N]; // ��¼ÿ�����ɫ��
int n,m;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool dfs(int u, int c)
{
    color[u] = c; // Ⱦɫ

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!color[j])
        {
            if (!dfs(j,3 - c)) return false; // ��ͨ���д���������������� -------- �Ƕ���ͼ
        }       
        else if (color[j] == c) return false; // �������ڱߵ���ɫ��ͬ������� 
    }

    return true;
}


int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while(m --)
    {
        int a,b;
        cin >> a >> b;
        add(a,b),add(b,a);
    }

    bool flag = true;
    for (int i = 1; i <= n; i ++)
        if (!color[i]) // ����� i ����û��Ⱦɫ���ͽ���dfs����������ڵ���ͨ��Ⱦɫ
        {
            if (!dfs(i,1)) // ��� i �ŵ����ڵ������ͨ�������������򲻿����Ƕ���ͼ�����Խ�flag ���Ϊfalse�����˳�ѭ��
            {
                flag = false;
                break;
            }
        }
    if (flag) cout << "�Ƕ���ͼ" << endl;
    else cout << "���Ƕ���ͼ" << endl;
    return 0;
}