#include <iostream>
#include <algorithm>
#include <vector>

class PriorityQueue {
public:
    // Constructor to initialize the min heap
    PriorityQueue(int capacity) {
        heap.resize(capacity);
        size = 0;
    }

    // Function to insert an element into the min heap
    void push(int value) {
        // Add the new element to the end of the heap
        heap[size] = value;

        // Heapify the new element to maintain the min heap property
        int current = size;
        int parent = (current - 1) / 2;
        while (current > 0 && heap[current] < heap[parent]) {
            std::swap(heap[current], heap[parent]);
            current = parent;
            parent = (current - 1) / 2;
        }

        size++;
    }

    // Function to remove the minimum element (root) from the min heap
    int pop() {
        // Store the root element to be returned later
        int root = heap[0];

        // Replace the root with the last element in the heap
        heap[0] = heap[size - 1];
        size--;

        // Heapify the root element to maintain the min heap property
        int current = 0;
        int leftChild = 2 * current + 1;
        int rightChild = 2 * current + 2;
        while (leftChild < size) {
            int minIndex = current;
            if (heap[minIndex] > heap[leftChild]) {
                minIndex = leftChild;
            }
            if (rightChild < size && heap[minIndex] > heap[rightChild]) {
                minIndex = rightChild;
            }
            if (minIndex == current) {
                break;
            }
            std::swap(heap[current], heap[minIndex]);
            current = minIndex;
            leftChild = 2 * current + 1;
            rightChild = 2 * current + 2;
        }

        return root;
    }

private:
    // The heap is stored in an array
    std::vector<int> heap;
    int size;
};

int main() {
    PriorityQueue pq(5); // Create a min heap with capacity 5

    // Insert some elements into the min heap
    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(15);
    pq.push(30);

    // Remove and print the minimum element from the min heap
    std::cout << pq.pop() << std::endl; // Output: 5
    std::cout << pq.pop() << std::endl; // Output: 10
    std::cout << pq.pop() << std::endl; // Output: 15

    return 0;
}
