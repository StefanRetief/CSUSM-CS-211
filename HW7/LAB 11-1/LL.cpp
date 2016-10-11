// Stefan Retief
// CS211 LL, HW5
// LL Class - Class File
// ======================================================

#include <iostream>
#include "LL.hpp"

//PURPOSE:      Constructor which initilizes front, rear, and count
LL::LL() {
    front = NULL;
    rear = NULL;
    count = 0;
}

//PURPOSE:      When the program hits and endbrace '}', delete the LL
//ALGORITHM:    While the LQueue isn't empty, delete front
LL::~LL() {
    while (!isEmpty()) {
        deleteFront();
    }
}

//PURPOSE:      To add en element to the rear of the lqueue
//PARAMS:       the element to add the the lqueue
//ALGORITHM:    if empty, make a new node and set the element. front->next = NULL
//              else, make a new node on rear->next, set the element and set rear
//              ->next to NULL
void LL::addRear(el_t value) {
    if (isEmpty()) {
        front = new node;
        rear = front;
        front->elem = value;
        front->next = NULL;
        count++;
    }
    else {
        rear->next = new node;
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
el_t LL::deleteFront() {
    if (isEmpty()) {
        queueError("UNABLE TO REMOVE FRONT. QUEUE UNDERFLOW.");
        return 0;
    }
    
    else {
        if (count == 1) {
            el_t second = front->elem;
            delete front;
            front = NULL;
            rear = NULL;
            count--;
            return second;
        }
        else {
            if (isEmpty()) {
                queueError("UNABLE TO REMOVE REAR. QUEUE UNDERFLOW");
                return 0;
            }
            else {
                node* second = front->next;
                el_t sec = front->elem;
                delete front;
                front = second;
                count--;
                return sec;
            }
        }
    }
}

//PURPOSE:      To return if a queue is empty or not (returns true or false)
//PARAMS:       None
//ALGORITHM:    if count is at the initilized state of 0, return true, else
//              return false
bool LL::isEmpty() {
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
void LL::displayAll() {
    if (isEmpty()) {
        cout << "[EMPTY]" << endl;
    }
    else {
        node* p = front;
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
void LL::addFront(el_t elem) {
    if (isEmpty()) {
        addRear(elem);
    }
    else {
        node* second = front;
        front = new node;
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
el_t LL::deleteRear() {
    if (isEmpty()) {
        queueError("UNABLE TO REMOVE REAR. QUEUE UNDERFLOW");
        return 0;
    }
    else {
        if (count == 1) {
            el_t second = rear->elem;
            delete rear;
            front = NULL;
            rear = NULL;
            count--;
            return second;
        }
        else {
            if (isEmpty()) {
                queueError("UNABLE TO REMOVE REAR. QUEUE UNDERFLOW");
                return 0;
            }
            else {
                node* p = front;
                while (p->next != rear) {
                    p = p->next;
                }
                el_t sec = rear->elem;
                delete p->next;
                rear = p;
                rear->next = NULL;
                count--;
                return sec;
            }
        }
    }
}

//PURPOSE:      To delete the first node containing the element
//PARAMS:       The element to search for and delete
//ALGORITHM:    makes two pointers, and starts from the front and moves back
//              if the elem is found, delete the node, set pre->next to the
//              node following delete and display message
void LL::deleteNode(el_t e) {
    
    if (!isEmpty()) {
        if (front->elem == e) {
            deleteFront();
            cout << "ELEMENT FOUND! FIRST " << e << " ELEMENT DELETED!" << endl;
        }
        else {
            node* pre;
            node* del;
            for(pre = front, del = front->next; del!= NULL && del->elem != e; pre = del, del = del->next)
                ;
            
            if(del != NULL) {
                pre->next = del->next;
                if (del == rear)
                    rear = pre;
                delete del;
                count--;
                cout << "ELEMENT FOUND! FIRST " << e << " ELEMENT DELETED!" << endl;
            }
            else {
                cout << "ELEMENT NOT FOUND!" << endl;
            }
        }
    }
}

//PURPOSE:      To delete all nodes containing the element
//PARAMS:       The element to search for and delete
//ALGORITHM:    Makes two pointers, and searches until del == NULL. If
//              Elem is found, delete and makes pre->next the node following del
//              displays message if found or not.
void LL::deleteNodes(el_t e) {
    
    if (!isEmpty()) {
        bool found = false;
        node* pre = front;
        node* del = front->next;
        
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
        if (!found) {
            cout << "ELEMENT NOT FOUND!" << endl;
        }
        else {
            cout << "ELEMENT FOUND! ALL " << e << " ELEMENTS DELETED!" << endl;
        }
    }
}

//PURPOSE:      (Private) To handle unexpected errors encountered by other
//              methods
//PARAMS:       String message to be displayed
//ALGORITHM:    'cout' the message and exit program with error code 1
void LL::queueError(string msg) {
    cout << msg << endl;
    exit(1);
}