// Stefan Retief
// CS211 LAB 13-2, HW#
// LL_T Class - Header File
// ======================================================

#ifndef LL_E_T_hpp
#define LL_E_T_hpp

#include <string>
using namespace std;

template <class T>
struct node {                   // stuct that holds the element and a pointer to the next element
    T elem;
    node<T>* next;
};

template <class T>
class LL {
private:
    node<T>* front;                // address to the front element
    node<T>* rear;                 // address to the last element
    int count;                  // how many elements do we have right now?
    void printAllReverse(node<T>*);// Reverses the elements from a lqueue
public:
    LL();                   // constructor LL();
    ~LL();                  // deconstructor LL();
    
    //HOW TO CALL:  Call onto an existing LL ([LL].addRear(elem))
    //              with the element you want to add to the LL
    //PURPOSE:      to add a pointer with an element to te list
    void addRear(T elem);
    
    //HOW TO CALL:  Call onto an existing LL ([LL.deleteFront())
    //PURPOSE:      Deletes the rear pointer and returns the element
    T deleteFront();
    
    //HOW TO CALL:  Call onto an existing LL ([LL.deleteRear())
    //PURPOSE:      Deletes the front pointer and returns the element
    T deleteRear();
    
    //HOW TO CALL:  Call onto an existing queue ([LLName].isEmpty())
    //PURPOSE:      Checks if the queue has no (0) elements and returns
    //              true or false accordingly
    bool isEmpty();
    
    //HOW TO CALL:  Call onto an existing queue ([LLName].displayAll())
    //PURPOSE:      Displays all elements in the LL
    void displayAll();
    
    //HOW TO CALL:  Call onto an existing queue with the element you want
    //              to add as a parameter ([LLName].addFront(elem))
    //PURPOSE:      To add an element to the front of the LL
    void addFront(T);
    
    //HOW TO CALL:  Call onto an existing queue with the element you want
    //              to delete as a parameter ([LLName].deleteNode(elem))
    //PURPOSE:      To delete the first node containing the element
    void deleteNode(T);
    
    //HOW TO CALL:  Call onto an existing queue with the element you want
    //              to delete as a parameter ([LLName].deleteNodes(elem))
    //PURPOSE:      To delete the all the nodes containing the element
    void deleteNodes(T);
    
    //HOW TO CALL: Call onto an existing queue with the element you want
    //PURPOSE: To add elements in ascending order (low to high)
    void addInOrderAscend(T e);
    
    //HOW TO CALL: Call onto an existing queue with the element you want
    //PURPOSE: To add elements in descending order (high to low)
    void addInOrderDescend(T e);
    
    //HOW TO CALL: Call onto an existing queue with the element you want
    //PURPOSE: returns true or false if the element if found or not
    bool search(T e);
    
    //HWO TO CALL:  Call on existing lqueue ([lqueueName].displayAll())
    //PURPOSE:      To print all the elements in reverse. Calls
    //              printAllReverse(node<T>*) to reverse recusively
    void printAllReverse();
    
    class Underflow {};
    class Overflow {
    private:
        T val; public:
        //constructor
        Overflow(T v){val = v;}
        //get function to access the private data member T getElem(){return val;}
    };
    
};

//PURPOSE:      Constructor which initilizes front, rear, and count
//PURPOSE:      Constructor which initilizes front, rear, and count
template <class T>
LL<T>::LL() {
    front = NULL;
    rear = NULL;
    count = 0;
}

//PURPOSE:      When the program hits and endbrace '}', delete the LL
//ALGORITHM:    While the LQueue isn't empty, delete front
template <class T>
LL<T>::~LL() {
    while (!isEmpty()) {
        deleteFront();
    }
}

//PURPOSE:      To add en element to the rear of the lqueue
//PARAMS:       the element to add the the lqueue
//ALGORITHM:    if empty, make a new node and set the element. front->next = NULL
//              else, make a new node on rear->next, set the element and set rear
//              ->next to NULL
template <class T>
void LL<T>::addRear(T value) {
    if (isEmpty()) {
        front = new node<T>;
        rear = front;
        front->elem = value;
        front->next = NULL;
        count++;
    }
    else {
        rear->next = new node<T>;
        rear = rear->next;
        rear->elem = value;
        rear->next = NULL;
        count++;
    }
}

//PURPOSE:      To delete the front pointer and display the element
//PARAMS:       None
//ALGORITHM:    while the lqueue isn't empty, set a temp element to front->next
//              and deletethe front. Set the temp to the front and return the element
template <class T>
T LL<T>::deleteFront() {
    if (isEmpty()) {
        throw Underflow();
        return 0;
    }
    
    else {
        if (count == 1) {
            T second = front->elem;
            delete front;
            front = NULL;
            rear = NULL;
            count--;
            return second;
        }
        else {
            node<T>* second = front->next;
            T sec = front->elem;
            delete front;
            front = second;
            count--;
            return sec;
        
        }
    }
}

//PURPOSE:      To return if a queue is empty or not (returns true or false)
//PARAMS:       None
//ALGORITHM:    if count is at the initilized state of 0, return true, else
//              return false
template <class T>
bool LL<T>::isEmpty() {
    if (front == NULL && rear == NULL)
        return true;
    else
        return false;
}

