#include <iostream>
#include "Graph.hpp"
#include "Set.hpp"

auto main() -> int{
    Graph myGraph(1000);
    myGraph.addEdge(4, 5);

    myGraph.addEdge(4, 1);

    myGraph.addEdge(4, 0);
    myGraph.addEdge(4, 2);
    myGraph.addEdge(5, 1);
    myGraph.addEdge(5, 0);
    myGraph.addEdge(0, 2);

    int * distance = myGraph.BFS(myGraph, 5);
    for(int i = 0; i < 100; i++){
        std::cout << distance[i] << std::endl;
    }

    Set<int> mySet(1000);
    mySet = myGraph.outConnections(0);
    mySet.displaySet();



}