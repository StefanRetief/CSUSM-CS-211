// Stefan Retief
// CS211 fibonacci, HW3
// Fibonacci Client - Client File
// ======================================================

#include <iostream>
#include <time.h>
using namespace std;

int fib(int);
int recursiveFib(int);

int main() {
    clock_t start, end;
    int pos, sum;

    cout << "Enter a position: ";
    cin >> pos;
    start = clock();
    
    sum = fib(pos);
    
    end = clock();
    cout << "Elapsed time: " << (end - start) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;
    cout << "Fibonnaci number at position " << pos << " is " << sum << endl;
    
    start = clock();
    sum = recursiveFib(pos);
    
    end = clock();
    cout << "Elapsed time: " << (end - start) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;
    cout << "Fibonnaci number at position " << pos << " is " << sum << endl;
    
}

int fib(int num) {
    int n1 = 0, n2 = 1;
    int fibnum = 0;
    
    if (num <= 1) {
        return num;
    }
    else
    for (int i = 0; i < num-1; i++) {
        fibnum = n1 + n2;
        n1 = n2;
        n2 = fibnum;
        
    }
    return fibnum;
}

int recursiveFib(int pos)
{
    if(pos <= 1) //position is 0 or 1 (base cases)
        return pos;
    else
        return recursiveFib(pos-2) + recursiveFib(pos-1);
}