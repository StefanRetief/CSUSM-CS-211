// Stefan Retief
// CS211 LQueue, HW5
// LQueue Class - Class File
// ======================================================

#include <iostream>
#include "LQueue.hpp"

//PURPOSE:      Constructor which initilizes front, rear, and count
LQueue::LQueue() {
    front = NULL;
    rear = NULL;
    count = 0;
}

//PURPOSE:      When the program hits and endbrace '}', delete the LQueue
//ALGORITHM:    While the LQueue isn't empty, delete front
LQueue::~LQueue() {
    while (!isEmpty()) {
        deleteFront();
    }
}

//PURPOSE:      To add en element to the rear of the lqueue
//PARAMS:       the element to add the the lqueue
//ALGORITHM:    if empty, make a new node and set the element. front->next = NULL
//              else, make a new node on rear->next, set the element and set rear
//              ->next to NULL
void LQueue::addRear(el_t value) {
    if (isEmpty()) {
        front = new node;
        rear = front;
        front->elem = value;
        front->next = NULL;
        count++;
    }
    else {
        rear->next = new node;
        rear = rear->next;
        rear->elem = value;
        rear->next = NULL;
        count++;
    }
}

//PURPOSE:      To delete the front pointer and display the element
//PARAMS:       None
//ALGORITHM:    while the lqueue isn't empty, set a temp element to front->next
//              and deletethe front. Set the temp to the front and return the element
el_t LQueue::deleteFront() {
    if (isEmpty()) {
        queueError("UNABLE TO REMOVE FRONT. QUEUE UNDERFLOW.");
        return 0;
    }
    else {
        node* second = front->next;
        int sec = front->elem;
        delete front;
        front = second;
        count--;
        return sec;
    }
    
}

//PURPOSE:      To return if a queue is empty or not (returns true or false)
//PARAMS:       None
//ALGORITHM:    if count is at the initilized state of 0, return true, else
//              return false
bool LQueue::isEmpty() {
    if (count == 0)
        return true;
    else
        return false;
}

//PURPOSE:      To display all the elements in the lqueue
//PARAMS:       None
//ALGORITHM:    While the lqueue isn't empty, put a temp pointer to the front
//              and while the temp->next = NULL, keep displaying and moving
//              the element
void LQueue::displayAll() {
    if (isEmpty()) {
        cout << "[EMPTY]" << endl;
    }
    else {
        node* p = front;
        while (p != NULL) {
            //cout << "[";
            cout << p->elem;
            p = p->next;
            //cout << "]" << " ";
        }
        //cout << endl;
    }
}

//PURPOSE:      To display the lqueue in reverse
//PARAMS:       None
//ALGORITHM:    calls the private function printAllReverse(node* p) with the param
//              'front'
void LQueue::printAllReverse () {
    printAllReverse (front);
}

//PURPOSE:      (Private) To display the lqueue in reverse recursively
//PARAMS:       pointer to the first node
//ALGORITHM:    while the pointer isn't NULL, continue to the next pointer
//              if pointer = NULL, return and display element
void LQueue::printAllReverse (node* p) {
    if(p == NULL)
        return;
    else {
        printAllReverse(p->next);
        cout << p->elem;
    }
}

//PURPOSE:      (Private) To handle unexpected errors encountered by other
//              methods
//PARAMS:       String message to be displayed
//ALGORITHM:    'cout' the message and exit program with error code 1
void LQueue::queueError(string msg) {
    cout << msg << endl;
    exit(1);
}