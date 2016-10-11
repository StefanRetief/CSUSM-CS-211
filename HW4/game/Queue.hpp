// Stefan Retief
// CS211 Queue, HW4
// Queue Class - Header File
// ======================================================

#ifndef Queue_hpp
#define Queue_hpp

#include <string>
using namespace std;

//create an enumuration type
enum op {ADD, SUB, MULT, DIVI};

//create a struct that will have an operand, a operator, another operand
struct expr
{
    int oprd1;
    op oprt;
    int oprd2;
};

typedef expr el_t; // el_t is an alias for char
const int QUEUE_SIZE = 10; // this is the max number of elements the queue can have

class Queue {
private:
    // Data members are:
    el_t el[QUEUE_SIZE];        // a character array called el
    int count;                  // how many elements do we have right now?
    int front;                  // where the front element of the queue is.
    int rear;                   // where the rear element of the queue is.
    void queueError(string);    // This displays an error messages passed to it and does exit(1);
public:
    Queue();                    // constructor Queue();
    bool isEmpty();             // returns true if queue is empty, otherwise false bool isEmpty();
    bool isFull();              // returns true if queue is full, otherwise false bool isFull();
    el_t remove();              // removes element to queue
    void add(el_t);             // adds element from queue
    el_t getFront();            // return the front element (but does not remove it)
    void goToBack();            // if queue has more than 1 element, moves the front one to the rear
    int getSize();              // returns the current size int getSize();
    void displayAll();          // display everything in the queue from front to rear enclosed in []
};

#endif /* Queue_hpp */
