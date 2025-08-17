#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char * strings_xor(char*s,char*t){
    int len=strlen(s);
    char *ans = (char *)malloc(sizeof(char) * (len + 1)); 
    ans[len]='\0';
    for(int i=0;i<len;i++){
        int num1=s[i]-'0';
        int num2=t[i]-'0';
        ans[i]=(num1!=num2)?'1':'0';
    }
   
    return ans;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char s[1001],t[1001];
    scanf("%1000s",s);
    scanf("%1000s",t);
    char *result=strings_xor(s,t);
    printf("%s",result);
    free(result);
    return 0;
}
