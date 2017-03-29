//
//  main.cpp
//  search
//
//  Created by Amir Jabbari on 10/29/15.
//  Copyright © 2015 Amir Jabbari. All rights reserved.
//

#include <iostream>
using namespace std;
#include "list.hpp"
#include "array.hpp"

int main(int argc, const char * argv[]) {
    int choice;
    int number;
    int element;
    do{
        cout<<"\nChoose your search type:";
        cout<<"\n1. Arrays: Sequential Search without recursion";
        cout<<"\n2. Arrays: Sequential Search with recursion";
        cout<<"\n3. Ordered Arrays: Binary Search without recursion";
        cout<<"\n4. Ordered Arrays: Binary Search with recursion";
        cout<<"\n5. Linked List: Search without recursion";
        cout<<"\n6. Linked List: Search with recursion";
        cout<<"\nEnter 0 to exit.\nYour choice: ";
        cin>>choice;
        if (choice!=0){
        cout<<"\nSpecify the number of elements to be searched: ";
            cin>>number;}
        switch (choice) {
            case 1:{
                Array list(number);
                list.initializeArray(number);
                list.printArray();
                cout << "Specify the element to be searched for by price: ";
                cin >> element;
                list.seqSearch(element);
                break;}
            case 2:{
                Array list(number);
                list.initializeArray(number);
                list.printArray();
                cout << "Specify the element to be searched for by price: ";
                cin >> element;
                list.setseqRecSearch(element);
                break;}
            case 3:{
                Array list(number);
                list.initializeArray(number);
                list.sort();
                list.printArray();
                cout << "Specify the element to be searched for by price: ";
                cin >> element;
                list.binSearch(element);
                break;}
            case 4:{
                Array list(number);
                list.initializeArray(number);
                list.sort();
                list.printArray();
                cout << "Specify the element to be searched for by price: ";
                cin >> element;
                list.setbinRecSearch(element);
                break;}
            case 5: {
                list linked;
                linked.AddNode(number);
                linked.printList();
                cout << "Specify the element to be searched for by price: ";
                cin >> element;
                linked.search(element);
                break; }
            case 6: {
                list linked;
                linked.AddNode(number);
                linked.printList();
                cout << "Specify the element to be searched for by price: ";
                cin >> element;
                linked.setSearchRec(element);
                break; }
            default:
                cout << "Please enter a valid entry!" << endl;
                break;
        }
        
    }while(choice!=0);

}
