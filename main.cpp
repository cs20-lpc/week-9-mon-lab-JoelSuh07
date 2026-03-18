#include <iostream>
#include <string>
#include "LinkedQueue.hpp"

int main() {
    try {
        LinkedQueue<int> q;

        std::cout << "--- Testing Enqueue and Front/Back ---" << std::endl;
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        std::cout << "Length: " << q.getLength() << " (Expected: 3)" << std::endl;
        std::cout << "Front: " << q.front() << " (Expected: 10)" << std::endl;
        std::cout << "Back: " << q.back() << " (Expected: 30)" << std::endl;

        std::cout << "\n--- Testing Dequeue ---" << std::endl;
        q.dequeue();
        std::cout << "Front after 1 dequeue: " << q.front() << " (Expected: 20)" << std::endl;
        std::cout << "Length: " << q.getLength() << " (Expected: 2)" << std::endl;

        std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
        LinkedQueue<int> qCopy(q);
        std::cout << "Copy Front: " << qCopy.front() << " (Expected: 20)" << std::endl;
        std::cout << "Copy Back: " << qCopy.back() << " (Expected: 30)" << std::endl;

        std::cout << "\n--- Testing Assignment Operator ---" << std::endl;
        LinkedQueue<int> qAssign;
        qAssign.enqueue(100);
        qAssign = q;
        std::cout << "Assigned Front: " << qAssign.front() << " (Expected: 20)" << std::endl;
        qAssign.enqueue(40);
        std::cout << "Assigned Back after enqueue: " << qAssign.back() << " (Expected: 40)" << std::endl;
        std::cout << "Original Back (should be unchanged): " << q.back() << " (Expected: 30)" << std::endl;

        std::cout << "\n--- Testing Clear ---" << std::endl;
        q.clear();
        std::cout << "Is empty after clear: " << (q.isEmpty() ? "Yes" : "No") << " (Expected: Yes)" << std::endl;

        std::cout << "\n--- Testing Exception Handling ---" << std::endl;
        try {
            q.dequeue();
        } catch (const std::string& e) {
            std::cout << "Caught expected exception: " << e << std::endl;
        }

    } catch (const std::string& e) {
        std::cerr << "Unexpected Error: " << e << std::endl;
    }

    // Testing with strings
    std::cout << "\n--- Testing with Strings ---" << std::endl;
    LinkedQueue<std::string> userQueue;
    std::string userInput;
    
    std::cout << "Enter 3 strings to add to the queue:" << std::endl;
    for(int i = 0; i < 3; ++i) {
        std::cout << "Item " << i+1 << ": ";
        std::cin >> userInput;
        userQueue.enqueue(userInput);
    }

    std::cout << "\nQueue status:" << std::endl;
    std::cout << "Length: " << userQueue.getLength() << std::endl;
    std::cout << "Front: " << userQueue.front() << std::endl;
    std::cout << "Back: " << userQueue.back() << std::endl;

    userQueue.dequeue();
    std::cout << "Front after one dequeue: " << userQueue.front() << std::endl;

    return 0;
}