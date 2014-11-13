#include <iostream>
#include <sstream>
#include "mQueue.h"

using std::cout;
using std::stringstream;

MQ::MQ(){
    
    head = NULL;    
    sSize = 0;
    
}

MQ::~MQ(){
    
    cout << "Queue is gone! \n";
    
}

void MQ::enqueue(int value){
    
    if(head == NULL){
        head = new Node;
        head->value = value;
        head->next = NULL;
    } else if(tail == NULL){
        tail = new Node;
        tail->value = value;
        tail->next = NULL;
        head->next = tail;
    } else {
        Node * tmp;
        tmp = new Node;
        tmp->value = value;
        tmp->next = NULL;
        tail->next = tmp;
        tail = tmp;
    }
    
    sSize++;
    
}

int MQ::dequeue(){
    
    if(head == NULL){
        cout << "The queue is empty! \n";
    } else {
        Node * tmp = head;
        int value = head->value;
        head = head->next;
        delete tmp;
        sSize--;
    }
    
}

string MQ::toString(){
    
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

bool MQ::isEmpty(){
    
    if(head){
        return false;
    } else {
        return true;
    }
    
}

size_t MQ::size(){
    
    return sSize;
    
}