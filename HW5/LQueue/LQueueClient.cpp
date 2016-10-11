// Stefan Retief
// CS211 LQueue, HW5
// LQueueClient Client - Client File
// ======================================================

#include <iostream>
#include "LQueue.hpp"

int main() {
    LQueue q;
    
    if (q.isEmpty())
        cout << "Linked list is empty" << endl;
    else
        cout << "Linked list is not empty" << endl;
    
    q.displayAll();
    
    q.addRear(1);
    
    q.displayAll();
    
    q.addRear(2);
    q.addRear(3);
    q.addRear(4);
    
    q.displayAll();
    
    cout << "ELEMENT REMOVED: " << q.deleteFront() << endl;
    cout << "ELEMENT REMOVED: " << q.deleteFront() << endl;
    cout << "ELEMENT REMOVED: " << q.deleteFront() << endl;
    
    q.displayAll();
    
    if (q.isEmpty())
        cout << "Linked list is empty" << endl;
    else
        cout << "Linked list is not empty" << endl;
    
    cout << "ELEMENT REMOVED: " << q.deleteFront() << endl;
    
    if (q.isEmpty())
        cout << "Linked list is empty" << endl;
    else
        cout << "Linked list is not empty" << endl;
    
    q.displayAll();
    
    return 0;
    
}
