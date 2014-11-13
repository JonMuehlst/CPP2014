#ifndef MSTACK_H
#define MSTACK_H

#include <string>

using std::string;

struct Node {
    
  int value;
  Node * next;
    
};

class MStack {
    
    public:
        MStack();
        ~MStack();
        void push(int value);
        int pop();
        string toString();
        bool isEmpty();
        size_t size();
        
    private:
        Node * head;
        size_t sSize;
    
};

#endif