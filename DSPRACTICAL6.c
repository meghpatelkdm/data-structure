#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *first = NULL;
struct node *create_node(int x)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = x;
    temp->next = NULL;
    return temp;
}
void insert_First(int x)
{
    struct node *temp;
    temp= create_node(x);
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        temp->next = first;
        first = temp;
    }
}
void insert_Last(int x)
{
    struct node *z, *t;
    t = create_node(x);
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        z = first;
        while (z->next != NULL)
        {
            z= z->next;
        }
        z->next = t;
    }
}
void insert(int pos, int x)
{
    struct node *y, *t;
    int c = 1;
    t = create_node(x);
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        y = first;
        while (c != pos - 1)
        {
            y = y->next;
            c++;
        }
        t->next = y->next;
        y->next = t;
    }
}
void display()
{
    struct node *temp = first;
        while (temp != NULL)
        {
            printf("%d\t ", temp->info);
            temp = temp->next;
        }
}
void del_first()
{
    struct node *t;
    t = first;
    first = first->next;
    free(t);
}
void del_last()
{
    struct node *x,*t;
    t = first;
    while (t->next->next != NULL)
        t = t->next;
    x= t->next;
    t->next =NULL;
    free(x);
}
void del(int x)
{
    int c=1;
    struct node *t, *y;
    t = first;
    while (c != x - 1)
    {
     t = t->next;
     c++;
    }
    y = t->next;
    t->next = y->next;
    free(y);
}
int main()
{
    int choice,x,pos;
    while(1)
    {
        printf("enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("Enter element: ");
            scanf("%d", &x);
            insert_First(x);
            break;

            case 2:
            printf("Enter element: ");
            scanf("%d", &x);
            insert_Last(x);
            break;

            case 3:
            printf("Enter position: ");
            scanf("%d", &pos);
            printf("Enter element: ");
            scanf("%d", &x);
            insert(pos, x);
            break;

            case 4:
            del_first();
            break;

            case 5:
            del_last();
            break;

            case 6:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            del(pos);
            break;

            case 7:
            printf("Linked List: ");
            display();
            break;
        }
    }
}