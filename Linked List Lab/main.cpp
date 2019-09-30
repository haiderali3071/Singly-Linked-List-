//
//  main.cpp
//  Linked List Lab
//
//  Created by Haider Ali on 9/24/19.
//  Copyright © 2019 Haider Ali. All rights reserved.
//

#include <iostream>
using namespace std;

class Node{
 
public:
    int data=NULL;
    Node *next=NULL;
};

class LinkedList {
    
    Node *first = NULL;
    Node *loc;
    Node *ploc;
    int i=0;
    
public:
    bool isEmpty() {
        
        return first == NULL;
    }
    
    void insertAtFront(int value) {
        
        Node *temp = new Node();
        temp->data = value;
      
        if(isEmpty()) {
            first = temp;
        }
        else{
            temp->next = first;
            first = temp;
        }
    }
    
    void printList() {
        
        
        Node *temp = first;
        
        while(temp != NULL){
            
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }
    void reversePrint() {
    
        Node *temp = first;
        ploc = NULL;
        
        while(temp != ploc) {
        
            if(temp->next == ploc) {
                
                cout<<temp->data<<endl;
                ploc = temp;
                temp = first;
            }
            else {
                temp = temp->next;
            }
        }
    }
    
    void search(int value) {
        
        loc = first;
        ploc = NULL;
        
        if(isEmpty()) {
            return;
        }
        
        while(loc != NULL && loc->data<value) {
            
            ploc = loc;
            loc = loc->next;
        }
        
        if(loc != NULL && loc->data != value){
            
            loc = NULL;
        }
    }
    
    void insertSorted(int value) {
        
        search(value);
        
        if(loc != NULL) {
            
            cout<<"Value already exist. Duplication not allowed";
        }
        else {
            
            if(ploc == NULL) {
                insertAtFront(value);
            }
            else {
                Node *temp = new Node();
                temp->data = value;
                temp->next = ploc->next;
                ploc->next = temp;
            }
        }
    }
    
    void Delete(int value) {
        
        search(value);
        
        if(loc != NULL) {
            
            if(ploc == NULL) {
                
                first = loc->next;
                delete loc;
                loc = NULL;
            }
            else {
                
                ploc->next = loc->next;
                delete loc;
                loc = NULL;
            }
        }
        else {
            cout<<"value not found!";
        }
    }
    
    void destroyList() {
     
        Node *nn;
        while(first != NULL) {
            
            nn = first;
            first = first->next;
            delete nn;
        }
        nn = NULL;
    }
    
    void deleteOddData() {
        
        Node *temp = first;
        while (temp != NULL) {
            
            if(temp->data % 2 == 1){
                
                Delete(temp->data);
            }
            temp = temp->next;
        }
    }
    
    
    
    void makeOddEvenGroupsOfData() {
        
        Node *temp = first;
        Node *nFirst = NULL;
        first = NULL;
        Node *nn1 = NULL;
        Node *nn2 = NULL;
        
        while (temp != NULL) {
            
            if(temp->data % 2 == 1) {
                
                if(first != NULL) {
                    nn1->next = temp;
                    nn1 = temp;
                }
                else {
                    first = temp;
                    nn1 = first;
                }
                ploc = temp;
            }
            else{
                if(nFirst != NULL) {
                    nn2->next = temp;
                    nn2 = temp;
                }
                else {
                    nFirst = temp;
                    nn2 = nFirst;
                }
                loc = temp;
            }
            temp = temp->next;
        }
        
        if(first == NULL) {
            
            first = nFirst;
            loc->next = NULL;
        }
        else {
            ploc->next = nFirst;
            loc->next = NULL;
        }
       
    }
    
    void swapTwoValues(int value1, int value2) {
        
        Node *loc1;
        Node *ploc1;
        Node *temp;
        
        search(value1);
        loc1 = loc;
        ploc1 = ploc;
        search(value2);
        
        if(loc != NULL && loc1 != NULL) {
            
            if(ploc1 == NULL ) {
                //first value found at head node
                if (loc1 != ploc) {
                    
                    temp = loc->next;
                    loc->next = loc1->next;
                    first = loc;
                    ploc->next = loc1;
                    loc1->next = temp;
                }
                else if (loc1 == ploc){
                    
                    first = loc;
                    temp = loc->next;
                    loc->next = loc1;
                    loc1->next = temp;
                }
                
            }
            else if(ploc == NULL){
                 //second value found at head node
                
                if (loc != ploc1) {

                    temp = loc1->next;
                    loc1->next = loc->next;
                    first = loc1;
                    ploc1->next = loc;
                    loc->next = temp;
                    
                } else if (loc == ploc1){
                    
                    first = loc1;
                    temp = loc1->next;
                    loc1->next = loc;
                    loc->next = temp;
                }
               
            }
            else if(ploc1 != NULL && ploc != NULL && loc1 != ploc && loc != ploc1){
                temp = loc1->next;
                loc1->next = loc->next;
                ploc->next = loc1;
                ploc1->next = loc;
                loc->next = temp;
            }
            else{
                if(loc == ploc1) {
                    
                    ploc->next = loc1;
                    temp = loc1->next;
                    loc1->next = loc;
                    loc->next = temp;
                }
                else if (loc1 == ploc) {
                    
                    ploc1->next = loc;
                    temp = loc->next;
                    loc->next = loc1;
                    loc1->next = temp;
                }
            }
            
        }
        else {
            cout<<"Both values not found"<<endl;
        }
        
    }
    
    void reverseOrder() {
        
        if(first == NULL) {
            return;
        }
        
        ploc = NULL;
        Node *temp = first;
        Node *nn;
        
        while(temp != NULL) {
        
            nn = temp;
            temp = temp->next;
            nn->next = ploc;
            ploc = nn;
        }
        first = ploc;
    }
};


   


