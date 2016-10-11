// Stefan Retief
// CS211 LQueue, HW5
// LQueueAdd - Client File
// ======================================================

#include <iostream>
#include "LQueue.hpp"
using namespace std;

LQueue createReserseLL(string);
LQueue addLLs(LQueue&, LQueue&);

int main() {
    string n1, n2;
    
    //ask user to enter two numbers
    cout << "Enter a number: ";
    cin >> n1;
    
    cout << "Enter a second number: ";
    cin >> n2;
    
    //create the lqueue
    LQueue reReverse1 = createReserseLL(n1);
    LQueue reReverse2 = createReserseLL(n2);
    
    //print the equation in reverse
    reReverse1.displayAll();
    cout << " + ";
    reReverse2.displayAll();
    cout << " = ";
    LQueue reSum = addLLs(reReverse1, reReverse2);
    reSum.displayAll();
    cout << endl;
    
    //create the lqueue by sending the numbers to the function CreateReverseLL
    LQueue reverse1 = createReserseLL(n1);
    LQueue reverse2 = createReserseLL(n2);
    
    //print the equation in the correct way
    reverse1.printAllReverse();
    cout << " + ";
    reverse2.printAllReverse();
    cout << " = ";
    LQueue sum = addLLs(reverse1, reverse2);
    sum.printAllReverse();
    cout << endl;
    
    return 0;
}

//create the lqueues from strings
LQueue createReserseLL(string s) {
    //make a char variable to add to th queue
    char newN;
    
    //make a new queue that will be returnd
    LQueue q;
    
    //fill the queue from the string length
    for (int i = (s.length()-1); i >= 0; i--) {
        newN = s[i];
        
        //convert the char to int
        q.addRear(atoi(&newN));
    }
    return q;
}

LQueue addLLs(LQueue &n1, LQueue &n2) {
    //make 3 operands
    int op1;
    int op2;
    
    //op3 is the carryover
    int op3 = 0;
    
    //create the lqueue that will be returned
    LQueue lSum;
    
    //make sure that neither of the queues are empty or that the carryover is 0
    while (!n1.isEmpty() || !n2.isEmpty() || op3 != 0) {
        
        //delete front as long as it's not empty
        if (!n1.isEmpty())
           op1 = n1.deleteFront();
        else    //else make it 0
            op1 = 0;
        //delete front as long as it's not empty
        if (!n2.isEmpty())
            op2 = n2.deleteFront();
        else    //else make it 0
            op2 = 0;
        
        //sum is the 3 operands added together
        int sum = op1 + op2 + op3;
        
        //reset op3 to 0
        op3 = 0;
        
        //if sum is greater than 9, carry the one
        if (sum > 9) {
            sum -= 10;
            op3 = 1;
        }
        
        //add the sums to the lqueue
        lSum.addRear(sum);
    }
    
    return lSum;
}