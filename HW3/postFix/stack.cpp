// Stefan Retief
// CS211 postFix, HW3
// Stack Class - Class File
// ======================================================

#include <iostream>
#include "stack.hpp"

//PURPOSE:      (Private) To handle unexpected errors encountered by other
//              methods
//PARAMS:       String message to be displayed
//ALGORITHM:    'cout' the message and exit program with error code 1
void Stack::stackError(string msg) {
    cout << msg << endl;
    exit(1);
}

//PURPOSE:      Constructor which initilizes top
Stack::Stack()
{
    top = -1;
}

//PURPOSE:      To return if a stack is empty or not (returns true or false)
//PARAMS:       None
//ALGORITHM:    if top is at the initilized state of -1, return true, else
//              return false
bool Stack::isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}

//PURPOSE:      To return if a stack is full or not (returns true or false)
//PARAMS:       None
//ALGORITHM:    if top is at 1 below MAX, return true as no more can be
//              can be entered, else, return false
bool Stack::isFull() {
    if (top == MAX-1 )
        return true;
    else
        return false;
}

//PURPOSE:      To return the top element and move the pointer to the next
//PARAMS:       None
//ALGORITHM:    if stack is empty, then go call error and exit, else return
//              the top element and decrement top to point to the next element
el_t Stack::pop() {
    if (isEmpty())
    {
        stackError("ERROR: STACK OVERFLOW");
        return 0;
    }
    else
        return el[top--];
}

//PURPOSE:      To return the top element without popping or moving the pointer
//PARAMS:       None
//ALGORITHM:    If stack is empty, then call error and exit, else return the
//              top element
el_t Stack::topElem() {
    if (isEmpty())
    {
        stackError("ERROR: STACK IS EMPTY");
        return 0;
    }
    else
        return el[top];
}

//PURPOSE:      To push a passed element to the stack
//PARAMS:       New element elem of type el_t
//ALGORITHM:    if not full, increment top and place elem in there
void Stack::push(el_t elem) {
    if (isFull())
        stackError("ERROR: STACK OVERFLOW");
    else
        el[++top] = elem;
}

//PURPOSE:      To clear the entire stack
//PARAMS:       None
//ALGORITHM:    while stack is not empty, pop until it is.
void Stack::clearIt()
{
    while (!isEmpty())
    {
        pop();
    }
}

//PURPOSE:      To display all the elements in the stack without moving the pointer
//PARAMS:       None
//ALGORITHM:    starting from top, display the element followed by a newline char
//              until 0
void Stack::displayAll()
{
    for (int i = top; i >= 0; i--)
    {
        cout << el[i] << endl;
    }
}