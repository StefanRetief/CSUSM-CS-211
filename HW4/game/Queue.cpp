// Stefan Retief
// CS211 Queue, HW4
// Queue Class - Class File
// ======================================================

#include "Queue.hpp"
#include <iostream>

Queue::Queue() {
    front = 0;
    rear = -1;
    count = 0;
}

void Queue::queueError(string str) {
    cout << str;
    exit(1);
}

bool Queue::isEmpty() {
    if (count == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool Queue::isFull() {
    if (count == QUEUE_SIZE) {
        return true;
    }
    else {
        return false;
    }
}

el_t Queue::remove() {
    if (isEmpty()) {
        queueError("QUEUE UNDERFLOW");
    }
    else {
        el_t e = el[front];
        front = (front+1) % QUEUE_SIZE;
        count--;
        return e;
    }
}

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

el_t Queue::getFront() {
    if (!isEmpty()) {
        return el[front];
    }
    else {
        queueError("QUEUE IS EMPTY. CANNOT GET FRONT ELEMENT");
    }
}


void Queue::goToBack() {
        add(remove());
}

int Queue::getSize() {
    return count;
}

/*void Queue::displayAll() {
    
    if (!isEmpty()) {
    int tempf = front;
    int f;
    
    cout << endl;
    for (int i = 0; i < count; i++) {
        f = tempf % 5;
        cout << "Element " << i+1 << ": [" << el[f] << "]"<< endl;
        tempf++;
    }
    cout << endl;
    }
    else {
        queueError("QUEUE IS EMPTY. UNABLE TO DISPLAY ALL");
    }
}*/
