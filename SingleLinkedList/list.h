#include <cstdlib>
#include <iostream>

using namespace std;
#include "stock.cpp"
class list{
private:
    
    typedef struct node{
        stock data;
        node* next;
    }* nodePtr;
    
    nodePtr head;
    nodePtr curr;
    nodePtr temp;
    int length;
    
public:
    list();
    void AddNode(stock);
    void printList();
    void getMiddleNode();
    void splitList();
};