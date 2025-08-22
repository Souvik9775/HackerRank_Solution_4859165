#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100000

typedef struct {
    int arr[MAX];
    int top;
}Stack;

void init(Stack *s){
    s->top=-1;
}
int isEmpty(Stack *s){
    return s->top==-1;
}
void push(Stack *s,int x){
    s->arr[++(s->top)]=x;
}
int pop(Stack *s){
    return s->arr[(s->top)--];
}
int peek(Stack *s){
    return s->arr[s->top];
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
     int q;
     scanf("%d",&q);
     Stack s1,s2;
     init(&s1);
     init(&s2);
     while(q--){
        int type;
        scanf("%d",&type);
        if(type==1){
            int x;
            scanf("%d",&x);
            push(&s1,x);
        }
        else if(type==2){
            if(isEmpty(&s2)){
                while(!isEmpty(&s1)){
                    push(&s2,pop(&s1));
                }
            }
            if(!isEmpty(&s2))pop(&s2);
        }
         else if(type==3){
            if(isEmpty(&s2)){
                while(!isEmpty(&s1)){
                    push(&s2,pop(&s1));
                }
            }
            if(!isEmpty(&s2))printf("%d\n",peek(&s2));
        }
     }
    return 0;
}
