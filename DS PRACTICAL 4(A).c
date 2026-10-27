#include <stdio.h>
#include <ctype.h>

char stack[20];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int pre(char c)
{
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

int main()
{
    char in[20], post[20];
    int i, j = 0;

    printf("Enter Infix: ");
    scanf("%s", in);

    for (i = 0; in[i] != '\0'; i++)
    {
        if (isalnum(in[i]))
        {
            post[j++] = in[i];
        }
        else
        {
            while (top != -1 && pre(stack[top]) >= pre(in[i]))
            {
                post[j++] = pop();
            }
            push(in[i]);
        }
    }

    while (top != -1)
    {
        post[j++] = pop();
    }

    post[j] = '\0';

    printf("Postfix = %s", post);

    return 0;
}