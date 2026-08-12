#include <iostream>
#include <queue> // Required header

int main() {
    // Creates a max heap by default
    std::priority_queue<int> maxHeap;

    // Insert elements
    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(20);

    // Get the maximum element (Root)
    std::cout << "Top element: " << maxHeap.top() << std::endl; // Output: 30

    // Remove the maximum element
    maxHeap.pop();

    std::cout << "New top element: " << maxHeap.top() << std::endl; // Output: 20
    return 0;
}
