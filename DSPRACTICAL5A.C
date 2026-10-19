#include<stdio.h>
#include<stdlib.h>
#define s 5
int queue[s];
int front=-1,rear=-1;
int full()
{
   if(rear == s-1)
   return 1;
   else 
   return 0;
}
int empty()
{
    if(front == -1)
    return 1;
    else
    return 0;
}
void insert (int x)
{
    if(full())
    {
        printf("queue is overflow\n");
    }
    else
    {
        if(front==-1)
        front=0;
        queue[++rear]=x;
    }
}
void deleteelement()
{
    if(empty())
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("deleted element is=%d \n",queue[front]);
        front++;
    }
}
void display()
{
    int i;
    if(empty())
    {
        printf("queue is empty\n");
    }
    else
    {
         printf("queue element are = ");
         i=front;

         while(i<=rear)
         {
            printf("%d ",queue[i]);
            i++;
         }
         printf(" \n ");
     }
 }
int main ()
{
    int choice ,x;
    while(1)
    {
        printf("enter your choice:");
        scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("insert the element : ");
        scanf("%d",&x);
        insert(x);
        break;

        case 2:
        deleteelement();
        break;

        case 3:
        display();
        break;

        case 4:
        exit(0);
    }
}
}