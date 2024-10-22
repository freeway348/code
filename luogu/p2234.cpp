#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
int n;
const int N = 4e4 + 10, INF = 1e7;

struct node
{
    int l,r;
    int key,val;
}tr[N];

int root, idx;

int get_node(int key)
{
    tr[++ idx].key = key;
    tr[idx].val = rand();
    return idx;
}   

void build()
{
    get_node(-INF), get_node(INF);
    root = 1, tr[1].r = 2;
}

void zig(int &p) // 右旋
{
    int q = tr[p].l;
    tr[p].l = tr[q].r;
    tr[q].r = p;
    p = q;
}

void zag(int &p) // 左旋
{
    int q = tr[p].r;
    tr[p].r = tr[q].l;
    tr[q].l = p;
    p = q;
}

void insert(int &p, int key)
{
    if (!p) p = get_node(key);
    else if (tr[p].key == key) return;
    else if (tr[p].key > key)
    {
        insert(tr[p].l, key);
        if (tr[p].val < tr[tr[p].l].val) zig(p);
    }
    else if (tr[p].key < key)
    {
        insert(tr[p].r, key);
        if (tr[p].val < tr[tr[p].r].val) zag(p);
    }
}

int get_prev(int p, int key) // 找前驱
{
    if (!p) return - INF;
    if (tr[p].key == key) return tr[p].key; // 要注意，营业额可能会相等
    if (tr[p].key > key) return get_prev(tr[p].l, key);
    return max(tr[p].key, get_prev(tr[p].r, key));
}

int get_next(int p, int key)
{
    if (!p) return INF;
    if (tr[p].key == key) return tr[p].key;
    if (tr[p].key < key) return get_next(tr[p].r, key);
    return min(tr[p].key, get_next(tr[p].l, key));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    build();
    cin >> n;
    LL sum = 0;
    int x;

    for (int i = 1; i <= n; i ++)
    {
        cin >> x;
        if (i == 1) sum += x;
        else sum += min(x - get_prev(root, x), get_next(root, x) - x);

        insert(root, x);
    }
    cout << sum << endl;
}