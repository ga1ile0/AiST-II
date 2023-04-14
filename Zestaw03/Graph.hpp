#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "Set.hpp"
#include "LinkedList.hpp"
#include "LinkedQueue.hpp"
#include <queue>

#define DEF_CAP 100

class Graph{
    private:
        LinkedList<int> * arr;
        int capacity;
        int _size;
        void resize(int newCapacity);
    public:
        Graph();
        Graph(int vertNum);
        Graph(const Graph& other);
        ~Graph();
        void addEdge(int i, int j);
        void removeEdge(int i, int j);
        bool hasEdge(int i, int j);
        int size() const;
        Set<int> inConnections(int i) const;
        Set<int> outConnections(int i) const;
        Set<int> allConnections(int i) const;
        int* BFS(const Graph& g, int s);
};

void Graph::resize(int newCapacity){
    capacity = newCapacity;
    LinkedList<int> * newArr;
    newArr = new LinkedList<int>[newCapacity];
    for(int i = 0; i < _size; i++){
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;

}

Graph::Graph(){
    capacity = DEF_CAP;
    arr = new LinkedList<int>[capacity];
}

Graph::Graph(int vertNum){
    capacity = vertNum;
    arr = new LinkedList<int>[capacity];
}

Graph::Graph(const Graph& other){
    capacity = other.capacity;
    arr = new LinkedList<int>[capacity];
    for(int i = 0; i < capacity; i++){
        arr[i] = other.arr[i];
    }
}

Graph::~Graph(){
    delete[] arr;
}

void Graph::addEdge(int i, int j){
    if(arr[i].empty())
        _size++;
    if(arr[j].empty())
        _size++;
    if(_size >= capacity){
        resize(capacity*2);
    }
    arr[i].push_back(j);
    arr[j].push_back(i);
}

void Graph::removeEdge(int i, int j){
    int k = arr[i].remove(j);
    k = arr[j].remove(i);
    if(arr[i].empty())
        _size--;
    if(arr[j].empty())
        _size--;
    if(_size <= capacity/4)
        resize(capacity/2);
}

bool Graph::hasEdge(int i, int j){
    return (arr[i].find(j) != -1);
}

int Graph::size() const {
    return _size;
}

Set<int> Graph::inConnections(int i) const { //wszystkie wierzchołki od których wychodzą krawędzie do i
    Set<int> outSet(capacity);
    for(int j = 0; j < capacity; j++){
        if(arr[j].find(i) != -1){
            outSet.insert(j);
        }
    }
    return outSet;
}

Set<int> Graph::outConnections(int i) const { //wszystkie wierzchołki do których wychodzą krawędzie z i
    Set<int> outSet(capacity);
    for(LinkedList<int>::Iterator it = arr[i].begin(); it != arr[i].end(); it++){
        outSet.insert(it->value);
    }
    return outSet;
}

Set<int> Graph::allConnections(int i) const { //suma dwóch poprzednich;
    Set<int> inSet(capacity);
    for(int j = 0; j < capacity; j++){
        if(arr[j].find(i) != -1){
            inSet.insert(j);
        }
    }
    
    Set<int> outSet(capacity);
    for(LinkedList<int>::Iterator it = arr[i].begin(); it != arr[i].end(); it++){
        outSet.insert(it->value);
    }
    

    outSet.setUnion(inSet);
    return outSet;

}

int* Graph::BFS(const Graph& g, int s){
    int gSize = g.size();
    //std::queue<int> q;
    LinkedQueue q;
    bool* visited = new bool[gSize];
    int* paths = new int[gSize];

    
    for(int i = 0; i < gSize; i++){
        visited[i] = false;
        paths[i] = -1;
    }

    visited[s] = true;
    paths[s] = 0;
    q.push(s);

    while(!q.empty()){
        int frontEl = q.frontEl();
        q.pop();
        Set<int> adj = g.outConnections(frontEl);

        for(int i = 0; i < adj.size(); i++){
            int v = adj.getElement(i);
            if(!visited[v]){
                visited[v] = true;
                paths[v] = paths[frontEl] + 1;
                q.push(v);
            }
        }
    }

    delete[] visited;
    return paths;

}

#endif