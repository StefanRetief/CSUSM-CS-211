// Stefan Retief
// CS211 palindrome, HW6
// palindrome Client - Client File
// ======================================================

#include <iostream>
#include "LL_T.hpp"

void createLL(string, LL<char>&);
bool isPalindrome(LL<char>&);

int main() {
    string s;               //initilize string and a LL
    LL<char> palindrome;
    
    cout << "Enter a string: ";     //ask for a string
    getline(cin, s);                //getline to get spaces
    
    if (s.length() >= 1)            //make sure there is atleast one char
        createLL(s, palindrome);    //store string in LL with func
    else                            //else, string isn't long enough
        cout << "ERROR: No string entered." << endl;
    
    if (isPalindrome(palindrome))   //check that it's a palindrome
        cout << s << " IS a palindrome." << endl;   //result
    else
        cout << s << " IS NOT a palindrome." << endl;   //result
    
    
    return 0;
}

void createLL(string s, LL<char>& str) {  //stores the string into a LL
    for (int i = 0; i < s.length(); i++) {  //adding chars to LL
        if (isalpha(s[i]))                  //add only alpha chars
            str.addRear(tolower(s[i]));
    }
}

bool isPalindrome(LL<char>& palindrome) { //check is LL is palindrome
    bool isPal = false;
    char front;
    char rear;
    
    while(!palindrome.isEmpty()) {  //delete front to get element
        front = palindrome.deleteFront();
        
        if (palindrome.isEmpty())   //this accounts for odd numbered words
            return true;
        else
            rear = palindrome.deleteRear(); //else delete from the back
        
        if (front == rear)  //compare chars
            isPal = true;
        else
            return false;   //if a char does not match, break
    }
    return isPal;
}

