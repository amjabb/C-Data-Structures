//
//  portfolio.cpp
//  lab4
//
//  Created by Amir Jabbari on 9/20/15.
//  Copyright © 2015 Amir Jabbari. All rights reserved.
//

#include "portfolio.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

portfolio::portfolio()
{
    head = NULL;
    tail = NULL;
    dbFileName = "ListOutput.txt";
}

bool portfolio::load(string fn)
{
    ifstream fin(fn.c_str());
    if(fin.fail()) return(false);
    while(!fin.eof()){
        stockNode * st = new stockNode;
        fin >> *st;
        if(head == NULL)
        {
            st->back = st->next = NULL;
            head = tail = st;
        }
        else
        {
            st->back = tail;
            tail->next = st;
            st->next = NULL;
            tail=st;
        }
        
    }
    fin.close();
    return(true);
}

bool portfolio::save(string fn)
{
    if(fn.empty()) fn = dbFileName;
    ofstream fout(fn.c_str());
    if(fout.fail()) return(false);
    stockNode * st = head;
    while(st != NULL)
    {
        fout << *st;
        st = st->next;
    }
    fout.close();
    return(true);
}

void portfolio::print()
{
    stockNode * sn = head;
    while (sn != NULL)
    {
        cout << *sn;
        sn = sn->next;
    }
}

void portfolio::print_rev()
{
    stockNode * sn = tail;
    while (sn != NULL)
    {
        cout << *sn;
        sn = sn->back;
    }
}

void portfolio::recPrint_rev(stockNode* sn){
    if(sn != NULL)
    {
        cout<<*sn;
        recPrint_rev(sn->back);
    }
}

bool portfolio::remove(string sn)
{
    if(head==NULL) return false;
    if(head->sname == sn){
        stockNode *temp = head;
        head = temp->next;
        head->back = NULL;
        delete temp;
        return true;
    }
    stockNode *ptprev = head;
    stockNode *pt = ptprev->next;
    while(pt!=NULL)
    {
        if(pt->sname == sn)
        {
            ptprev->next = pt->next; 
            delete pt;
            return true;
        }
        ptprev = pt;
        pt = pt->next;
    }
    return false;
}

void portfolio::add(string sn,int p)
{
    stockNode * n = new stockNode;
    stockNode * temp = new stockNode;
    n->next = n->back = NULL;
    n->sname = sn;
    n->sprice = p;
    if(head!=NULL){
        temp = head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next = n;
    }
}

void portfolio::addToBeg(string sn,int p)
{
    stockNode * n = new stockNode;
    n->next = n->back = NULL;
    n->sname = sn;
    n->sprice = p;
    n->next = head;
    n->back = NULL;
    if (head != NULL)
        head = tail = n;
    else
        head = n;
    
}

void portfolio::addToMid(string sn,int p)
{
    stockNode * n = new stockNode;
    n->sname = sn;
    n->sprice = p;
    stockNode * n1 = tail;
    stockNode * n2 = head;
    while (n1 != n2 && n1->next != n2)
    {
        n1 = n1->back;
        n2 = n2->next;
    }
    n->back = n1;
    n->next = n1->next;
    n->next->back = n;
    n1->next = n;
}

void portfolio::userChoice()
{
    int choice;
    bool gameOn = true;
    while (gameOn != false){
        cout << "*******************************\n";
        cout << " 1 - Load File\n";
        cout << " 2 - Save to Output File\n";
        cout << " 3 - Print Recursive Reverse\n";
        cout << " 4 - Print\n";
        cout << " 5 - Remove First\n";
        cout << " 6 - Remove Mid\n";
        cout << " 7 - Remove Last\n";
        cout << " 8 - Add to Beginning\n";
        cout << " 9 - Add to Middle\n";
        cout << " 10 - Add to End\n";
        cout << " 11 - Exit Program\n";
        cout << " Enter your choice and press return: ";
        
        cin >> choice;
        switch (choice)
        {
            case 1:
                load("input.txt");
                break;
            case 2:
                save("Output.txt");
                break;
            case 3:
                //print_rev();
                recPrint_rev(tail);
                break;
            case 4:
                print();
                break;
            case 5:
                remove("A1");
                break;
            case 6:
                remove("A10");
                break;
            case 7:
                remove("A20");
                break;
            case 8:
            {
                string uStock;
                int uPrice;
                cout << "Enter the name of  the Stock:";
                cin >> uStock;
                cout << "Enter the price of the Stock:";
                cin >> uPrice;
                addToBeg(uStock, uPrice);
                break;
            }
            case 9:
            {
                string uStock;
                int uPrice;
                cout << "Enter the name of  the Stock:";
                cin >> uStock;
                cout << "Enter the price of the Stock:";
                cin >> uPrice;
                addToMid(uStock, uPrice);
                break;
            }
            case 10:
            {
                string uStock;
                int uPrice;
                cout << "Enter the name of  the Stock:";
                cin >> uStock;
                cout << "Enter the price of the Stock:";
                cin >> uPrice;
                add(uStock, uPrice);
                break;
            }
            case 11:
                cout << "End of Program.\n";
                gameOn = false;
                break;
            default:
                cout << "Not a Valid Choice. \n";
                cout << "Choose again.\n";
                cin >> choice;
                break;
        }
        
    }
}
