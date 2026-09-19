#include <iostream>
using namespace std;
int main()
{
    int s;
    char ch;
    cout << "Enter the size number of List: ";
    cin >> s;
    int List[s];
    int key, found = 0;
    int n, count = 0, number, position, choice;
    cout << "Enter the number of Element of list wider a size " << s << ": " << endl;
    cin >> n;
    if (n > s)
    {
        cout << "invalid elements";
        return 0;
    }
    cout << "Enter numbers: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> List[i];
        count++;
    }
do {
    cout << "Enter choice: 1. Insertion 2. deletion 3. search 4. display 5. number of elements \n";
    cout << "choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Enter number 8 position which you insert into list:" << endl;
        cout << "position:" << endl;
        cin >> position;
        cout << "number:" << endl;
        cin >> number;
        if (position == n + 1)
        {
            List[position - 1] = number;
            n++;
            count++;
        }
        else if (position > n + 1)
        {
            cout << "invalid position!!!";
            break;
        }
        else {
            for (int i = n - 1; i >= position-1; i--)
            {
                List[i + 1] = List[i];
            }
        List[position-1] = number;
        n++;
        count ++;
    }
    break;
    case 2:
    int pos;
    cout << "Enter a position between (1 to " << n << ") which you want to delete: ";
    cin >> pos;
    for (int i = pos - 1; i < n - 1; i++)
    {
        List[i] = List[i+1];
    }
    n--;
    count--;
    break;

    case 3:
    cout << "Enter element which you want to search: " << endl;
    cin >> key;
    for (int i = 0; i < n; i++)
    {
        if (List[i] == key)
        {
        cout << "element found at position of" << i + 1 << endl;
        found = 1;
        break;
    }
}
if (found == 0)
{
    cout << "element not found !!!" << endl;
}
break;

case 4:
    for (int i = 0; i < n; i++)
    {
        cout << List[i] << endl;
    }
    break;

case 5:
    cout << "\n Now number of element in the List is " << count << endl;
    break;
}
cout << "\n Do you want to continue? \n yes \n \n If yes enter 'y' or if no then 'N'" << endl;
cin >> ch;
} while (ch == 'y');
return 0;
}