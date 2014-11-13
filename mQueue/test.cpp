#include <iostream>
#include "mQueue.h"

using std::cout;

int main(){
    
    MQ * q = new MQ;
    
    for(int i = 1; i < 11; i++){
        q->enqueue(i);
        cout << q->toString() << std::endl;
        cout << "Size: " << q->size() << std::endl;
    }
    
    cout << q->toString() << std::endl;
    
    while(!q->isEmpty()){
        cout << q->toString() << std::endl;
        cout << "Size: " << q->size() << std::endl;
        q->dequeue();
       
    }
    
     q->dequeue();
     
     delete q;
    
}