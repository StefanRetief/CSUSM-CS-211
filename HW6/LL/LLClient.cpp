// Stefan Retief
// CS211 LL, HW5
// LL Client - Client File
// ======================================================

#include <iostream>
#include "LL.hpp"

int main() {
    LL test;
    
    //Add 1,2,3 to the front and 4,5 to the rear
    cout << "BEGIN TEST: " << endl;
    test.addFront(1);
    test.addFront(2);
    test.addFront(3);
    test.addRear(4);
    test.addRear(5);
    cout << "DISPLAY ALL: ";    //display the LL
    test.displayAll();
    cout << endl;
    
    //test removing elements
    cout << "REMOVE FRONT AND REAR: " << endl;
    cout << "REMOVE " << test.deleteFront() << endl;
    cout << "REMOVE " << test.deleteRear() << endl;
    cout << "DISPLAY ALL: ";    //display the LL
    test.displayAll();
    cout << endl;
    
    //test removing again
    cout << "REMOVE FRONT AND REAR: " << endl;
    cout << "REMOVE " << test.deleteFront() << endl;
    cout << "REMOVE " << test.deleteRear() << endl;
    cout << "DISPLAY ALL: ";    //display the LL
    test.displayAll();
    cout << endl;
    
    //test remove one more time
    cout << "REMOVE FRONT: " << endl;
    cout << "REMOVE " << test.deleteFront() << endl;
    cout << "DISPLAY ALL: ";    //display the LL
    test.displayAll();
    cout << endl;
    
    //add 10 and 11 to rear and front
    cout << "ADD REAR(10) AND FRONT(11): " << endl;
    test.addRear(10);
    test.addFront(11);
    cout << "DISPLAY ALL: ";    //display the LL
    test.displayAll();
    cout << endl;
    
    //remove rear twice to make empty
    cout << "REMOVE REAR TWICE:  " << endl;
    cout << "REMOVE " << test.deleteRear() << endl;
    cout << "REMOVE " << test.deleteRear() << endl;
    cout << "DISPLAY ALL: ";    //display [EMPTY]
    test.displayAll();
    
    return 0;
}
