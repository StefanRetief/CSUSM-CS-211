// Stefan Retief
// CS211 stack Lab, HW3
// Stack Client - Client File
// ======================================================

#include <iostream>
#include "stack.hpp"

int main()
{
    Stack myStack;
    if (myStack.isEmpty())
    {
        cout << "The stack is empty" << endl << endl;
    }
    
    myStack.push("Mike");
    myStack.push("Kathy");
    
    cout << myStack.topElem() << " is at the top." << endl;
    
    myStack.push("Dave");
    myStack.push("Alice");
    myStack.push("Tom");
    
    if (myStack.isFull())
    {
        cout << "\nThe stack is full" << endl << endl;
    }
    
    myStack.displayAll();
    
    if (myStack.isFull())
        cout << "\nThe stack is full" << endl << endl;
    else
        myStack.push("Meg");
    
    myStack.pop();
    
    cout << myStack.topElem() << " is at the top." << endl << endl;
    
    myStack.clearIt();
    
    if (myStack.isEmpty())
    {
        cout << "The stack is empty" << endl;
    }
    
    
    return 0;
}
