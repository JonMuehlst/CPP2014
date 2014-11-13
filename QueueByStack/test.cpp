#include <iostream>
#include "QueueByStack.h"

using std::cout;

int main(){
    
    QBS * q = new QBS;
    
    for(int i = 1; i < 11; i++){
        q->enqueue(i);
    }
    
    while(q->size() > 5){
        cout << q->first() << ", ";       
        cout << "Size: " << q->size() << std::endl;
        q->dequeue();
       
    }
    
    for(int i = 11; i < 21; i++){
        q->enqueue(i);
    }
    
    
    while(!q->isEmpty()){
        cout << q->first() << ", ";       
        cout << "Size: " << q->size() << std::endl;
        q->dequeue();
       
    }
    
     cout << "Size: " << q->size() << std::endl;
    //  q->dequeue();
     
     delete q;
    
}