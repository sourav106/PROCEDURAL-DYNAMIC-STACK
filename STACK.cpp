#include <iostream>
#include <stdlib.h>
#define SIZE 3
using namespace std;

typedef struct Stack
{
    int top = -1;
    int *arr;
    int size;
} Stack;

Stack *createStack(int size); // Create memory block for Stack and init the top = -1
bool isEmpty(Stack *s);       // If Stack is Empty return true else false
// bool isFull(Stack *s);         // If Stack is Full Return true
void Push(Stack *s, int item); // Push Element on Top of Stack
int Pop(Stack *s);             // returns Index of Popped Element from Stack
void Display(Stack *s);        // Display Elements of Stack
// int getSize(Stack *s);         // Get Size of Stack
void println(); // Print New 3 lines

inline void println() { cout << "\n\n\n"; }

Stack *createStack(int size = SIZE)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    s->arr = (int *)malloc(sizeof(int) * size);
    s->size = size;
    return s;
}

void Display(Stack *s)
{
    if (s->top < 0) // EMPTY STACK
    {
        cout << "Empty Stack";
        println();
    }
    else if (s->top == 0) // SINGLE ELEMENT PRESENT
        cout << s->arr[s->top] << "\t<==== Top and BOTTOM" << endl;
    else // MORE THAN ONE ELEMENTS
    {
        cout << s->arr[s->top] << "\t<==== Top " << endl;
        for (int i = s->top - 1; i > 0; i--)
            cout << s->arr[i] << endl;
        cout << s->arr[0] << "\t<==== Bottom" << endl;
    }
}

inline bool isEmpty(Stack *s) { return s->top < 0 ? true : false; }

void Push(Stack *s, int item)
{
    if (s->top >= SIZE - 1)                         // TOP = SIZE - 1 (STACK IS FULL)
        s->arr = (int *)realloc(s->arr, ++s->size); // Expanding memory block by 1 of Stack Array
    s->arr[++s->top] = item;
}

int Pop(Stack *s)
{
    if (isEmpty(s))
        return -1;
    else
    {
        int p = s->top--;
        if (s->size > SIZE) // If size > SIZE then, reduce the memory size also
            s->arr = (int *)realloc(s->arr, --s->size);
        return p;
    }
}

void menu()
{
    cout << "1> PUSH\n";
    cout << "2> POP\n";
    cout << "3> DISPLAY\n";
    cout << "4> GET STACK SIZE\n";
    cout << "5> EXIT\n";
}

int main()
{
    int ch;
    int item;
    Stack *s = createStack();
    while (true)
    {
        menu();
        cout << "\nEnter your Choice: ";
        cin >> ch;
        if (ch == 1)
        {
            cout << "\nEnter Item: ";
            cin >> item;
            Push(s, item);
            println();
        }
        else if (ch == 2)
        {
            int p = Pop(s);
            if (p < 0)
                cout << "Empty Stack";

            else
                cout << "\nPopped Item: " << s->arr[p];

            println();
        }
        else if (ch == 3)
        {
            Display(s);
            println();
        }
        else if (ch == 4)
        {
            cout << "Stack Size: " << s->size;
            println();
        }
        else if (ch == 5)
            break;
        else
        {
            cout << "\nInvalid Input!!!\n";
            println();
        }
    }
    return 0;
}