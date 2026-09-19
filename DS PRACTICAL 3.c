#include<stdio.h>
#include<stdlib.h>
#define s 5
int  tos=-1;
int stk[s];
int empty(void)
{
    if(tos==-1)
    return 1;
    else
    return 0;
}
int full()
{
    if(tos==s-1)
    return 1;
    else
    return 0;
}
void push(int x)
{
    if(!full())
    {
        ++tos;
        stk[tos]=x;
    }
    else
    {
        exit (0);
    }
}
int pop(int x)
{
    if(!empty())
    {
        x=stk[tos];
        tos--;
    }
    else
    {
        exit(0);
    }
}
int peek(int x)
{
    if(!empty())
    {
        x=stk[tos];
    }
    else 
    {
        exit (0);
    }
}
int display()
{
     if(!empty())
     {
        for(int i=0;i<=tos;i++)
        {
         printf("%d ", stk[i]);
        }
     }
     else
     {
        printf("the stack is empty\n");
     }
};
int main()
{
    int n;
    int x;
    char ch;
    int num;
    while(1)
    {
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.peek\n");
        printf("4.display\n");
        printf("entre your choice:");
        scanf("%d",&n);
    switch(n)
    {
        case 1:
        printf("enter the push element");
        scanf("%d",&x);
        push(x);
        break;
        case 2:
        printf("the pop element is =%d",x);
        
        pop(x);
        break;
        case 3:
        printf("the peek element is=%d",x);
        
        peek(x);
        break;
        case 4:
        printf("display elements= ");
        
        display();
        break; 
    };
    printf("\ndo you want to continue\n");
    scanf("%c",&ch);
    if(ch=='n')
    break;
    }
}