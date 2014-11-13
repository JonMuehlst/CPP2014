#include <iostream>
#include <sstream>
#include "mStack.h"

using std::cout;
using std::stringstream;

MStack::MStack(){
    
    head = NULL;    
    sSize = 0;
    
}

MStack::~MStack(){
    
    cout << "Stack is gone! \n";
    
}

void MStack::push(int value){
    
    if(head == NULL){
        head = new Node;
        head->value = value;
        head->next = NULL;
    } else {
        Node * tmp;
        tmp = new Node;
        tmp->value = value;
        tmp->next = head;
        head = tmp;
    }
    
    sSize++;
    
}

int MStack::pop(){
    
    if(head == NULL){
        cout << "The stack is empty! \n";
    } else {
        Node * tmp = head;
        int value = head->value;
        head = head->next;
        delete tmp;
        sSize--;
    }
    
}

string MStack::toString(){
    
    string ans = "";
    Node * tmp = head;
    
    while(tmp != NULL){
        stringstream ss;
        ss << tmp->value;
        string s = ss.str();
        ans += "" + s + ", "; 
        tmp = tmp->next;
    }
    
    return ans;
}

bool MStack::isEmpty(){
    
    if(head){
        return false;
    } else {
        return true;
    }
    
}

size_t MStack::size(){
    
    return sSize;
    
}