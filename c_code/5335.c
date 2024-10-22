#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main ()
{
    char str[1000]={0};
    int i,len;
    scanf ("%s",str);
    len=strlen(str);
    for (i=len-1;i>=0;i--)
    {
        scanf ("%c",str[i]);
    }
    return 0;
}
