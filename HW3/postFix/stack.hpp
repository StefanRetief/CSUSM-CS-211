// Stefan Retief
// CS211 postFix, HW3
// PostFixRevised Class - Header File
// ======================================================

#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>
#include <string>
using namespace std;

const int MAX = 5;

typedef int el_t; //define el_t to be int for now

class Stack
{
private:
    el_t el[MAX];               //An array of el_t's
    int top;                    //Index of the top of the stack
    void stackError(string);    //Utility function for error handling
public:
    Stack();                    //constructor
    
    //HOW TO CALL:  Call onto an existing stack ([stackName].isEmpty())
    //PURPOSE:      Checks if the stack has no (0) elements and returns
    //              true or false accordingly
    bool isEmpty();
    
    //HOW TO CALL:  Call onto an existing stack ([stackName].isFull())
    //PURPOSE:      Checks if the stack has Max (5) elements and
    //              returns true or false accordingly
    bool isFull();
    
    //HOW TO CALL:  Call onto existing stack ([stackName].pop())
    //PURPOSE:      Check if stack is empty, and goes to error,
    //              else, returns the element and moves the pointer
    //              down to the next element
    el_t pop();
    
    //HOW TO CALL:  Call onto an existing stack ([stackName].topElem())
    //PURPOSE:      To return the top element with moving the pointer
    el_t topElem();
    
    //HOW TO CALL:  Pass an element to be pushed to the top of the stack
    //PURPOSE:      If stack not full, enters an element at the top else
    //              calls an emergency exit routine
    void push(el_t);
    
    //HOW TO CALL:  Call onto an existing stack ([stackName].clearIt())
    //PURPOSE:      if the stack is not empty, will pop() all elements
    //              until it is
    void clearIt();
    
    //HOW TO CALL:  Call onto an existing stack ([stackName].displayAll())
    //PURPOSE:      Displays all elements in the stack
    void displayAll();
};

#endif /* stack_hpp */
