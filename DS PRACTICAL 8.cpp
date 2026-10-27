#include <iostream>
using namespace std;
struct node
{
    int info;
    struct node *left, *right;
};
struct node *create_node(int x)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = x;
    temp->left = temp->right = NULL;
    return temp;
}
void setleft(struct node *q, int x)
{
    struct node *p;
    p = create_node(x);
    q->left = p;
}
void setright(struct node *q, int x)
{
    struct node *p;
    p = create_node(x);
    q->right = p;
}

void inorder(struct node *p)
{
    if (p == NULL)
    {
        return;
    }
    else
    {
        inorder(p->left);
        cout << p->info << " ";
        inorder(p->right);
    }
}
void preorder(struct node *p)
{
    if (p == NULL)
    {
        return;
    }
    else
    {
        cout << p->info << " ";
        preorder(p->left);
        preorder(p->right);
    }
}
void postorder(struct node *p)
{
    if (p == NULL)
    {
        return;
    }
    else
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->info << " ";
    }
}
struct node* insert(struct node* root, int x)
{
    if (root == NULL)
    {
        return create_node(x);
    }

    if (x < root->info)
    {
        if (root->left == NULL)
        {
            setleft(root, x);
        }
        else
        {
            insert(root->left, x);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            setright(root, x);
        }
        else
        {
            insert(root->right, x);
        }
    }
    return root;
}
int main()
{
    int n;
    struct node *root = NULL;
    cout << "PLZZ ENTER THE ROOT: ";
    cin >> n;
    root = create_node(n);
    int choice;
    do
    {
        cout << "\nDO YOU WANT TO INSERT ANY NODE:\n1. Yes (enter 1)\n2. No (enter 2)\n";
        cin >> choice;
        if (choice == 1)
        {
            int x;
            cout << "\nEnter content of the node: ";
            cin >> x;
            root = insert(root, x);
        }
    } while (choice != 2);
int traversalChoice;
do
{
    cout << "\n\n===== TRAVERSAL MENU =====";
    cout << "\n1. Inorder Traversal";
    cout << "\n2. Preorder Traversal";
    cout << "\n3. Postorder Traversal";
    cout << "\n4. Exit";
    cout << "\nEnter your choice: ";
    cin >> traversalChoice;

    switch (traversalChoice)
    {
        case 1:
            cout << "\nInorder Traversal: ";
            inorder(root);
            cout << endl;
            break;

        case 2:
            cout << "\nPreorder Traversal: ";
            preorder(root);
            cout << endl;
            break;

        case 3:
            cout << "\nPostorder Traversal: ";
            postorder(root);
            cout << endl;
            break;

        case 4:
            cout << "\nExiting...";
            break;

        default:
            cout << "\nInvalid Choice!";
    }
} while (traversalChoice != 4);    
    return 0;
}