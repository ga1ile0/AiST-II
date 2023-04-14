#include <iostream>
#include "Set.hpp"

int main(){
    std::cout << std::endl << std::endl;
    Set<int> set1;
    std::cout <<"INSERT: " << std::endl;
    for(int i = 0; i < 10; i++){
        set1.insert(i);
    }
    set1.displaySet();
    
    std::cout << std::endl << "REMOVE: " << std::endl;
    set1.remove(1);
    set1.displaySet();

    std::cout << std::endl << "POP: " << std::endl;
    std::cout << "Pop1: " << set1.pop() << std::endl;
    set1.displaySet();

    std::cout << std::endl << "isMEMEBER: " << std::endl;
    if(set1.isMember(2))
        std::cout << "2 is a member of the set" << std::endl;
    else
        std::cout << "2 is not a member of the set" << std::endl;
    



    std::cout << std::endl << "########## Difference, intersection and unionSet methods ##########" << std::endl << std::endl;

    Set<int> set2;
    for(int i = 5; i < 15; ++i){
        set2.insert(i);
    }

    std::cout << "DIFFERENCE: " << std::endl;
    Set<int> difference_set;
    difference_set = set1.difference(set2);
    std::cout << "Difference-set size: " << difference_set.size() << std::endl;
    difference_set.displaySet();
    std::cout << std::endl << std::endl;

    std::cout << "INTERSECTION: " << std::endl;
    Set<int> intersection_set;
    intersection_set = set1.intersection(set2);
    std::cout << "Intersection-set size: " << intersection_set.size() << std::endl;
    intersection_set.displaySet();
    std::cout << std::endl << std::endl;


    std::cout << "UNION: " << std::endl;
    Set<int> union_set;
    union_set = set1.setUnion(set2);
    std::cout << "Union-set size: " << union_set.size() << std::endl;
    union_set.displaySet();
    std::cout << std::endl << std::endl;


    std::cout << "########## Copy constructor and operators testing ##########" << std::endl << std::endl;

    Set<int> test_set1(set1);
    std::cout << "COPY-CONSTRUCTOR: " << std::endl;
    test_set1.displaySet();
    std::cout << std::endl;

    Set<int> test_set2;
    test_set2 = set2;
    std::cout << "= OPERATOR: " << std::endl;
    test_set2.displaySet();
    std::cout << std::endl;

    std::cout << "== OPERATOR: " << std::endl;
    std::cout << "Set1: ";
    set1.displaySet();
    std::cout << "Set2: ";
    set2.displaySet();
    if(set1 == set2){
        std::cout << "The sets are equal." << std::endl;
    }else{
        std::cout << "The sets are NOT equal." << std::endl;
    }
    std::cout << std::endl;

    std::cout << "!= OPERATOR: " << std::endl;
    std::cout << "Set1: ";
    set1.displaySet();
    std::cout << "Set2: ";
    difference_set.displaySet();
    if(set1 != set2){
        std::cout << "The sets are NOT equal." << std::endl;
    }else{
        std::cout << "The sets are equal." << std::endl;
    }
    std::cout << std::endl;

}