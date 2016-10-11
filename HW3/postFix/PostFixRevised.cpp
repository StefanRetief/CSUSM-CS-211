// Stefan Retief
// CS211 postFix, HW3
// PostFixRevised Client - Client File
// ======================================================

#include <iostream>
#include <string>
#include "stack.hpp"

int charToInt(string);
bool isOperand(string);
bool isOperator(char);
int doMath(int, char, int);

int main()
{
    Stack numbers;
    string expre;
    bool error = false;
    int opr1 = 0, opr2 = 0;
    
    cout << "Enter the expression you would like to evaluate: ";
    getline(cin, expre);
    
    expre += '\n';
    
    int temp = 0;
    string op;
    
    for (int i = 0; i < expre.length() && !error; i++) {
        if (expre[i] == ' ' || expre[i] == '\n') {
            op = expre.substr(temp, i - temp);
            temp = i+1;
            if (isOperand(op) && !numbers.isFull()) {
                if (i == expre.length() - 1 && !numbers.isEmpty() && !error) {
                    error = true;
                    cout << "Incomplete expression was found." << endl;
                }
                numbers.push(charToInt(op));
            }
            else if (numbers.isFull()) {
                error = true;
                cout << "Stack is full. The operand cannot be pushed." << endl;
            }
            else if (isOperator(op[0])) {
                if (!numbers.isEmpty()) {
                    opr2 = numbers.topElem();
                    numbers.pop();
                }
                else if (!error) {
                    error = true;
                    opr2 = 0;
                    cout << "Stack is empty. There are not enough operands." << endl;
                }
                if (!numbers.isEmpty()) {
                    opr1 = numbers.topElem();
                    numbers.pop();
                }
                else if (!error) {
                    error = true;
                    opr1 = 0;
                    cout << "Stack is empty. There are not enough operands." << endl;
                }
                if (i == expre.length() - 1 && !numbers.isEmpty() && !error) {
                    error = true;
                    cout << "Incomplete expression was found." << endl;
                }
                if (!error) {
                    numbers.push(doMath(opr1, op[0], opr2));
                }
            }
            else if (!isOperator(op[0]) || !isOperand(op)) {
                error = true;
                cout << "Invalid expression." << endl;
            }
        }
    }
    if (!error)
        cout << " = " << numbers.topElem() << endl;
    
    return 0;
}

bool isOperand(string ch) //return true if ch is an operand (digit) ch >= ‘0’ && ch <= ‘9’
{
    bool valid = true;
    for (int i = 0; i < ch.length() && valid; i++) {
        if (ch[i] >= '0' && ch[i] <= '9')
            valid = true;
        else
            valid = false;
    }
    return valid;
}

int charToInt(string ch) //convert a character to integer (if an item is a digit)
{
    int total = 0;
    for (int i = 0; i < ch.length(); i++) {
        int tens = 1;
        int j = 0;
        int newNum;
        while (j < ch.length() - (i+1)) {
            tens = tens * 10;
            j++;
        }
        newNum = ch[i] - 48;
        total += newNum * tens;
    }
    return total;
    return stoi(ch);
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
}*/