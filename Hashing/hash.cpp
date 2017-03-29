//
//  hash.cpp
//  search
//
//  Created by Amir Jabbari on 11/2/15.
//  Copyright © 2015 Amir Jabbari. All rights reserved.
//

#include "hash.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Hash::Hash(int size)
{
    for(int i = 0; i < tableSize; i++)
    HashTable[i] = new stock();
    for(int i = 0; i < size; i++)
    {
        int r = rand()%100 +1;
        stringstream st;
        st << "A" << i;
        string result = st.str();
        int index = hash(result);
        
        while (StatusTable[index] == 1) {
            if(index == size)
                index = 0;
            index = index+1;
        }
        StatusTable[index] = 1;
        HashTable[index] =  new stock(result,r);
    }
}

void Hash::AddItem(string sname, int sprice)
{
    int index = hash(sname);
    while (StatusTable[index] == 1) {
        if(index == tableSize)
            index = 0;
        index = index+1;
    }
    StatusTable[index] = 1;
    HashTable[index]->stockInit(sname,sprice);
}

void Hash::deleteItem(string name){
    int index = hash(name);
    while (StatusTable[index]==1){
        if (HashTable[index]->getName() == name) {
        HashTable[index]->setName("empty");
        HashTable[index]->setPrice(0);
        StatusTable[index] = 0;
        }
    else{
        index += 1;
    }
    }
    cout << "\nAfter item is deleted: "<<endl;
    printTable();
}

int Hash::NumberOfItemsInIndex(int index)
{
    int count = 0;
    
    if(HashTable[index]->getName() == "empty")
    {
        return count;
    }
    else
    {
        count++;
        stock* Ptr = HashTable[index];
        
    }
    return count;
}

void Hash::printTable()
{
    int number;
    for(int i = 0; i < tableSize; i++)
    {
        if (HashTable[i]->getName() == "empty")
        {
            cout << "index = " << i << endl;
            cout << "Empty" << endl;
            cout << 0 << endl;
        }
        else{
        cout << "index = " << i << endl;
        cout << HashTable[i]->getName() << endl;
        cout << HashTable[i]->getPrice() << endl;
        }
    }
}

void Hash::printItemsInIndex(int index)
{
    stock* Ptr = HashTable[index];

    for(int i = 0; i < tableSize; i++)
    {
    if(Ptr->getName() == "empty")
    {
        cout << "index = " << index << " is empty";
    }
    else
    {
        cout << "index " << index << " contains the following item\n";
    }
    }
}

void Hash::search(string sname)
{
    int index = hash(sname);
    bool foundName = false;
    int sprice;
    
    stock* Ptr = HashTable[index];
    for ( int i = 0; i < tableSize; i++)
    {
        if (sname == HashTable[index]->getName()) {
            foundName = true;
            break;
        }
        else {
            index++;
        }
    }
    if(foundName == true)
    {
        cout << "Stock Price = " << HashTable[index]->getPrice()<< endl;
        cout << "Location = " << index << endl;
    }
}

int Hash::hash(string key)
{
    int hash = 0;
    int index;
    
    for(int i = 0; i < key.length(); i++)
    {
        hash = (hash + (int)key[i]) * 8;
    }
    
    index = hash % tableSize;
    
    return index;
}