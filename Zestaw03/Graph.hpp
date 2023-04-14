#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "Set.hpp"
#include "LinkedList.hpp"
#include <queue>

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
    arr = other.arr;
}

Graph::~Graph(){
    delete[] arr;
}

void Graph::addEdge(int i, int j){
    arr[i].push_back(j);
    arr[j].push_back(i);
}

void Graph::removeEdge(int i, int j){
    int k = arr[i].remove(j);
    k = arr[j].remove(i);
}

bool Graph::hasEdge(int i, int j){
    if(arr[i].find(j) == -1)
        return false;
    else
        return true;
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
    return outSet;

    outSet.setUnion(inSet);
    return outSet;

}

int* Graph::BFS(const Graph& g, int s){
    int* dist = new int[g.capacity];
    bool* visited = new bool[g.capacity];
    for(int i = 0; i < g.capacity; i++){
        visited[i] = false;
        dist[i] = -1;
    }

    std::queue<int> q;
    visited[s] = true;
    dist[s] = 0;
    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        Set<int> adj = g.allConnections(u);
        for(int i = 0; i < adj.size(); i++){
            int v = adj.getElement(i);
            if(!visited[v]){
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
        }
        }
        
    }
    delete[] visited;
    return dist;
}

#endif