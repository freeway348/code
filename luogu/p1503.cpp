// ƽ���� -------- treap(tree + heap)
/*
BST ----- ���������� (һ������²�������ͬ��Ȩֵ�����У�������һ��ans����¼Ȩֵ���ֵĴ���)  ---------- ��������õ���ֵ�������������������
������--------> ��̬ά��һ����������
���ʣ� 1.��ǰ�ڵ�����������κ�һ�����Ȩֵ  <  ��ǰ�ڵ��Ȩֵ
      2.��ǰ�ڵ�����������κ�һ�����Ȩֵ  >  ��ǰ�ڵ��Ȩֵ
����������1. ���룻    2. ɾ����    3.��ǰ��/��̣�ǰ��-----��������е�ǰһ��λ�ã� ���--------��������еĺ�һ��λ�ã�

���⣺ acwing����ͨƽ����
*/ 

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, INF = 1e8;
int n,m;
int a[N],k;
struct Node
{
    int l,r;
    int key,val;
    int cnt,size; // cnt:��ֵ��ͬ�ĸ����� size��ÿһ���ڵ�������ܽ�����
    bool flag; // �ж��Ƿ�ը, true: û��ը�� false����ը��
}tr[N];

int root, idx; // root:���ڵ㣬 idx����ǰ���䵽�Ľڵ�

void pushup(int p) // ����ÿ���ڵ��sizeֵ
{
    tr[p].size = tr[p].cnt;
    if (tr[p].key == tr[tr[p].l].key + 1)
        tr[p].size += tr[tr[p].l].size;
    if (tr[p].key == tr[tr[p].r].key - 1)
        tr[p].size += tr[tr[p].r].size;
}

int get_node(int key) // �����ڵ�
{
    tr[++ idx].key = key;
    tr[idx].val = rand(); // ȡ���ֵ
    tr[idx].cnt = tr[idx].size = 1; // Ҷ�ڵ�
    tr[idx].flag = true;
    return idx;
}

void build() // ��ʼ��
{
    get_node(-INF), get_node(INF);
    root = 1, tr[1].r = 2;
    pushup(root); // ����sizeֵ
}

void insert(int &p, int key) // ͬ��Ҫ���¸��ڵ㣬������Ҫ�õ�����
{
    // ȫ�ֱ���Ĭ��ֵΪ 0���ṹ��Ҳһ����������˵������һ���� x = 1����ôִ��insert�����ҵ�rootָ��� - INF������ x �� - INF����ô�����������ң�����insert(tr[p].r, key); ������ p == 1����Ȼ����ݹ�
    // ��ʱ p = 2��key = INF������ʱ INF ������������Ϊ�գ����� tr[2].l = tr[2].r = 0, ����ִ�� if (!p) �ж�ͨ����� get_node ������������ֵ�Ĳ������Ҳ����
    if (!p) p = get_node(key); // ��� p == 0, ˵�����ǿյģ�����ֱ�Ӵ����ڵ�
    else if (tr[p].key == key) tr[p].cnt ++;
    else if (tr[p].key > key)
    {
        insert(tr[p].l, key);
    }
    else 
    {
        insert(tr[p].r, key);
    }
    pushup(p);
}

void remove(int &p, int key)
{
    if (!p) return;
    if (tr[p].key == key)
    {
        if (tr[p].cnt > 1) tr[p].cnt --;
        else if (tr[p].l || tr[p].r) // ��ΪҪɾ���ڵ� p������Ҫ�ȿ����ڵ� p ��û������������������������У��Ǿ��Ƚ�����ת�������û�о�ֱ��ɾ��
        {
            if (!tr[p].r || tr[tr[p].l].val > tr[tr[p].r].val) // ��������������ڣ����������������ȼ�����������
            {
                zig(p);
                remove(tr[p].r, key); // ��Ϊ������p ָ��Ľڵ�ı��ˣ�ԭ���� p �ڵ�������������������ڵ�
            }
            else
            {
                zag(p);
                remove(tr[p].l, key);
            }
        }
        else p = 0; // ������������������ڣ���ô��ֱ��ɾ������ 0 ����
    }
    else if (tr[p].key > key) remove(tr[p].l, key); // ����������
    else remove(tr[p].r, key); // ����������

    pushup(p);
}

int get_rank_by_key(int p, int key) // ͨ����ֵ������(�������)
{
    if (!p) return 0;
    if (tr[p].key == key) return tr[tr[p].l].size + 1;
    if (tr[p].key > key) return get_rank_by_key(tr[p].l, key);
    return tr[tr[p].l].size + tr[p].cnt + get_rank_by_key(tr[p].r, key); 
}

int get_key_by_rank(int p, int rank) // ͨ����������ֵ(�������)
{
    if (!p) return INF;
    if (tr[tr[p].l].size >= rank) return get_key_by_rank(tr[p].l, rank);
    if (tr[tr[p].l].size + tr[p].cnt >= rank) return tr[p].key;
    return get_key_by_rank(tr[p].r, rank - tr[tr[p].l].size - tr[p].cnt); 
    // ��Ϊ���������ң����ڵ��size��ı䣬�����������size�����������ֱȸ��ڵ����������Ҫ����������Ҫ��ȥ���ڵ�����������ܸ���
}

int get_prev(int p, int key) // �ҵ��ϸ�С�� key �������, ����С��x����������Ҳ������ǰ��(�������)
{
    if (!p) return -INF;
    if (tr[p].key >= key) return get_prev(tr[p].l, key); // һֱ�����ң�ֱ���ҵ��ϸ�С�� key ��ֵ
    return max(tr[p].key, get_prev(tr[p].r, key)); 
    // �ҵ��ϸ�С�� key �������ĸ��ڵ���ټ����Ҹø��ڵ��������������ҵ����ͷ������ҵ�Ҷ�ӽ��ֵ������Ҳ������ͷ��ص�ǰ�ڵ� p ��keyֵ
}

int get_next(int p, int key) // �ҵ��ϸ���� key ����С��, ��������x����С������Ҳ�����Һ��(�������)
{
    if (!p) return INF;
    if (tr[p].key <= key) return get_next(tr[p].r, key);
    return min(tr[p].key, get_next(tr[p].l, key));
}

int main()
{
    build(); // ���������ڱ�

    cin >> n >> m;

    for (int i = 1; i <= n; i ++)
        insert(root, i);

    while(m --)
    {
        char opt;
        cin >> opt;
        if (opt == 'D')
        {
            int x;
            cin >> x;
            a[k ++] = x;
            remove(root, x);
        }
        else if (opt == 'Q')
        {
            int x;
            cin >> x;
            get_rank_by_key(root, x);
            cout << tr[root].size - 1 << endl;
        }
        else if (opt == 'R')
        {
            insert(root, a[-- k]);
        }
    }

    return 0;
}