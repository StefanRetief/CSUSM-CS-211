// Stefan Retief
// CS211 LQueue, HW5
// LQueue Class - Header File
// ======================================================

#ifndef LQueue_hpp
#define LQueue_hpp
#include <string>
using namespace std;

typedef int el_t;

struct node {                   // stuct that holds the element and a pointer to the next element
    el_t elem;
    node* next;
};

class LQueue {
private:
    node* front;                // address to the front element
    node* rear;                 // address to the last element
    int count;                  // how many elements do we have right now?
    void queueError(string);    // This displays an error messages passed to it and does exit(1);
public:
    LQueue();                   // constructor LQueue();
    ~LQueue();                  // deconstructor LQueue();
    
    //HOW TO CALL:  Call onto an existing lqueue ([lqueue].addRear(elem))
    //              with the element you want to add to the lqueue
    //PURPOSE:      to add a pointer with an element to te list
    void addRear(el_t elem);
    
    //HOW TO CALL:  Call onto an existing lqueue ([lqueue.deletefront())
    //PURPOSE:      Deletes the front pointer and returns the element
    el_t deleteFront();
    
    //HOW TO CALL:  Call onto an existing queue ([lqueueName].isEmpty())
    //PURPOSE:      Checks if the queue has no (0) elements and returns
    //              true or false accordingly
    bool isEmpty();
    
    //HOW TO CALL:  Call onto an existing queue ([lqueueName].displayAll())
    //PURPOSE:      Displays all elements in the lqueue
    void displayAll();
};



#endif /* LQueue_hpp */
