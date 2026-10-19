#include<stdio.h>
#include<stdlib.h>
#define s 5
int queue[s];
int front=-1,rear=-1;
int empty()
{
    if(front==-1)
    return 1;
    else
    return 0;
}
int full()
{
    if(front==(rear+1)%s)
    {
        printf("queue is full");
        return 1;
    }
    else
    {
    return 0;
    }
}
void insert (int x)
{
    if(full())
    {
        
        printf("\nqueue is overflow\n");
    }
    else
    {
        if(front==-1)
        front=0;
        rear=(rear+1)%s;
        queue[rear]=x;
    }
}
void del(int x)
{
    if(empty())
    {
        printf("queue is empty\n");
    }
    else
    {
        x=queue[front];
        if(front==rear)
        {
        front=rear=-1;
        }
        else
        {
        front=(front+1)%s;
        }
        printf("deleted element = %d\n", x);
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
        printf("queue elements are = ");
        for(i = front; ; i = (i + 1) % s)
        {
            printf("%d ", queue[i]);
            if(i == rear)
            break;
        }
        printf("\n");
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
        del(x);
        break;

        case 3:
        display();
    }
}
}