//PURPOSE:      To display all the elements in the lqueue
//PARAMS:       None
//ALGORITHM:    While the lqueue isn't empty, put a temp pointer to the front
//              and while the temp->next = NULL, keep displaying and moving
//              the element
template <class T>
void LL<T>::displayAll() {
    if (isEmpty()) {
        cout << "[EMPTY]" << endl;
    }
    else {
        node<T>* p = front;
        while (p != NULL) {
            cout << "[";
            cout << p->elem;
            p = p->next;
            cout << "]" << " ";
        }
        cout << endl;
    }
}

//PURPOSE:      To add an node to the front before all other pointers
//PARAMS:       The element you would like to add
//ALGORITHM:    stores the front node in a temp pointer, makes a new pointer
//              in front and sets front->next to the temp pointer
template <class T>
void LL<T>::addFront(T elem) {
    if (isEmpty()) {
        addRear(elem);
    }
    else {
        node<T>* second = front;
        front = new node<T>;
        front->next = second;
        front->elem = elem;
        count++;
    }
}

//PURPOSE:      To delete the rear pointer from the LL
//PARAMS:       None
//ALGORITHM:    determines if the LL has one, none or many elements, then
//              stores the element in a temp variable, sets the rear pointer to
//              NULL and the previous become rear, returns the element
template <class T>
T LL<T>::deleteRear() {
    if (isEmpty()) {
        throw Underflow();
        return 0;
    }
    else {
        if (count == 1) {
            T second = rear->elem;
            delete rear;
            front = NULL;
            rear = NULL;
            count--;
            return second;
        }
        else {
            node<T>* p = front;
            while (p->next != rear) {
                p = p->next;
            }
            T sec = rear->elem;
            delete p->next;
            rear = p;
            rear->next = NULL;
            count--;
            return sec;
        }
    }
}

//PURPOSE:      To delete the first node containing the element
//PARAMS:       The element to search for and delete
//ALGORITHM:    makes two pointers, and starts from the front and moves back
//              if the elem is found, delete the node, set pre->next to the
//              node following delete and display message
template <class T>
void LL<T>::deleteNode(T e) {
    
    if (!isEmpty()) {
        if (front->elem == e) {
            deleteFront();
        }
        else {
            node<T>* pre;
            node<T>* del;
            for(pre = front, del = front->next; del!= NULL && del->elem != e; pre = del, del = del->next)
                ;
            
            if(del != NULL) {
                pre->next = del->next;
                if (del == rear)
                    rear = pre;
                delete del;
                count--;
            }
        }
    }
}

//PURPOSE:      To delete all nodes containing the element
//PARAMS:       The element to search for and delete
//ALGORITHM:    Makes two pointers, and searches until del == NULL. If
//              Elem is found, delete and makes pre->next the node following del
//              displays message if found or not.
template <class T>
void LL<T>::deleteNodes(T e) {
    
    if (!isEmpty()) {
        bool found = false;
        node<T>* pre = front;
        node<T>* del = front->next;
        
        while (del != NULL) {
            if (del->elem == e) {
                pre->next = del->next;
                if (del == rear)
                    rear = pre;
                delete del;
                found = true;
                count--;
            }
            else
                pre = pre->next;
            del = pre->next;
        }
        if (front->elem == e) {
            deleteFront();
            found = true;
        }
    }
}

template <class T>
void LL<T>::addInOrderAscend(T e) {
    
    if (isEmpty()) {
        addFront(e);
    }
    else if (front->elem > e) {
        addFront(e);
    }
    else {
        node<T>* p = front;
        while(p->next != NULL && p->next->elem < e)
            p = p->next;
        
        node<T>* next;
        
        next = p->next;
        p->next = new node<T>;
        p->next->next = next;
        p->next->elem = e;
        count++;
    }
}

template <class T>
void LL<T>::addInOrderDescend(T e) {
    
    if (isEmpty()) {
        addFront(e);
    }
    else if (front->elem < e) {
        addFront(e);
    }
    else {
        node<T>* p = front;
        while(p->next != NULL && p->next->elem > e)
            p = p->next;
        
        node<T>* next;
        
        next = p->next;
        p->next = new node<T>;
        p->next->next = next;
        p->next->elem = e;
        count++;
    }
    
}

template <class T>
bool LL<T>::search(T e) {
    if (isEmpty()) {
        return false;
    }
    else {
        node<T>* scan = front;
        while(scan != NULL) {
            if (scan->elem == e) {
                return true;
            }
            scan = scan->next;
        }
    }
    return false;
}

//PURPOSE:      To display the lqueue in reverse
//PARAMS:       None
//ALGORITHM:    calls the private function printAllReverse(node<T>* p) with the param
//              'front'
template <class T>
void LL<T>::printAllReverse() {
    printAllReverse (front);
}

//PURPOSE:      (Private) To display the lqueue in reverse recursively
//PARAMS:       pointer to the first node
//ALGORITHM:    while the pointer isn't NULL, continue to the next pointer
//              if pointer = NULL, return and display element
template <class T>
void LL<T>::printAllReverse(node<T>* p) {
    if(p == NULL)
        return;
    else {
        printAllReverse(p->next);
        cout << p->elem;
    }
}


#endif /* LL_T_hpp */
