// Stefan Retief
// CS211 Pointers, HW5
// Lab 7-2 - Pointers lab
// ======================================================

#include <iostream>
using namespace std;

int main() {
    //a. Declare 2 pointers P1 and P2 that will point to integer cells.
    int* p1;
    int* p2;
    
    //b. Make P1 point to a cell.
    p1 = new int;
    
    //c. Put 1 in it.
    *p1 = 1;
    
    //d. Display the cell content.
    cout << "1 " << *p1 << endl;
    
    //e. Make P2 point to a cell.
    p2 = new int;   //e
    
    //f. Put 2 in it.
    *p2 = 2;        //f
    
    //g. Display the cell content.
    cout << "2 " << *p2 << endl; //g
    
    //h. Now make P2 point to the same cell as P1.
    delete p2;  //h
    p2 = p1;    //h
    
    //i. Display the content of the cell using P2.
    cout << "3 " << *p2 << endl; //i
    
    //j. Now delete the cell.
    delete p2;  //j
    
    //k. Initialize P1.
    p1 = NULL;  //k
    
    //l. Make P2 point to a new cell.
    p2 = new int;   //l
    
    //m. Put 3 in it.
    *p2 = 3;    //m
    
    //n. Display the cell content
    cout << "4 " << *p2 << endl;    //n
    
    return 0;
}
