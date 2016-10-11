// Stefan Retief
// CS211 postFix, HW3
// PostFix Client - Client File
// ======================================================

#include <iostream>
#include <string>
#include "stack.hpp"

//Prototypes
int charToInt(char);
bool isOperand(char);
bool isOperator(char);
int doMath(int, char, int);

int main()
{
    Stack numbers;  //Create the stack
    string expre;   //The string for the input string
    bool error = false; //start off with no error
    int opr1 = 0, opr2 = 0;     //initilize two ints to save from the stack
    
    //user is prompted to enter the expression and saved in 'expre'
    cout << "Enter the expression you would like to evaluate: ";
    cin >> expre;
    
    //begin for loop. Must have no error and be between 0 and the string length
    for (int i = 0; i < expre.length() && !error; i++) {
        //Check if the first character of string is a number and then check if the stack is full.
        //also check if the we reach a number
        //If not full and is number, push.
        if (isOperand(expre[i]) && !numbers.isFull()) {
            if (i == expre.length()-1 && !numbers.isEmpty() && !error) {
                error = true;
                cout << "Incomplete expression was found." << endl;
            }
            else {
                numbers.push(charToInt(expre[i]));
            }
        }
        // else, error is true and present the error message. The loop will terminate
        else if (numbers.isFull()) {
            error = true;
            cout << "Stack is full. The operand cannot be pushed." << endl;
        }
        //else, we check if the character is an operator
        else if (isOperator(expre[i])) {
            //make sure the stack is not empty and put the top element in the int opr2, and pop the stack
            if (!numbers.isEmpty()) {
                opr2 = numbers.topElem();
                numbers.pop();
            }
            //else, if the stack is empty, present error and end the loop
            else if (!error) {
                error = true;
                opr2 = 0;
                cout << "Stack is empty. There are not enough operands." << endl;
            }
            //check again if the stack is empty, and put the next top element into the int opr1, and pop the stack
            if (!numbers.isEmpty()) {
                opr1 = numbers.topElem();
                numbers.pop();
            }
            //else, if the stack is empty, present error and end the loop
            else if (!error) {
                opr1 = 0;
                error = true;
                cout << "Stack is empty. There are not enough operands." << endl;
            }
            //Make sure we haven't reached the end of the string and there are still numbers left in the stack
            if (i == expre.length()-1 && !numbers.isEmpty() && !error) {
                error = true;
                cout << "Incomplete expression was found." << endl;
            }
            //finally, if no errors, do the math
            if (!error) {
                numbers.push(doMath(opr1, expre[i], opr2));
            }
        }
        //checks if the char is either an operator or operand
        else if (!isOperator(expre[i]) && !isOperand(expre[i])) {
            error = true;
            cout << "Invalid expression." << endl;
        }
    }
    //display the answer
    if (!error)
        cout << expre << " = " << numbers.topElem() << endl;
    
    return 0;
}

bool isOperand(char ch) //return true if ch is an operand (digit) ch >= ‘0’ && ch <= ‘9’
{
    return ch >= '0' && ch <= '9';
}

int charToInt(char ch) //convert a character to integer (if an item is a digit)
{
    //return ch - 48;
    return atoi(&ch);
}

bool isOperator(char ch) //return true if it is an operator (+, -, *, /)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int doMath(int opr1, char opt, int opr2) //returns the result of opr1 opt opr2
{
    switch(opt) {
        case '+' :
            return opr1 + opr2;
            break;
        case '-' :
            return opr1 - opr2;
            break;
        case '*' :
            return opr1 * opr2;
            break;
        case '/' :
            return opr1 / opr2;
            break;
        default:
            return 0;
            break;
    }
}