#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
int mid;
int x;
int n;
priority_queue<int, vector<int>, greater<int> > s_heap;
priority_queue<int, vector<int>> g_heap;

int main()
{
    cin >> n;
    cin >> x;
    mid = x;
    cout << mid << endl;


    for (int i = 2; i <= n; i ++)  
    {
        cin >> x;
        // �����ѶѶ�Ԫ���ǵ�һ��С�� mid ��Ԫ�أ�С���ѶѶ�Ԫ���ǵ�һ�����ڵ��� mid ��Ԫ��
        if (x < mid)
            g_heap.push(x);
        else s_heap.push(x);
        
        if (i % 2 == 1) // �������Ϊ������
        {
            while(s_heap.size() != g_heap.size()) // ����������Ԫ�����������ʱ����Ԫ������Ķ��е�Ԫ��ת�Ƶ���һ�����У�ֱ�����ߵĶ�Ԫ���������
            {
                if (s_heap.size() > g_heap.size()) // ˵�� mid ̫С�ˣ���Ҫ����
                {
                    g_heap.push(mid);
                    mid = s_heap.top();
                    s_heap.pop();
                    
                }
                else 
                {
                    s_heap.push(mid);
                    mid = g_heap.top();
                    g_heap.pop();
                    
                }
            }
            cout << mid << endl;
        }
        
    
    }
    return 0;
}