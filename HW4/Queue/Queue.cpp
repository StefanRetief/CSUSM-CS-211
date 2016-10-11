// Stefan Retief
// CS211 Queue, HW4
// Queue Class - Class File
// ======================================================

#include "Queue.hpp"
#include <iostream>

//PURPOSE:      Constructor whitch initilizes front, rear, and count
Queue::Queue() {
    front = 0;
    rear = -1;
    count = 0;
}

//PURPOSE:      (Private) To handle unexpected errors encountered by other
//              methods
//PARAMS:       String message to be displayed
//ALGORITHM:    'cout' the message and exit program with error code 1

void Queue::queueError(string str) {
    cout << str;
    exit(1);
}

//PURPOSE:      To return if a queue is empty or not (returns true or false)
//PARAMS:       None
//ALGORITHM:    if count is at the initilized state of 0, return true, else
//              return false
bool Queue::isEmpty() {
    if (count == 0) {
        return true;
    }
    else {
        return false;
    }
}

//PURPOSE:      To return if a stack is full or not (returns true or false)
//PARAMS:       None
//ALGORITHM:    if count is at QUEUE_SIZE, return true as no more can be
//              can be entered, else, return false
bool Queue::isFull() {
    if (count == QUEUE_SIZE) {
        return true;
    }
    else {
        return false;
    }
}

//PURPOSE:      To return the top element and move the pointer to the next
//PARAMS:       None
//ALGORITHM:    if stack is empty, then go call error and exit, else return
//              the front element and find the next element by moduling front+1
el_t Queue::remove() {
    if (isEmpty()) {
        queueError("QUEUE UNDERFLOW");
        return static_cast<el_t>(NULL);
    }
    else {
        el_t e = el[front];
        front = (front+1) % QUEUE_SIZE;
        count--;
        return e;
    }
}

//PURPOSE:      To add a passed element to the queue
//PARAMS:       New element elem of type el_t
//ALGORITHM:    if not full, increment find new rear by moduling front+1
//              by QUEUE_SIZE and add the elem to that element
void Queue::add(el_t elem) {
    if (isFull()) {
        queueError("QUEUE OVERFLOW");
    }
    else {
        rear = (rear+1) % QUEUE_SIZE;
        el[rear] = elem;
        count++;
    }
}

//PURPOSE:      To return the front element without removing or moving the pointer
//PARAMS:       None
//ALGORITHM:    If queue is empty, then call error and exit, else return the
//              front element
el_t Queue::getFront() {
    if (!isEmpty()) {
        return el[front];
    }
    else {
        queueError("QUEUE IS EMPTY.");
        return static_cast<el_t>(NULL);
    }
}

//PURPOSE:      To move the front element to the back
//PARAMS:       None
//ALGORITHM:    First, removes the front element, which also returns it. Then
//              adds it to the back of the queue with add()
void Queue::goToBack() {
        add(remove());
}

//PURPOSE:      To return the size of the queue by returning count
//PARAMS:       None
//ALGORITHM:    return the count variable which is incremented and decremented with
//              the amount of elements in the queue
int Queue::getSize() {
    return count;
}

//PURPOSE:      To display all the elements in the queue without moving the pointer
//PARAMS:       None
//ALGORITHM:    Put front in a temporary variable, then using a for loop, display
//              as many times as there re elements in the queue. Then module temp
//              by the queue size to find the next element, whether in front or back
void Queue::displayAll() {
    
    if (!isEmpty()) {
        int tempf = front;
        int f;
        
        cout << endl;
        for (int i = 0; i < count; i++) {
            f = tempf % QUEUE_SIZE;
            cout << "Element " << i+1 << ": [" << el[f] << "]"<< endl;
            tempf++;
        }
        cout << endl;
    }
    else {
        queueError("QUEUE IS EMPTY. UNABLE TO DISPLAY ALL");
    }
}