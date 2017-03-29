//
//  list.hpp
//  search
//
//  Created by Amir Jabbari on 10/29/15.
//  Copyright © 2015 Amir Jabbari. All rights reserved.
//

#ifndef list_hpp
#define list_hpp

#include <iostream>
using namespace std;
#include "stock.hpp"

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
    void AddNode(int);
    void printList();
    void getMiddleNode();
    void splitList();
    void search(int);
    void searchRec(nodePtr,int,int);
    void setSearchRec(int);
};
#endif /* list_hpp */
