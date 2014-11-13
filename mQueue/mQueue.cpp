#include <iostream>
#include <string>

using std::cout;

MQ::MQ(){
    
    head = NULL;    
    size = 0;
    
}

MQ::~MQ(){
    
    cout << "Queue is gone! \n";
    
}


void MQ::enqueue(int value){
    
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
    
    size++;
    
}

int MQ::dequeue(){
    
    if(head == NULL){
        cout << "The queue is empty! \n";
    } else {
        Node * tmp = head;
        int value = tmp->value;
        head->next = head->next->next;
        delete tmp;
        size--;
    }
    
}

string MQ::toString(){
    
    string ans = "";
    Node * tmp = head;
    
    while(tmp){
        ans += "" + tmp->value + ", ";    
    }
    
    return ans;
}

bool MQ::isEmpty(){
    
    if(head){
        return true;
    } else {
        return false;
    }
    
}