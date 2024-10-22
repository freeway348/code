// 平衡树 -------- treap(tree + heap)
/*
BST ----- 二叉搜索树 (一般情况下不存在相同的权值，若有，则增加一个ans来记录权值出现的次数)  ---------- 中序遍历得到的值是升序排序的有序序列
本质上--------> 动态维护一个有序序列
性质： 1.当前节点的左子树的任何一个点的权值  <  当前节点的权值
      2.当前节点的右子树的任何一个点的权值  >  当前节点的权值
基本操作：1. 插入；    2. 删除；    3.找前驱/后继（前驱-----中序遍历中的前一个位置； 后继--------中序遍历中的后一个位置）

例题： acwing：普通平衡树
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
    int cnt,size; // cnt:数值相同的个数； size：每一个节点的子树总结点个数
}tr[N];

int root, idx; // root:根节点， idx：当前分配到的节点

void pushup(int p) // 更新每个节点的size值
{
    tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + tr[p].cnt;
}

int get_node(int key) // 创建节点
{
    tr[++ idx].key = key;
    tr[idx].val = rand(); // 取随机值
    tr[idx].cnt = tr[idx].size = 1; // 叶节点
    return idx;
}

void build() // 初始化
{
    get_node(-INF), get_node(INF);
    root = 1, tr[1].r = 2;
    pushup(root); // 更新size值
}

void zig(int &p) // 右旋，采用引用是因为旋转时，根节点会改变
{
    // p 就是root根节点的指向值，与main中的root值作用一样，都是指向目前的根节点所处的idx值
    int q = tr[p].l;
    tr[p].l = tr[q].r;
    tr[q].r = p; // 实现左旋操作
    p = q; // 根节点变了
    pushup(tr[p].r), pushup(p); // 因为根节点换了，所以原来的 p 变成了现在的 p 节点的右儿子，并且pushup的顺序也会影响size值的变化，要注意哪个是底层的，要先更新，哪个是高层的(距离根节点更近的)，要后更新
}

void zag(int &p) // 左旋
{
    int q = tr[p].r;
    tr[p].r = tr[q].l;
    tr[q].l = p;
    p = q;
    pushup(tr[p].l), pushup(p);
}

void insert(int &p, int key) // 同样要更新根节点，所以需要用到引用
{
    if (!p) p = get_node(key); // 如果 p == 0, 说明树是空的，所以直接创建节点
    else if (tr[p].key == key) tr[p].cnt ++;
    else if (tr[p].key > key)
    {
        insert(tr[p].l, key);
        if (tr[p].val < tr[tr[p].l].val) zig(p); 
    }
    else 
    {
        insert(tr[p].r, key);
        if (tr[p].val < tr[tr[p].r].val) zag(p); // 因为左旋和右旋操作都不会影响中序遍历的顺序，所以根据val优先级排序，以此进行左旋和右旋操作，可以优化复杂度
    }
    pushup(p);
}

void remove(int &p, int key)
{
    if (!p) return;
    if (tr[p].key == key)
    {
        if (tr[p].cnt > 1) tr[p].cnt --;
        else if (tr[p].l || tr[p].r) // 因为要删除节点 p，所以要先看看节点 p 有没有左子树或者右子树，如果有，那就先进行旋转，如果都没有就直接删除
        {
            if (!tr[p].r || tr[tr[p].l].val > tr[tr[p].r].val) // 如果右子树不存在，或者左子树的优先级比右子树大
            {
                zig(p);
                remove(tr[p].r, key); // 因为左旋后，p 指向的节点改变了，原本的 p 节点变成了右旋后的右子树节点
            }
            else
            {
                zag(p);
                remove(tr[p].l, key);
            }
        }
        else p = 0; // 如果左右子树都不存在，那么就直接删除，置 0 即可
    }
    else if (tr[p].key > key) remove(tr[p].l, key); // 往左子树找
    else remove(tr[p].r, key); // 往右子树找

    pushup(p);
}

int get_rank_by_key(int p, int key) // 通过数值查排名
{
    if (!p) return 0;
    if (tr[p].key == key) return tr[tr[p].l].size + 1;
    if (tr[p].key > key) return get_rank_by_key(tr[p].l, key);
    return tr[tr[p].l].size + tr[p].cnt + get_rank_by_key(tr[p].r, key); 
}

int get_key_by_rank(int p, int rank) // 通过排名找数值
{
    if (!p) return INF;
    if (tr[tr[p].l].size >= rank) return get_key_by_rank(tr[p].l, rank);
    if (tr[tr[p].l].size + tr[p].cnt >= rank) return tr[p].key;
    return get_key_by_rank(tr[p].r, rank - tr[tr[p].l].size - tr[p].cnt); 
    // 因为往右子树找，根节点的size会改变，变成右子树的size，而右子树又比根节点和左子树都要大，所以排名要减去根节点和左子树的总个数
}

int get_prev(int p, int key) // 找到严格小于 key 的最大数, 即：小于x的最大的数，也就是找前驱
{
    if (!p) return -INF;
    if (tr[p].key >= key) return get_prev(tr[p].l, key); // 一直往左找，直到找到严格小于 key 的值
    return max(tr[p].key, get_prev(tr[p].r, key)); 
    // 找到严格小于 key 的子树的根节点后，再继续找该根节点的右子树，如果找到，就返回最右的叶子结点值，如果找不到，就返回当前节点 p 的key值
}

int get_next(int p, int key) // 找到严格大于 key 的最小数, 即：大于x的最小的数，也就是找后继
{
    if (!p) return INF;
    if (tr[p].key <= key) return get_next(tr[p].r, key);
    return min(tr[p].key, get_next(tr[p].l, key));
}

int main()
{
    build(); // 设置两个哨兵

    cin >> n;

    while(n --)
    {
        int opt, x;
        cin >> opt >> x;
        if (opt == 1) insert(root, x); // 操作1：插入一个数值x 
        else if (opt == 2) remove(root, x); // 操作2：删除一个数值x，不用delete是因为已经存在delete关键字，不能重名
        else if (opt == 3) 
        {
            insert(root, x); // 先将查询排名的数 x 插入，以防止treap平衡树中不存在数 x
            int y = get_rank_by_key(root, x) - 1; // 因为哨兵影响了排名
            cout << y << endl;
            remove(root, x);  // 查询结束后删除
        }
        else if (opt == 4) cout << get_key_by_rank(root, x + 1) << endl; // 因为设立了两个哨兵，影响了排名，所以要进行+1-1操作
        else if (opt == 5) cout << get_prev(root, x) << endl;
        else if (opt == 6) cout << get_next(root, x) << endl;
    }

    return 0;
}