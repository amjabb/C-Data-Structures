//
//  quadHash.cpp
//  search
//
//  Created by Amir Jabbari on 11/15/15.
//  Copyright © 2015 Amir Jabbari. All rights reserved.
//

#include "chainHash.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

chainHash::chainHash(int size)
{
    for(int i = 0; i < tableSize; i++)
    {
        HashTable[i] = new node;
        HashTable[i]->data.setName("empty");
        HashTable[i]->data.setPrice(0);
        HashTable[i]->next = NULL;
    }
    for(int i = 0; i < size; i++)
    {
        int r = rand()%100 +1;
        stringstream st;
        st << "A" << i;
        string result = st.str();
        int index = chainhash(result);
        if(HashTable[index]->data.getName() == "empty")
        {
            HashTable[index]->data.setName(result);
            HashTable[index]->data.setPrice(r);
        }
        else{
            nodePtr Ptr = HashTable[index];
            nodePtr n = new node;
            n->data.setName(result);
            n->data.setPrice(r);
            while (Ptr->next != NULL) {
                Ptr = Ptr->next;
            }
            Ptr->next = n;
        }
    }
}

void chainHash::AddItem(string sname, int sprice)
{
    int index = chainhash(sname);
    while (StatusTable[index] == 1) {
        if(index == tableSize)
            index = 0;
        index = index+1;
    }
    StatusTable[index] = 1;
    HashTable[index]->data.stockInit(sname,sprice);
}


void chainHash::printTable()
{
    int number;
    for(int i = 0; i < tableSize; i++)
    {
        if (HashTable[i]->data.getName() == "empty")
        {
            cout << "index = " << i << endl;
            cout << "Empty" << endl;
            cout << 0 << endl;
        }
        else{
            cout << "index = " << i << endl;
            cout << HashTable[i]->data.getName() << endl;
            cout << HashTable[i]->data.getPrice() << endl;
            nodePtr Ptr = HashTable[i];
            while (Ptr->next!=NULL) {
                HashTable[i] = HashTable[i]->next;
                cout << "index = " << i << endl;
                cout << HashTable[i]->data.getName() << endl;
                cout << HashTable[i]->data.getPrice() << endl;
                Ptr = Ptr->next;
            }
        }
    }
}

void chainHash::printItemsInIndex(int index)
{
    nodePtr Ptr = HashTable[index];
    
    for(int i = 0; i < tableSize; i++)
    {
        if(Ptr->data.getName() == "empty")
        {
            cout << "index = " << index << " is empty";
        }
        else
        {
            cout << "index " << index << " contains the following item\n";
        }
    }
}

void chainHash::search(string sname)
{
    int index = chainhash(sname);
    bool foundName = false;
    int sprice;
    
    nodePtr Ptr = HashTable[index];
    for ( int i = 0; i < tableSize; i++)
    {
        if (sname == HashTable[index]->data.getName()) {
            foundName = true;
            break;
        }
        else {
            while (Ptr->next!=NULL) {
                if ( sname == HashTable[index]->data.getName())
                {
                    foundName = true;
                    break;
                }
                else
                    Ptr = Ptr->next;
            }
        }
    }
    if(foundName == true)
    {
        cout << "Stock Price = " << HashTable[index]->data.getPrice()<< endl;
        cout << "Location = " << index << endl;
    }
}

int chainHash::chainhash(string key)
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