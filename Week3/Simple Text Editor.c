 #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include <stdlib.h>
    
    struct Stack
    {
      char *arr[100][100];
      int tos;  
    };
    
    void push(struct Stack*,char*);
    char *pop(struct Stack*);
    
    int main() {
        int i,place,j,Q,c;
        char warr[100],Str[1000]="";
        struct Stack S1,S2;
        S1.tos=S2.tos=-1;
        scanf("%d",&Q);
        for(i=0;i<Q;i++)
        {
            scanf("%d",&c);
            if(c==1)
            {
                fflush(stdin);
                scanf("%s",warr);
                strcat(Str,warr);
                push(&S2,"1");
                push(&S1,warr);
            }
            else if(c==2)
            {
                int k=0;
                char warr[100]="";
                scanf("%d",&place);
                for(j=strlen(Str)-place;j<strlen(Str);j++)
                {
                    warr[k]=Str[j];
                    k++;
                }
                warr[k]='\0';
                push(&S2,"2");
                push(&S1,warr);
                Str[strlen(Str)-place]='\0';
            }
            else if(c==3)
            {
                scanf("%d",&place);
                printf("%c\n",Str[place-1]);
            }
            else
            {
                if(strcmp(pop(&S2),"1")==0)
                {
                    Str[strlen(Str)-strlen(pop(&S1))]='\0';
                }
                else
                {
                    char *ch;
                    ch=pop(&S1);
                    strcat(Str,ch);
                }
            }
            printf("string=%s\n",Str);
        }      
        return 0;
    }
    
    void push(struct Stack *S,char *arr)
    {
        S->tos=S->tos+1;
        S->arr[S->tos][99]=arr;
        printf("pushed=%s\n",S->arr[S->tos][99]);
    }
    char* pop(struct Stack *S)
    {
        char* arr;
        arr=S->arr[S->tos][99];
        printf("popped=%s\n",S->arr[S->tos][99]);
        S->tos=S->tos-1;
        return arr;
    }
