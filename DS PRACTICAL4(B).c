#include<stdio.h>
#include<ctype.h>

 int stack[50];
 int top=-1;

 void push(int val)
 {
    stack[++top] = val;
 }
 int pop()
 {
    return stack[top--];
 }
 int cal(char op,int op1,int op2);

 int main()
 {
    char post[50];
    int p1,p2,r,i=0;
    fgets(post,sizeof(post),stdin);

    while(post[i] !='\0')
    {
        if(post[i] == ' ' || post[i] == '\n'){
            i++;
            continue;
        }
    }
    if(isdigit(post[i]))
    {
        push(post[i] - '0');
    }
    else {
        p1=pop();
        p2=pop();
        r=cal(post[i],p2,p1);
        push(r);
    }
    i++;

 
 printf("%d\n",pop());
 return 0;
}
int cal(char op,int op1,int op2)
{
    switch(op)
    {
        case '+': return op1+op2;
        case '-': return op1-op2;
        case '*': return op1*op2;
        case '/': return op1 / op2;
        default: printf("invalid operator\n");
        return 0;
    }
}