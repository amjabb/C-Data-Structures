//
//  quadraticHash.hpp
//  search
//
//  Created by Amir Jabbari on 11/15/15.
//  Copyright © 2015 Amir Jabbari. All rights reserved.
//

#ifndef quadraticHash_hpp
#define quadraticHash_hpp

#include <iostream>
#include "stock.hpp"
using namespace std;

class quadHash{
private:
    static const int tableSize = 10;
    stock* HashTable[tableSize];
    int StatusTable[tableSize] = {0};
    
public:
    quadHash(int);
    int hash(string key);
    void AddItem(string sname, int sprice);
    int NumberOfItemsInIndex(int index);
    void printTable();
    void printItemsInIndex(int index);
    void search(string sname);
};

#endif /* quadraticHash_hpp */
