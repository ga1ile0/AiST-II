#include <iostream>
#include "Queue.hpp"

auto main() -> int{
    std::cout <<"METHODS TESTING: " << std::endl;
    Queue<int> queue1(1000);
    queue1.insert(1, 3);
    queue1.insert(2, 2);
    queue1.insert(4, 1);
    queue1.insert(5, 21);
    queue1.insert(7, 9);
    queue1.insert(4, 21);
    queue1.insert(6, 9);
  
    queue1.display();
    QueueElem<int> elem1 = queue1.extractMax();
    queue1.display();
    elem1 = queue1.extractMax();
    queue1.display();

    std::cout << std::endl;

    std::cout <<"COPY CONSTRUCTOR:" << std::endl;
    std::cout << "Queue1: ";
    queue1.display();
    Queue<int> copy_queue(queue1);
    std::cout << "Queue2 (copy-constructor): ";
    copy_queue.display();

    std::cout << std::endl;

    std::cout << "OPERATOR TESTING: " << std::endl;
    std::cout << "## =operator" << std::endl;
    std::cout << "Queue1: ";
    queue1.display();
    Queue<int> queue2;
    queue2 = queue1;
    std::cout << "Queue2: ";
    queue2.display();

    std::cout << std::endl;

    std::cout << "## ==operator" << std::endl;
    std::cout << "Queue1: ";
    queue1.display();
    std::cout << "Queue2: ";
    queue2.display();
    if(queue1 == queue2)
        std::cout << "Queues are the same!" << std::endl;
    else
        std::cout << "Queues are NOT the same!" << std::endl;
    
    std::cout << std::endl;

    std::cout << "## != operator" << std::endl;
    std::cout << "Queue1: ";
    queue1.display();
    std::cout << "Queue2: ";
    queue2.display();
    if(queue1 != queue2)
        std::cout << "Queues are NOT the same!" << std::endl;
    else
        std::cout << "Queues are the same!" << std::endl;

    QueueElem<int> test_elem = queue1.extractMax();
    queue1.display();
}