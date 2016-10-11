// Stefan Retief
// CS211 LAB 11-2, HW7
// LL Class - Header File
// ======================================================

#ifndef LL_hpp
#define LL_hpp
#include <string>
using namespace std;

typedef string el_t;

struct node {                   // stuct that holds the element and a pointer to the next element
    el_t elem;
    node* next;
};

class LL {
private:
    node* front;                // address to the front element
    node* rear;                 // address to the last element
    int count;                  // how many elements do we have right now?
    void queueError(string);    // This displays an error messages passed to it and does exit(1);
public:
    LL();                   // constructor LL();
    ~LL();                  // deconstructor LL();
    
    //HOW TO CALL:  Call onto an existing LL ([LL].addRear(elem))
    //              with the element you want to add to the LL
    //PURPOSE:      to add a pointer with an element to te list
    void addRear(el_t elem);
    
    //HOW TO CALL:  Call onto an existing LL ([LL.deleteFront())
    //PURPOSE:      Deletes the rear pointer and returns the element
    el_t deleteFront();
    
    //HOW TO CALL:  Call onto an existing LL ([LL.deleteRear())
    //PURPOSE:      Deletes the front pointer and returns the element
    el_t deleteRear();
    
    //HOW TO CALL:  Call onto an existing queue ([LLName].isEmpty())
    //PURPOSE:      Checks if the queue has no (0) elements and returns
    //              true or false accordingly
    bool isEmpty();
    
    //HOW TO CALL:  Call onto an existing queue ([LLName].displayAll())
    //PURPOSE:      Displays all elements in the LL
    void displayAll();
    
    //HOW TO CALL:  Call onto an existing queue with the element you want
    //              to add as a parameter ([LLName].addFront(elem))
    //PURPOSE:      To add an element to the front of the LL
    void addFront(el_t);
    
    //HOW TO CALL:  Call onto an existing queue with the element you want
    //              to delete as a parameter ([LLName].deleteNode(elem))
    //PURPOSE:      To delete the first node containing the element
    void deleteNode(el_t);
    
    //HOW TO CALL:  Call onto an existing queue with the element you want
    //              to delete as a parameter ([LLName].deleteNodes(elem))
    //PURPOSE:      To delete the all the nodes containing the element
    void deleteNodes(el_t);
    
    //HOW TO CALL: Call onto an existing queue with the element you want
    //PURPOSE: To add elements in ascending order (low to high)
    void addInOrderAscend(el_t e);
    
    //HOW TO CALL: Call onto an existing queue with the element you want
    //PURPOSE: To add elements in descending order (high to low)
    void addInOrderDescend(el_t e);
    
    //HOW TO CALL: Call onto an existing queue with the element you want
    //PURPOSE: returns true or false if the element if found or not
    bool search(el_t e);

};



#endif /* LL_hpp */
