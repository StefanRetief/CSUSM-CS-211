//// Stefan Retief
//// CS211 Lab 11-2, HW#
//// LAB11-2 Client - Client File
//// ======================================================
//
//#include <iostream>
//#include "LL.hpp"
//using namespace std;
//
//int main() {
//    LL test;
//
//    cout << "ASCEND TEST:" << endl;
//    
//    test.addInOrderAscend(5);
//    
//    test.displayAll();
//    
//    test.addInOrderAscend(1);
//    
//    test.displayAll();
//    
//    test.addInOrderAscend(3);
//    
//    test.displayAll();
//    
//    test.addInOrderAscend(0);
//    
//    test.displayAll();
//    
//    test.addInOrderAscend(7);
//    
//    test.displayAll();
//    
//    test.addInOrderAscend(7);
//    
//    test.displayAll();
//    
//    test.addInOrderAscend(5);
//    
//    test.displayAll();
//    
//    test.addInOrderAscend(0);
//    
//    test.displayAll();
//    
//    while (!test.isEmpty()) {
//        test.deleteRear();
//    }
//    
//    cout << "DESCEND TEST:" << endl;
//    
//    test.addInOrderDescend(5);
//    
//    test.displayAll();
//    
//    test.addInOrderDescend(1);
//    
//    test.displayAll();
//    
//    test.addInOrderDescend(3);
//    
//    test.displayAll();
//    
//    test.addInOrderDescend(0);
//    
//    test.displayAll();
//    
//    test.addInOrderDescend(7);
//    
//    test.displayAll();
//    
//    test.addInOrderDescend(7);
//    
//    test.displayAll();
//    
//    test.addInOrderDescend(5);
//    
//    test.displayAll();
//    
//    test.addInOrderDescend(0);
//    
//    test.displayAll();
//    
//    while (!test.isEmpty()) {
//        test.deleteRear();
//    }
//    
//    cout << "SEARCH TEST:" << endl;
//    
//    test.addRear(3);
//    test.addRear(9);
//    test.addRear(2);
//    test.addRear(1);
//    test.addRear(9);
//    test.addRear(11);
//    
//    int i = 3;
//    
//    if (test.search(i)) {
//        cout << "FOUND: " << i << endl;
//    }
//    else {
//        cout << "NOT FOUND: " << i << endl;
//    }
//    
//    i = 11;
//    
//    if (test.search(i)) {
//        cout << "FOUND: " << i << endl;
//    }
//    else {
//        cout << "NOT FOUND: " << i << endl;
//    }
//    
//    i = 2;
//    
//    if (test.search(i)) {
//        cout << "FOUND: " << i << endl;
//    }
//    else {
//        cout << "NOT FOUND: " << i << endl;
//    }
//    
//    i = 9;
//    
//    if (test.search(i)) {
//        cout << "FOUND: " << i << endl;
//    }
//    else {
//        cout << "NOT FOUND: " << i << endl;
//    }
//    
//    i = 100;
//    
//    if (test.search(i)) {
//        cout << "FOUND: " << i << endl;
//    }
//    else {
//        cout << "NOT FOUND: " << i << endl;
//    }
//    
//}
