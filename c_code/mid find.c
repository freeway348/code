#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 50
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
int main() {
 
    int post[MAXNUM] = {0};//�������
    int len_post = 0;
    int i,j;
    int rootN;
 
    while( (scanf("%d",&post[len_post])) != EOF) {//δ֪�����ַ����ָ���ʱ����EOF���ж��Ƿ�������� 
        len_post ++;
    }
 
    rootN = post[len_post-1];//ѭ�����������һ��Ԫ�ؾ��Ǻ����������ĸ��ڵ㣨�������� 
    for( i = 0; i < len_post; i++) {//�ҵ����ڵ�������� 
        if( post[i] > rootN)
            break;//�պ��ҵ���i��Ӧ�ľ�����������һ����㣬break�˳�ѭ����������i++ 
    }
 
    for( j = i; j < len_post; j++) {//�������������С�ڸ��ڵ������������벻��ĳ�������ĺ��������� 
        if( post[j] < rootN ) {
            printf("false");
            break;
        }
    }
 
    if( j == len_post )
        printf("true");//�����������ڵ����������û����С�ڸ��ڵ㣬��ɹ����������� 
 
    return 0;
 
}
