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
    myGraph.addEdge(2,3);
    int * distance = myGraph.BFS(myGraph, 5);
    for(int i = 0; i < myGraph.size(); i++){
        std::cout << distance[i] << std::endl;
    }
    Set<int> mySet(1000);
    mySet = myGraph.outConnections(4);
    mySet.displaySet();

    if(myGraph.hasEdge(0,5))
        std::cout << "Yeah" << std::endl;
    myGraph.removeEdge(0, 5);
    if(myGraph.hasEdge(0,5))
        std::cout << "Yeah2" << std::endl;
}