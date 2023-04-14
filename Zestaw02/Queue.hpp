#ifndef QUEUE_HPP
#define QUEUE_HPP

#define DEF_CAP 100

template<typename U>
struct QueueElem{
    U data;
    int priority;
};


template<class T>
class Queue{
    private:
        QueueElem<T> * arr;
        int _size;
        int capacity;
        void resize(int newCapacity);
    public:
        Queue();
        Queue(int capacity_);
        Queue(const Queue<T> &other);
        Queue<T>& operator=(const Queue<T> &other);
        bool operator==(const Queue<T> &other) const;
        bool operator!=(const Queue<T> &other) const;
        void insert(T x, int k);
        QueueElem<T> max();
        QueueElem<T> extractMax();
        int size() const;
        void display() const;
};

template<class T>
void Queue<T>::resize(int newCapacity){
    QueueElem<T> * newArr = new QueueElem<T>[newCapacity];
    for(int i = 0; i < _size; i++){
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}

template<class T>
Queue<T>::Queue(){
    arr = new QueueElem<T>[DEF_CAP];
    _size = 0;
}

template<class T>
Queue<T>::Queue(int capacity_){
    capacity = capacity_;
    _size = 0;
    arr = new QueueElem<T>[capacity_];
}

template<class T>
Queue<T>::Queue(const Queue<T> &other){
    if(this != &other){
        delete[] arr;
        _size = other._size;
        capacity = other.capacity;
        arr = new QueueElem<T>[capacity];
        for(int i = 0; i < _size; i++){
            arr[i] = other.arr[i];
        }
    }
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T> &other){
    if(this != &other){
        delete[] arr;
        _size = other._size;
        capacity = other.capacity;
        arr = new QueueElem<T>[capacity];
        for(int i = 0; i < _size; i++){
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template<class T>
bool Queue<T>::operator==(const Queue<T> &other) const {
    if(_size != other._size)
        return false;
    for(int i = 0; i < _size; ++i){
        if(arr[i].data != other.arr[i].data || arr[i].priority != other.arr[i].priority)
            return false;
    }
    return true;
    
}

template<class T>
bool Queue<T>::operator!=(const Queue<T> &other) const {
    return !(*this == other);
}

template<class T>
void Queue<T>::insert(T x, int k){
    //check for resize
    if((_size + 1) >= capacity){
        std::cout << "huh?" << std::endl;
        resize(2*capacity);
    }
    arr[_size].data = x;
    arr[_size].priority = k;
    int child = _size - 1;
    int parent = (child - 1) / 2;
    //heapify up
    while(child > 0 && arr[child].priority > arr[parent].priority){
        std::swap(arr[child], arr[parent]);
        child = parent;
        parent = (child - 1) / 2;
    }
    _size++;
}

template<class T>
QueueElem<T> Queue<T>::max(){
    return arr[0];
}

template<class T>
QueueElem<T> Queue<T>::extractMax(){
    if(_size == 0){
        throw std::out_of_range("the queue is empty.");
    }
    //check for resize
    if((_size+1)*4 <= capacity){
        resize(capacity/2);
    }
    QueueElem<T> temp = arr[0];
    arr[0] = arr[_size - 1];
    //heapify down
    int parent = 0;
    int leftChild = 1;
    while(leftChild < _size){
        int rightChild = leftChild + 1;
        int maxChild = (rightChild < _size && arr[rightChild].priority > arr[leftChild].priority) ? rightChild : leftChild;
        if(arr[maxChild].priority <= arr[parent].priority){
            break;
        }
        std::swap(arr[maxChild], arr[parent]);
        parent = maxChild;
        leftChild = 2*parent + 1;
    }
    _size--;
    return temp;
}

template<class T>
int Queue<T>::size() const {
    return _size;
}

template<class T>
void Queue<T>::display() const {
    for(int i = 0; i < _size; ++i){
        std::cout << "--" <<  "[" << arr[i].data << ":" << arr[i].priority << "]";
    }
    std::cout << std::endl;
}
#endif


