// Stefan Retief
// CS211 LAB 11-1, HW#
// LAB11-1 Client - Client File
// ======================================================

#include "LL.hpp"
#include <iostream>
using namespace std;

int main () {
    LL test;
    
    test.addRear(3);
    test.addRear(9);
    test.addRear(2);
    test.addRear(1);
    test.addRear(9);
    test.addRear(11);
    
    test.displayAll();
    
    test.deleteNodes(9);
    
    test.displayAll();
    
    //test.deleteNode(9);
    
    test.displayAll();
    
    test.deleteNodes(5);
    
    test.displayAll();
    
    test.deleteNodes(3);
    
    test.displayAll();
    
    test.deleteNode(11);
    
    test.displayAll();
    
    test.deleteNode(1);
    
    test.displayAll();
    
    test.deleteNode(2);
    
    test.displayAll();
    
    test.deleteNode(5);
    return 0;
}