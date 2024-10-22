#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 50
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
int main() {
 
    int post[MAXNUM] = {0};//后序遍历
    int len_post = 0;
    int i,j;
    int rootN;
 
    while( (scanf("%d",&post[len_post])) != EOF) {//未知输入字符数字个数时可用EOF来判断是否输入结束 
        len_post ++;
    }
 
    rootN = post[len_post-1];//循环结束，最后一个元素就是后序遍历输出的根节点（最后输出） 
    for( i = 0; i < len_post; i++) {//找到根节点的右子树 
        if( post[i] > rootN)
            break;//刚好找到的i对应的就是右子树第一个结点，break退出循环，避免了i++ 
    }
 
    for( j = i; j < len_post; j++) {//如果右子树中有小于根节点的数，则该输入不是某二叉树的后序遍历结果 
        if( post[j] < rootN ) {
            printf("false");
            break;
        }
    }
 
    if( j == len_post )
        printf("true");//如果遍历完根节点的右子树且没有数小于根节点，则成功遍历右子树 
 
    return 0;
 
}
