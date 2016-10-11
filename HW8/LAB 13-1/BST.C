#include <iostream>
#include <stdlib.h>
#include "LL.hpp"
using namespace std;

typedef int el_t;

class Node
{
  friend class BST;
private:
  el_t elem;
  Node* right;
  Node* left;
public:
  Node(el_t e){elem = e; right = NULL; left = NULL;}
};

class BST
{
private:
  Node* root;
  void insertNode(Node*&, el_t);
public:
  BST();
  void insertNode(el_t);
  bool search(el_t e);
};

BST::BST()
{
  root = NULL;
}

void BST::insertNode(el_t e)
{
  insertNode(root, e);
}

void BST::insertNode(Node*& p, el_t e)
{
  if(p == NULL)
    p = new Node(e);
  else if(e < p->elem)
    insertNode(p->left, e);
  else
    insertNode(p->right, e);
}
 
bool BST::search(el_t e)
{
    Node* p = root;
    int i = 0;
    while (p != NULL) {
        if (e == p->elem) {
            cout << i << " NODES CHECKED" << endl;
            return true;
        }
        else if (e < p->elem)
            p = p->left;
        else
            p = p->right;
        i++;
    }
    cout << i << " NODES CHECKED" << endl;
    return false;
}

int main()
{
  srand(time(0));

    BST b;
    LL l;
    int n;
    
    for (int i = 1; i <= 10000; i++) {
        n = rand() % 10000 + 1;
        b.insertNode(n);
        l.addRear(n);
    }

  int key;
  cout << "What number do you want to search for? ";
  cin >> key;


  cout << "BST *************************" << endl;
 
    if (b.search(key))
        cout << "FOUND" << endl;
    else
        cout << "NOT FOUND" << endl;
    cout << endl;

  cout << "LL************************" << endl;
  
    if (l.search(key))
        cout << "FOUND" << endl;
    else
        cout << "NOT FOUND" << endl;
  

  return 0;
}
