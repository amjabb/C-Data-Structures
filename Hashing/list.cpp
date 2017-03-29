//
//  list.cpp
//  search
//
//  Created by Amir Jabbari on 10/29/15.
//  Copyright © 2015 Amir Jabbari. All rights reserved.
//

#include "list.hpp"

#include <iostream>
#include <sstream>
using namespace std;

list::list(){
    head = NULL;
    curr = NULL;
    temp = NULL;
    length = 0;
}

void list::AddNode(int count){
    stock s;
    for(int i = 0;i<=count;i++)
    {
        
        int r = rand()%100 +1;
        stringstream st;
        st << "A" << i;
        string result = st.str();
        s.stockInit(result,r);
    nodePtr n = new node;
    n->next = NULL;
    n->data = s;
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
}

void list::search(int user){
    curr = head;
    int count = 0;
    while(curr!=NULL){
        stock s;
        s = curr->data;
        if(s.getPrice() == user)
        {
            cout << "Element Index: " << count << endl;
            break;
        }
        curr = curr->next;
        ++count;
    }
}

void list::printList(){
    curr = head;
    while(curr != NULL)
    {
        cout << curr->data;
        curr = curr->next;
    }
    
}

void list::searchRec(nodePtr curr, int user,int count){
        if (curr == NULL)
            return;
        else {
            stock s;
            s = curr->data;
            if (s.getPrice() == user)
                cout << "Element Index: " << count << endl;
            else
                searchRec(curr->next, user, ++count);
            }
}

void list::setSearchRec(int user){
    int count = 0;
    searchRec(head,user,count);
}



