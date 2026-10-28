#include <stdio.h>
#include <string.h>
#define MAX_HISTORY 50
#define MAX_TEXT 1000
// Stack structure using a 2D character array
typedef struct
{
    char data[MAX_HISTORY][MAX_TEXT];
    int top;
} Stack;

// Initialize the stack
void init(Stack *s)
{
    s->top = -1;
}
// Check whether the stack is empty
int isEmpty(Stack *s)
{
    return s->top == -1;
}
// Check whether the stack is full
int isFull(Stack *s)
{
    return s->top == MAX_HISTORY - 1;
}
// Push a text state onto the stack
void push(Stack *s, const char text[])
{
    int i;
    // If full, discard the oldest history state
    if (isFull(s))
    {
        for (i = 0; i < MAX_HISTORY - 1; i++)
        {
            strcpy(s->data[i], s->data[i + 1]);
        }
        s->top--;
    }
    s->top++;
    strcpy(s->data[s->top], text);
}
// Pop a text state from the stack
int pop(Stack *s, char result[])
{
    if (isEmpty(s))
    {
        return 0;
    }
    strcpy(result, s->data[s->top]);
    s->top--;
    return 1;
}
// Clear the stack
void clearStack(Stack *s)
{
    s->top = -1;
}
// Display current text
void display(const char text[])
{
    printf("\nCurrent Text: \"%s\"\n", text);
}
// Read a line of text safely
void readLine(char text[], int size)
{
    size_t length;
    if (fgets(text, size, stdin) != NULL)
    {
        length = strlen(text);
        if (length > 0 && text[length - 1] == '\n')
        {
            text[length - 1] = '\0';
        }
        else
        {
            // Discard remaining characters if input is too long
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
            {
                /* Discard extra input */
            }
        }
    }
    else
    {
        text[0] = '\0';
    }
}
// Type new text at the end of the existing text
void typeText(char text[], Stack *undoStack,
              Stack *redoStack)
{
    char newText[MAX_TEXT];
    printf("Enter text to type: ");
    readLine(newText, MAX_TEXT);
    if (strlen(text) + strlen(newText) >= MAX_TEXT)
    {
        printf("Error: Text limit exceeded!\n");
        return;
    }
    // Save the previous state
    push(undoStack, text);
    // A new edit clears redo history
    clearStack(redoStack);
    // Append new text
    strcat(text, newText);
    printf("Text added successfully!\n");
}
// Delete characters from the end of the text
void deleteChars(char text[], Stack *undoStack,Stack *redoStack)
{
    int n;
    int length;
    printf("Enter number of characters to delete: ");
    if (scanf("%d", &n) != 1)
    {
        printf("Invalid input! Enter a number.\n");
        // Clear invalid input
        while (getchar() != '\n')
        {
            /* Discard invalid input */
        }
        return;
    }
    // Remove newline left by scanf
    while (getchar() != '\n')
    {
        /* Discard remaining input */
    }
    length = (int)strlen(text);
    if (n <= 0)
    {
        printf("Enter a positive number!\n");
        return;
    }
    if (length == 0)
    {
        printf("Text is empty. Nothing to delete!\n");
        return;
    }
    // Save the previous state
    push(undoStack, text);
    // A new edit clears redo history
    clearStack(redoStack);
    // Delete at most the existing number of characters
    if (n > length)
    {
        n = length;
    }
    text[length - n] = '\0';
    printf("Characters deleted successfully!\n");
}
// Undo the most recent edit
void undo(char text[], Stack *undoStack,
          Stack *redoStack)
{
    if (isEmpty(undoStack))
    {
        printf("Nothing to undo!\n");
        return;
    }
    // Save current state for redo
    push(redoStack, text);
    // Restore previous state
    pop(undoStack, text);
    printf("Undo successful!\n");
}
// Redo the most recently undone edit
void redo(char text[], Stack *undoStack,
          Stack *redoStack)
{
    if (isEmpty(redoStack))
    {
        printf("Nothing to redo!\n");
        return;
    }
    // Save current state for undo
    push(undoStack, text);
    // Restore the undone state
    pop(redoStack, text);
    printf("Redo successful!\n");
}
// Main function
int main(void)
{
    Stack undoStack;
    Stack redoStack;
    char text[MAX_TEXT] = "";
    int choice;

    // Initialize both stacks
    init(&undoStack);
    init(&redoStack);

    printf("====================================\n");
    printf("       UNDO-REDO TEXT EDITOR\n");
    printf("====================================\n");

    do
    {
        printf("\n----------- MENU -----------\n");
        printf("1. Type Text\n");
        printf("2. Delete Characters\n");
        printf("3. Undo\n");
        printf("4. Redo\n");
        printf("5. Display Text\n");
        printf("6. Exit\n");
        printf("----------------------------\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Enter a number.\n");

            while (getchar() != '\n')
            {
                /* Discard invalid input */
            }
            continue;
        }
        // Remove newline after menu choice
        while (getchar() != '\n')
        {
            /* Discard remaining input */
        }
        switch (choice)
        {
            case 1:
                typeText(text, &undoStack, &redoStack);
                display(text);
                break;

            case 2:
                deleteChars(text, &undoStack, &redoStack);
                display(text);
                break;

            case 3:
                undo(text, &undoStack, &redoStack);
                display(text);
                break;

            case 4:
                redo(text, &undoStack, &redoStack);
                display(text);
                break;

            case 5:
                display(text);
                break;

            case 6:
                printf("\nExiting Text Editor...\n");
                printf("Thank you for using the editor!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
