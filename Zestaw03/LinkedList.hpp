#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <iostream>

using namespace std;

template<class T>
class LinkedList{
    public:

        struct Node{
            T value;
            Node* next;
            Node* prev;
        };
        
        LinkedList();
        void push_front(T x);
        T pop_front();
        void push_back(T x);
        T pop_back();
        int size();
        bool empty();
        void clear();
        int find(T x);
        T erase(int i);
        void insert(int i, T x);
        int remove(T x);
        bool replace(T x, T y);

        struct Iterator{
            Iterator(Node* ptr) : current(ptr) {}
            Node& operator*() const {return *current;}
            Node* operator->(){return current;}
            Iterator operator++(int){
                current = current->next;
                return *this;
            }
            friend bool operator==(const Iterator& a, const Iterator& b) {return a.current == b.current;};
            friend bool operator!=(const Iterator& a, const Iterator& b){return a.current != b.current;};
            private:
                Node* current;
        };

        Iterator begin(){
            return Iterator(guard->next);
        }

        Iterator end(){
            return Iterator(guard);
        }
        
    private:
        int count;
        Node* guard;
};

template<class T>
LinkedList<T>::LinkedList(){
    guard = new Node();
    guard->next = guard;
    guard->prev = guard;
    count = 0;
}


template<class T>
void LinkedList<T>::push_front(T x){ //wstawianie nowego elementu da początek listy
    Node *temp = new Node();
    temp->prev = guard; //przypinamy prev nowego elementu do guarda
    temp->next = guard->next; //przypinamy next nowego elementu do poprzedniego 'pierwszego' elementu
    guard->next->prev = temp; //przypinamy prev poprzedniego 'pierwszego' elementu na nowy element
    guard->next = temp;
    temp->value = x;
    count++;
}

template<class T>
T LinkedList<T>::pop_front(){ //usuwanie elementu z początku listy
    if(empty()){
        throw std::out_of_range("EMPTY");
    }
    else{
        T x = guard->next->value; 
        Node *temp = new Node(); 
        temp = guard->next;
        guard->next=temp->next; 
        temp->next->prev = guard; 
        delete temp;
        count--;
        return x;
    }
}

template<class T>
void LinkedList<T>::push_back(T x){ //wstawianie nowego elementu na koniec listy
    Node *temp = new Node();
    temp->value = x;
    temp->next = guard; //przypinamy next nowego elementu na guarda
    temp->prev=guard->prev; // przypinamy prev nowego elementu na poprzedni 'ostatni' element
    guard->prev->next = temp; //przepinamy next poprzedniego 'ostatniego' elementu na nowy element
    guard->prev = temp; 
    count ++;
}

template<class T>
T LinkedList<T>::pop_back(){ //usuwanie elementu z konca listy
    if(empty()){
        throw std::out_of_range("EMPTY");
    }
    else{
        T x = guard->prev->value;
        Node *temp = guard->prev;
        guard->prev = temp->prev;
        temp->prev->next = guard;

        delete temp;
        count--;
        return x;
    }
}

template<class T>
int LinkedList<T>::size(){
    return count;
}

template<class T>
bool LinkedList<T>::empty(){
    return (count == 0);
}

template<class T>
void LinkedList<T>::clear(){ //czyści listę
    while(count == 0){
        pop_front();
    }
}

template<class T>
int LinkedList<T>::find(T x){ //znajdzuje element o wartości x i zwraca jego pozycje

    Node *temp = guard;
    for(int i = 0; i < count ; i++){ 
        temp=temp->next; //przechodzimy po liscie
        if(temp->value == x){ //porównujemy wartości z x
            return i;
        }
    }
    return -1;

    
}

template<class T>
T LinkedList<T>::erase(int i){ // usuwa i zwraca element na pozycji i
    Node *temp = new Node();
    temp = guard->next;
    for(int a = 0; a < i; ++a){
        temp = temp->next; //przechodzimy po liscie aż do i
    }
    temp->prev->next = temp->next;//przepinamy next elementu i-1 na element i+1
    temp->next->prev = temp->prev;//przepinamy prev elementu i+1 na element i-1
    T x = temp->value;
    delete temp;
    count--;
    return x;

}

template<class T>
void LinkedList<T>::insert(int i, T x){ //wstawia x przed element o indeksie i
    Node* iterator = new Node(); //node do przejscia po liscie
    iterator = guard;
    Node* new_Node = new Node(); //node ktory wstawiam
    new_Node->value = x;

    for(int j = 0; j < i; j++){ //przechodzimy po liscie az do elementu i-1
        iterator = iterator->next;
    }
    new_Node->next = iterator->next; //przypinamy nexta nowego elementu na element i
    new_Node->prev = iterator; //przypinamy prev nowego elementu na element i-1
    iterator->next->prev = new_Node; //przepinamy prev elementu i na element i-1
    iterator->next = new_Node; 
    count++;
}

template<class T>
int LinkedList<T>::remove(T x){ //usuwa wystąpienia x i zwraca ich liczbę
    int counter = 0;
    Node *temp = new Node();
    temp = guard;;
    while(temp->next != guard){
        if(temp->next->value == x){
            delete temp;
            counter++;
            count--;
        }
        else{
            temp = temp->next;
        }
    }
    return counter;
}

template<class T>
bool LinkedList<T>::replace(T x, T y){ //wstawia x w miejsce pierwszego elementu o wartosci y

    Node* temp = guard;
    for(int i = 0; i< count ; ++i){
        temp=temp->next;
        if(temp->value == x){
            erase(i);
            insert(i, y);
            return true;
        }
    }
    return false;
    
}


#endif







