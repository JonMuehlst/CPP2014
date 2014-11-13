#ifndef QUEUEBYSTACK_H
#define QUEUEBYSTACK_H

#include <string>
#include <stack>

using std::string;
using std::stack;

class QBS {
    
    public:
        QBS();
        ~QBS();
        void enqueue(int value);
        int dequeue();
        int first();
        string toString();
        bool isEmpty();
        size_t size();
        
    private:
        stack<int> * one;
        stack<int> * two;
        size_t sSize;
    
};

#endif