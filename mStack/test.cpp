#include <iostream>
#include "mStack.h"

using std::cout;

int main(){
    
    MStack * s = new MStack;
    
    for(int i = 1; i < 11; i++){
        s->push(i);
        cout << s->toString() << std::endl;
        cout << "Size: " << s->size() << std::endl;
    }
    
    cout << s->toString() << std::endl;
    
    while(!s->isEmpty()){
        cout << s->toString() << std::endl;
        cout << "Size: " << s->size() << std::endl;
        s->pop();
       
    }
    
     s->pop();
     
     delete s;
    
}