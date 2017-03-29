//
//  hash.hpp
//  search
//
//  Created by Amir Jabbari on 11/2/15.
//  Copyright © 2015 Amir Jabbari. All rights reserved.
//

#ifndef hash_hpp
#define hash_hpp

#include <iostream>
#include "stock.hpp"
using namespace std;

class Hash{
private:
    static const int tableSize = 10;
    stock* HashTable[tableSize];
    int StatusTable[tableSize] = {-1};
   
public:
    Hash(int);
    int hash(string key);
    void AddItem(string sname, int sprice);
    void deleteItem(string name);
    int NumberOfItemsInIndex(int index);
    void printTable();
    void printItemsInIndex(int index);
    void search(string sname);
};

#endif /* hash_hpp */
