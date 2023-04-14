#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

class LinkedQueue{
    private:
        Node *front;
        Node *rear;
        int n;
    public:
        LinkedQueue();
        int size();
        void push(int x);
        int pop();
        int frontEl();
        bool empty();

};

LinkedQueue::LinkedQueue(){
    front = NULL;
    rear = NULL;
    n = 0;
}

bool LinkedQueue::empty(){
    return (n == 0);
}

void LinkedQueue::push(int x){
    Node *ptr = new Node();
    ptr->data = x;
    ptr->next = NULL;
    if(empty()){
        front = ptr;
        rear = ptr;
    }
    else{
        rear->next = ptr;
        rear = ptr;
    }
    n++;
}

int LinkedQueue::pop(){
    if(empty()){
        throw std::out_of_range("EMPTY");
        return -1;
    }
    else{
        int x = front->data;
        front = front->next;
        n--;
        return x;
    }

}

int LinkedQueue::frontEl(){
    return front->data;
}

int LinkedQueue::size(){
    return n;
}

#endif