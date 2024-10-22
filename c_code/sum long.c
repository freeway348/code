#include <stdio.h>
#include <string.h>

int jinwei = 0;

int invert(char *s){
    int i=0,j,l;
    char temp;
    l = strlen(s);
    j = l-1;
    while(s[i]=='0'){
        l--;
        s[i] = s[j];
        s[j] = '\0';
        i++;
        j--;
    }
    for(;j>i;i++,j--){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    return l;
}

char add(int a, int b){
    int temp;
    temp = (a+b)%10+jinwei;
    jinwei = (a+b)/10;
    if(temp==10){
        temp = 0;
        jinwei++;
    }
    return temp+'0';
}

int main(){
    char a[128],b[128],res[128]={'0'},str;
    int la,lb,i,lres;
    gets(a);
    gets(str);
    gets(b);
    la = invert(a);
    lb = invert(b);
    for(i=0;i<la&&i<lb;i++){
        res[i] = add(a[i]-'0',b[i]-'0');
    }
    if(la<lb){
        for(;b[i]!='\0';i++){
            res[i] = add(0,b[i]-'0');
        }
    }
    else{
        for(;a[i]!='\0';i++){
            res[i] = add(a[i]-'0',0);
        }
    }
    if(jinwei==1)
        res[i++] = '1';
    res[i] = '\0';
    lres = strlen(res);
    for(i=lres-1;i>=0;i--)
        printf("%c",res[i]);
    printf("\n");
    getchar();
    return 0;
}
