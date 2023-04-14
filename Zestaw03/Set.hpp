#ifndef SET_HPP
#define SET_HPP
#include <iostream>

#define DEF_CAP 100

template<class T>
class Set {
    private:
        T * array;
        int _size;
        int capacity;
        int findIndex(T x){ //binary search for finding the index of x in the array
            int l = 0, r = _size - 1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (array[m] == x) {
                    return m;
                } else if (array[m] < x) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            return -1;
        }

        void resize(int newCapacity){
            T * newArray = new T[newCapacity];
            for(int i = 0; i < _size; i++){
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
            capacity = newCapacity;
            
        }

        
        

    public:

       

        //constructors and destructor
        Set(){
            _size = 0;
            array = new T[DEF_CAP];
            capacity = DEF_CAP;
            for(int i = 0; i < DEF_CAP; i++){
                array[i] = T();
            }
        }

        Set(const int arraySize){
            _size = 0;
            array = new T[arraySize];
            capacity = arraySize;
            for(int i = 0; i < arraySize; i++){
                array[i] = T();
            }
        }

        ~Set(){
            delete[] array;
        }

        Set(const Set<T> &other) {
            _size = other._size;
            capacity = other.capacity;
            array = new T[capacity];
            for (int i = 0; i < _size; i++) {
                array[i] = other.array[i];
            }
        }

        //operators
        Set<T>& operator=(const Set<T> &other) {
            if (this != &other) {
                delete[] array;
                _size = other._size;
                capacity = other.capacity;
                array = new T[capacity];
                for (int i = 0; i < _size; i++) {
                    array[i] = other.array[i];
                }
            }
            return *this;
        }

        bool operator==(const Set<T> &other) const {
            if (_size != other._size) {
                return false;
            }
            for (int i = 0; i < _size; i++) {
                if (array[i] != other.array[i]) {
                    return false;
                }
            }
            return true;
        }

        bool operator!=(const Set<T> &other) const{
            return !(*this == other);
        }

        //methods
        void insert(T x){
            if (findIndex(x) != -1) {
                throw std::out_of_range("underflow");
            }
            if (_size + 1 == capacity) {
                resize(capacity * 2);
            }
            int index = 0;
            while (index < _size && array[index] < x) {
                index++;
            }
            for (int i = _size - 1; i >= index; i--) {
                array[i+1] = array[i];
            }
            array[index] = x;
            _size++;
        }

        bool isMember(T x){
            return (findIndex(x) != -1);
        }

        bool remove(T x){
            int index = findIndex(x);
            if(index == -1)
                return false;
            for(int i = index; i < _size + 1; ++i){
                array[i] = array[i+1];
            }
            _size--;
            if((_size*4) <= capacity){
                resize(capacity/2);
            }
            return true;
        }

        T pop(){
            T result = array[_size - 1];
            _size--;
            if((_size*4) <= capacity){
                resize(capacity/2);
            }
            return result;
        }

        int size() const {
            return _size;
        }

        T getElement(int index) const {
            if(index >= _size)
                throw std::out_of_range("index out of range");
            return array[index];
        }


        Set<T> intersection(const Set<T> &other){
            Set<T> temp_set = *this;
            Set<T> result;
            int i = 0, j = 0;
            while(i < _size && j < other.size()){
                if(temp_set.getElement(i) == other.getElement(j)){
                    result.insert(temp_set.getElement(i));
                    i++; j++;
                }
                else if(temp_set.getElement(i) < other.getElement(j)){
                    i++;
                }
                else{
                    j++;
                }
            }
            return result;
        }
        
        Set<T> difference(const Set<T> &other){
            Set<T> temp_set = *this;
            Set<T> result;
            int i = 0, j = 0;
            while(i < _size && j < other.size()){
                if(temp_set.getElement(i) == other.getElement(j)){
                    i++; j++;
                }
                else if(temp_set.getElement(i) < other.getElement(j)){
                    result.insert(temp_set.getElement(i));
                    i++;
                }
                else{
                    j++;
                }
            }
            while(i < _size){
                result.insert(temp_set.getElement(i));
                i++;
            }
            return result;
        }

        Set<T> setUnion(const Set<T> &other){
            Set<T> temp_set = *this;
            Set<T> result;
            int i = 0, j = 0;
            while(i < _size && j < other.size()){
                if(temp_set.getElement(i) == other.getElement(j)){
                    result.insert(temp_set.getElement(i));
                    i++; j++;
                }
                else if(temp_set.getElement(i) < other.getElement(j)){
                    result.insert(temp_set.getElement(i));
                    i++;
                }
                else{
                    result.insert(other.getElement(j));
                    j++;
                }
            }
            while(i < _size){
                result.insert(temp_set.getElement(i));
                i++;
            }
            while(j < other.size()){
                result.insert(other.getElement(j));
                j++;
            }
            return result;
            
        }

        //displays the elements of the set (for testing)
        void displaySet(){
            for(int i = 0; i < _size ; i++){
                std::cout << "--" << array[i];
            }
            std::cout << std::endl;
        }
};
#endif


