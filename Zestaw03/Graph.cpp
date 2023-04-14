#include <iostream>
#include "Graph.hpp"

auto main() -> int{
    Graph myGraph(1000);
    myGraph.addEdge(4, 5);
    myGraph.addEdge(4, 3);
    myGraph.addEdge(3, 1);
    myGraph.addEdge(4, 1);
    myGraph.addEdge(5, 7);
    myGraph.addEdge(7, 1);
    myGraph.addEdge(3, 9);
    myGraph.addEdge(9, 5);
    int * distance = myGraph.BFS(myGraph, 5);
    for(int i = 0; i < 10; i++){
        std::cout << distance[i] << std::endl;
    }
}