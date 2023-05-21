#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include "Set.hpp"
#include "LinkedList.hpp"
#include "LinkedQueue.hpp"

#define DEF_CAP 100

class Graph{
    private:
        LinkedList<int> * arr;
        int capacity;
    public:
        Graph();
        Graph(int vertNum);
        Graph(const Graph& other);
        ~Graph();
        void addEdge(int i, int j);
        void removeEdge(int i, int j);
        bool hasEdge(int i, int j);
        Set<int> inConnections(int i) const;
        Set<int> outConnections(int i) const;
        Set<int> allConnections(int i) const;
        int* BFS(const Graph& g, int s);
};


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
    delete arr;
}

void Graph::addEdge(int i, int j){
    arr[i].push_back(j);
}

void Graph::removeEdge(int i, int j){
    int k = arr[i].remove(j);
}

bool Graph::hasEdge(int i, int j){
    return (arr[i].find(j) != -1);
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
    //std::queue<int> q;
    LinkedQueue q;
    bool* visited = new bool[capacity];
    int* paths = new int[capacity];
    
    for(int i = 0; i < capacity; i++){
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