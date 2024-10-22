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
int n;
struct Node
{
    int l,r;
    int key,val;
    int cnt,size; // cnt:��ֵ��ͬ�ĸ����� size��ÿһ���ڵ�������ܽ�����
}tr[N];

int root, idx; // root:���ڵ㣬 idx����ǰ���䵽�Ľڵ�

void pushup(int p) // ����ÿ���ڵ��sizeֵ
{
    tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + tr[p].cnt;
}

int get_node(int key) // �����ڵ�
{
    tr[++ idx].key = key;
    tr[idx].val = rand(); // ȡ���ֵ
    tr[idx].cnt = tr[idx].size = 1; // Ҷ�ڵ�
    return idx;
}

void build() // ��ʼ��
{
    get_node(-INF), get_node(INF);
    root = 1, tr[1].r = 2;
    pushup(root); // ����sizeֵ
}

void zig(int &p) // ������������������Ϊ��תʱ�����ڵ��ı�
{
    // p ����root���ڵ��ָ��ֵ����main�е�rootֵ����һ��������ָ��Ŀǰ�ĸ��ڵ�������idxֵ
    int q = tr[p].l;
    tr[p].l = tr[q].r;
    tr[q].r = p; // ʵ����������
    p = q; // ���ڵ����
    pushup(tr[p].r), pushup(p); // ��Ϊ���ڵ㻻�ˣ�����ԭ���� p ��������ڵ� p �ڵ���Ҷ��ӣ�����pushup��˳��Ҳ��Ӱ��sizeֵ�ı仯��Ҫע���ĸ��ǵײ�ģ�Ҫ�ȸ��£��ĸ��Ǹ߲��(������ڵ������)��Ҫ�����
}

void zag(int &p) // ����
{
    int q = tr[p].r;
    tr[p].r = tr[q].l;
    tr[q].l = p;
    p = q;
    pushup(tr[p].l), pushup(p);
}

void insert(int &p, int key) // ͬ��Ҫ���¸��ڵ㣬������Ҫ�õ�����
{
    if (!p) p = get_node(key); // ��� p == 0, ˵�����ǿյģ�����ֱ�Ӵ����ڵ�
    else if (tr[p].key == key) tr[p].cnt ++;
    else if (tr[p].key > key)
    {
        insert(tr[p].l, key);
        if (tr[p].val < tr[tr[p].l].val) zig(p); 
    }
    else 
    {
        insert(tr[p].r, key);
        if (tr[p].val < tr[tr[p].r].val) zag(p); // ��Ϊ��������������������Ӱ�����������˳�����Ը���val���ȼ������Դ˽������������������������Ż����Ӷ�
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

int get_rank_by_key(int p, int key) // ͨ����ֵ������
{
    if (!p) return 0;
    if (tr[p].key == key) return tr[tr[p].l].size + 1;
    if (tr[p].key > key) return get_rank_by_key(tr[p].l, key);
    return tr[tr[p].l].size + tr[p].cnt + get_rank_by_key(tr[p].r, key); 
}

int get_key_by_rank(int p, int rank) // ͨ����������ֵ
{
    if (!p) return INF;
    if (tr[tr[p].l].size >= rank) return get_key_by_rank(tr[p].l, rank);
    if (tr[tr[p].l].size + tr[p].cnt >= rank) return tr[p].key;
    return get_key_by_rank(tr[p].r, rank - tr[tr[p].l].size - tr[p].cnt); 
    // ��Ϊ���������ң����ڵ��size��ı䣬�����������size�����������ֱȸ��ڵ����������Ҫ����������Ҫ��ȥ���ڵ�����������ܸ���
}

int get_prev(int p, int key) // �ҵ��ϸ�С�� key �������, ����С��x����������Ҳ������ǰ��
{
    if (!p) return -INF;
    if (tr[p].key >= key) return get_prev(tr[p].l, key); // һֱ�����ң�ֱ���ҵ��ϸ�С�� key ��ֵ
    return max(tr[p].key, get_prev(tr[p].r, key)); 
    // �ҵ��ϸ�С�� key �������ĸ��ڵ���ټ����Ҹø��ڵ��������������ҵ����ͷ������ҵ�Ҷ�ӽ��ֵ������Ҳ������ͷ��ص�ǰ�ڵ� p ��keyֵ
}

int get_next(int p, int key) // �ҵ��ϸ���� key ����С��, ��������x����С������Ҳ�����Һ��
{
    if (!p) return INF;
    if (tr[p].key <= key) return get_next(tr[p].r, key);
    return min(tr[p].key, get_next(tr[p].l, key));
}

int main()
{
    build(); // ���������ڱ�

    cin >> n;

    while(n --)
    {
        int opt, x;
        cin >> opt >> x;
        if (opt == 1) insert(root, x); // ����1������һ����ֵx 
        else if (opt == 2) remove(root, x); // ����2��ɾ��һ����ֵx������delete����Ϊ�Ѿ�����delete�ؼ��֣���������
        else if (opt == 3) 
        {
            insert(root, x); // �Ƚ���ѯ�������� x ���룬�Է�ֹtreapƽ�����в������� x
            int y = get_rank_by_key(root, x) - 1; // ��Ϊ�ڱ�Ӱ��������
            cout << y << endl;
            remove(root, x);  // ��ѯ������ɾ��
        }
        else if (opt == 4) cout << get_key_by_rank(root, x + 1) << endl; // ��Ϊ�����������ڱ���Ӱ��������������Ҫ����+1-1����
        else if (opt == 5) cout << get_prev(root, x) << endl;
        else if (opt == 6) cout << get_next(root, x) << endl;
    }

    return 0;
}