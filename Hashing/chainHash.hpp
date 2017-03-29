//
//  quadHash.hpp
//  search
//
//  Created by Amir Jabbari on 11/15/15.
//  Copyright © 2015 Amir Jabbari. All rights reserved.
//

#ifndef quadHash_hpp
#define quadHash_hpp

#include <iostream>
#include "stock.hpp"
using namespace std;

class chainHash{
private:
    static const int tableSize = 10;
    int StatusTable[tableSize] = {0};
    typedef struct node{
        stock data;
        node* next;
    }* nodePtr;
    nodePtr HashTable[tableSize];
    nodePtr head;
    nodePtr curr;
    nodePtr temp;
    int length;
public:
    chainHash(int);
    int chainhash(string key);
    void AddItem(string sname, int sprice);
    int NumberOfItemsInIndex(int index);
    void printTable();
    void printItemsInIndex(int index);
    void search(string sname);
};

#endif /* quadHash_hpp */
