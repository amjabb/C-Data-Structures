//
//  array.cpp
//  search
//
//  Created by Amir Jabbari on 10/29/15.
//  Copyright © 2015 Amir Jabbari. All rights reserved.
//

#include "array.hpp"
#include <iostream>
#include <sstream>
using namespace std;

Array::Array(){
    length = 100;
    list = new stock[length];
}

Array::Array(int num){
    length = num;
    list = new stock[num];
}
void Array::initializeArray(int user){
    stock s;
    for(int i = 0;i<=user;i++)
    {
        
        int r = rand()%100 +1;
        stringstream st;
        st << "A" << i;
        string result = st.str();
        s.stockInit(result,r);
        list[i] = s;
    }
}

void Array::printArray(){
    for(int i = 0; i<=getLength(); i++){
        cout << list[i];
    }
}

int Array::getLength(){
    return length;
}

void Array::seqSearch(int item){
    int loc;
    int count = 0;
    bool found = false;
    for (loc = 0; loc < getLength(); loc++){
        ++count;
        if (list[loc].getPrice() == item)
    {
        found = true;
        break;
    }}
    if (found)
        cout << "Element Index: " << count << endl;
    else
        cout<< "Element not in List" << endl;
}

int Array::seqRecSearch(int item, int loc){
    bool found = false;
    if (loc < getLength()){
        if (list[loc].getPrice() == item)
        {
            return loc;
        } return seqRecSearch(item, ++loc); }
    else
        return -1;
}

void Array::setseqRecSearch(int count){
    cout << "Element Index: " << seqRecSearch(count, 0) << endl;
}

void Array::binSearch(int item){
    int first = 0;
    int last = getLength() - 1;
    int mid = 0;
    bool found = false;
    while (first <= last && !found)
    {
        mid = (first + last) / 2;
        if (list[mid].getPrice() == item) found = true;
        else if (list[mid].getPrice() > item) last = mid - 1;
        else
            first = mid + 1;
    }
    if (found)
        cout << "Element Index: " << mid << endl;
    else
        cout<< "Element not in List" << endl;
}

void Array::sort(){
    int count = getLength();
    stock temp;
    for(int i =0;i<count;i++)
    {
        for(int j = 0; j<count-i;j++)
        {
            if(list[j].getPrice()>list[j+1].getPrice())
            {
                temp=list[j];
                list[j]=list[j+1];
                list[j+1] = temp;
            }
        }
    }
}

int Array::binRecSearch(int item, int first, int last){
    int mid = (first + last)/2;
    if(first>last) return -1;
    if(list[mid].getPrice() == item) return mid;
    if(list[mid].getPrice()>item) return binRecSearch(item, first, mid-1);
    else
       return binRecSearch(item, mid+1, last);
}

void Array::setbinRecSearch(int user){
    cout << "Element Index: " << binRecSearch(user, 0, getLength());
}

