#ifndef MQUEUE_H
#define MQUEUE_H

struct Node {
    
  int value;
  Node * next;
    
};

class MQ {
    
    public:
        MQ();
        ~MQ();
        void enqueue(int value);
        int dequeue();
        string toString();
        bool isEmpty();
        
    private:
        Node * head;
        size_t size;
    
};

#endif