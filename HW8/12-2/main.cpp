////
////  main.cpp
////  12-2
////
////  Created by Stefan Retief on April 20, 2016.
////  Copyright © 2016 Stefan Retief. All rights reserved.
////
//
//#include <iostream>
//#include "DLL.hpp"
//
//int main() {
//    DLL test;
//
//    cout << "ADD IN ORDER Descend [4,7,3,9,2,4,6,8,4,9,2,6]" << endl;
//    test.addInOrderDescend(4);
//    test.addInOrderDescend(7);
//    test.addInOrderDescend(3);
//    test.addInOrderDescend(9);
//    test.addInOrderDescend(2);
//    test.addInOrderDescend(4);
//    test.addInOrderDescend(6);
//    test.addInOrderDescend(8);
//    test.addInOrderDescend(4);
//    test.addInOrderDescend(9);
//    test.addInOrderDescend(2);
//    test.addInOrderDescend(6);
//    cout << "DISPLAY ALL: ";
//    test.displayAll();
//    cout << "DISPLAY ALL REVERSE: ";
//    test.displayAllReverse();
//    cout << endl;
//    
//    cout << "DELETE NODES [9]" << endl;
//    test.deleteNodes(9);
//    cout << "DISPLAY ALL: ";
//    test.displayAll();
//    cout << "DISPLAY ALL REVERSE: ";
//    test.displayAllReverse();
//    cout << endl;
//    
//    cout << "DELETE NODE [3] [7] [8]" << endl;
//    test.deleteNode(3);
//    test.deleteNode(7);
//    test.deleteNode(8);
//    cout << "DISPLAY ALL: ";
//    test.displayAll();
//    cout << "DISPLAY ALL REVERSE: ";
//    test.displayAllReverse();
//    cout << endl;
//    
//    cout << "DELETE NODES [4]" << endl;
//    test.deleteNodes(4);
//    cout << "DISPLAY ALL: ";
//    test.displayAll();
//    cout << "DISPLAY ALL REVERSE: ";
//    test.displayAllReverse();
//    cout << endl;
//    
//    cout << "DELETE NODES [2]" << endl;
//    test.deleteNodes(2);
//    cout << "DISPLAY ALL: ";
//    test.displayAll();
//    cout << "DISPLAY ALL REVERSE: ";
//    test.displayAllReverse();
//    cout << endl;
//    
//    cout << "DELETE NODE [6] [6]" << endl;
//    test.deleteNode(6);
//    test.deleteNode(6);
//    cout << "DISPLAY ALL: ";
//    test.displayAll();
//    cout << "DISPLAY ALL REVERSE: ";
//    test.displayAllReverse();
//    cout << endl;
//    
//    cout << "ADD FRONT [7] [5] [1] [4] [9] [2]" << endl;
//    test.addFront(1);
//    test.addFront(5);
//    test.addFront(7);
//    test.addRear(4);
//    test.addRear(9);
//    test.addRear(2);
//    cout << "DISPLAY ALL: ";
//    test.displayAll();
//    cout << "DISPLAY ALL REVERSE: ";
//    test.displayAllReverse();
//    cout << endl;
//    
//    cout << "DELETE FRONT [7] [5]" << endl;
//    test.deleteFront();
//    test.deleteFront();
//    cout << "DISPLAY ALL: ";
//    test.displayAll();
//    cout << "DISPLAY ALL REVERSE: ";
//    test.displayAllReverse();
//    cout << endl;
//    
//    cout << "SEARCH [7] [9]" << endl;
//    if (test.search(7))
//        cout << "FOUND" << endl;
//    if (test.search(9))
//        cout << "FOUND" << endl;
//    
//    cout << "DELETE REAR [2] [9]" << endl;
//    test.deleteRear();
//    test.deleteRear();
//    cout << "DISPLAY ALL: ";
//    test.displayAll();
//    cout << "DISPLAY ALL REVERSE: ";
//    test.displayAllReverse();
//    cout << endl;
//    
//    cout << "DELETE FRONT & REAR [1] [4]" << endl;
//    test.deleteFront();
//    test.deleteRear();
//    cout << "DISPLAY ALL: ";
//    test.displayAll();
//    cout << "DISPLAY ALL REVERSE: ";
//    test.displayAllReverse();
//    cout << endl;
//}
