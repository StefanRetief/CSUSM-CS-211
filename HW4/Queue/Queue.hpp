// Stefan Retief
// CS211 Queue, HW4
// Queue Class - Header File
// ======================================================

#ifndef Queue_hpp
#define Queue_hpp

#include <string>
using namespace std;

typedef char el_t; // el_t is an alias for char
const int QUEUE_SIZE = 5; // this is the max number of elements the queue can have

class Queue {
private:
    // Data members are:
    el_t el[QUEUE_SIZE];        // an array called el
    int count;                  // how many elements do we have right now?
    int front;                  // where the front element of the queue is.
    int rear;                   // where the rear element of the queue is.
    void queueError(string);    // This displays an error messages passed to it and does exit(1);
public:
    Queue();                    // constructor Queue();
    
    //HOW TO CALL:  Call onto an existing queue ([queueName].isEmpty())
    //PURPOSE:      Checks if the queue has no (0) elements and returns
    //              true or false accordingly
    bool isEmpty();
    
    //HOW TO CALL:  Call onto an existing queue ([queuekName].isFull())
    //PURPOSE:      Checks if the queue has Max (5) elements and
    //              returns true or false accordingly
    bool isFull();
    
    //HOW TO CALL:  Call onto existing queue ([queueName].pop())
    //PURPOSE:      Check if stack is empty, and goes to error,
    //              else, returns the element and moves the pointer
    //              down to the next element
    el_t remove();
    
    //HOW TO CALL:  Pass an element to be added to the rear of the stack
    //PURPOSE:      If stack not full, enters an element at the rear else
    //              calls an emergency exit routine
    void add(el_t);
    
    //HOW TO CALL:  Call onto an existing queue ([queueName].topElem())
    //PURPOSE:      To return the front element with moving the pointer
    el_t getFront();
    
    //HOW TO CALL:  Call onto existing queue ([queueName].goToBack())
    //PURPOSE:      To remove the front element of the queue and add
    //              it to the back of the queue
    void goToBack();
    
    //HOW TO CALL:  Call onto existing queue ([queueName].getSize())
    //PURPOSE:      To get the size of the current queue. Returns count
    int getSize();
    
    //HOW TO CALL:  Call onto an existing queue ([queueName].displayAll())
    //PURPOSE:      Displays all elements in the queue
    void displayAll();          // display everything in the queue from front to rear enclosed in []
};
#endif /* Queue_hpp */
