#include <iostream>
#include "mQueue.h"

using std::cout;

int main(){
    
    MQ q = new MQ;
    
    for(int i = 10; i > 0; i--){
        q->enqueue(i);
    }
    
    cout << q->toString() << endl;
    
    while(!q->isEmpty()){
        q->dequeue();
    }
    
     q->dequeue();
     
     delete q;
    
}