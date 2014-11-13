#include <iostream>
#include <sstream>
#include <assert.h>
#include "QueueByStack.h"

using std::cout;
using std::stringstream;

QBS::QBS(){
    
    one = new stack<int>;
    two = new stack<int>;
    sSize = 0;
    
}

QBS::~QBS(){
    
    cout << "Queue is gone! \n";
    
}

void QBS::enqueue(int value){
    
    one->push(value);
    
    sSize++;
    
}

int QBS::dequeue(){
    
    assert(sSize > 0);
    
    if(two->empty()){
        
        while(!one->empty()){
            two->push(one->top());
            one->pop();
        }
        
        sSize--;
        int val = two->top();
        two->pop();
        return val;
        
    } else {
        sSize--;
        int val = two->top();
        two->pop();
        return val;
    }
    
}

int QBS::first(){
    
    assert(sSize > 0);
    
    if(two->empty()){
        
        while(!one->empty()){
            two->push(one->top());
            one->pop();
        }
        
        int val = two->top();
        return val;
        
    } else {
        int val = two->top();
        return val;
    }
    
}

bool QBS::isEmpty(){
    
    if( sSize != 0 ){
        return false;
    } else {
        return true;
    }
    
}

size_t QBS::size(){
    
    return sSize;
    
}