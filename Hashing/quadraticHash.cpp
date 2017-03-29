//
//  quadraticHash.cpp
//  search
//
//  Created by Amir Jabbari on 11/15/15.
//  Copyright © 2015 Amir Jabbari. All rights reserved.
//

#include "quadraticHash.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

quadHash::quadHash(int size)
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
        int mult = 1;
        while (StatusTable[index] == 1) {
            if(index == size)
                index = 0;
            index += (mult*mult)%tableSize;
            mult++;
        }
        StatusTable[index] = 1;
        HashTable[index] =  new stock(result,r);
    }
}

void quadHash::AddItem(string sname, int sprice)
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

int quadHash::NumberOfItemsInIndex(int index)
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

void quadHash::printTable()
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

void quadHash::printItemsInIndex(int index)
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

void quadHash::search(string sname)
{
    int index = hash(sname);
    bool foundName = false;
    int number = 1;
    
    stock* Ptr = HashTable[index];
    for ( int i = 0; i < tableSize; i++)
    {
        if (sname == HashTable[index]->getName()) {
            foundName = true;
            break;
        }
        else {
            index += (number*number)%tableSize;
            
        }
    }
    if(foundName == true)
    {
        cout << "Stock Price = " << HashTable[index]->getPrice()<< endl;
        cout << "Location = " << index << endl;
    }
}

int quadHash::hash(string key)
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