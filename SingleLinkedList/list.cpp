#include <cstdlib>
#include <iostream>

#include "list.h"

using namespace std;

list::list(){
    head = NULL;
    curr = NULL;
    temp = NULL;
    length = 0;
}

void list::AddNode(stock st){
    nodePtr n = new node;
    n->next = NULL;
    n->data = st;
    
    if(head != NULL){
        curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = n;
    }
    else
    {
        head = n;
    }
    ++length;
}

void list::printList(){
    curr = head;
    while(curr != NULL)
    {
        cout << curr->data;
        curr = curr->next;
    }
    
}

void list::getMiddleNode(){
    curr = head;
    int m = 0;
    for( ;m<length/2;m++)
    {
        curr = curr->next;
    }
    cout << "Middle Node:" <<endl;
    cout<< curr->data;
    cout<< "Position from zero:"<<m+1<<endl;
    
}

void list::splitList(){
    curr = head;
    int m = 0;
    list l1,l2;
    for( ;m<length/2;m++)
    {
        l1.AddNode(curr->data);
        curr = curr->next;
    }
    for( ;m<length;m++)
    {
        l2.AddNode(curr->data);
        curr = curr->next;
    }   
    cout<<"First half: " <<endl; 
    l1.printList();
    cout<<"Second half: "<<endl;
    l2.printList();
}