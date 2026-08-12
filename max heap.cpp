#include <iostream>
using namespace std;

class MaxHeap {
    int arr[100];
    int size;

public:
    MaxHeap() {
        size = 0;
    }

    // Insert an element
    void insert(int value) {
        int i = size;
        arr[size] = value;
        size++;

        // Move the element upward
        while (i > 0) {
            int parent = (i - 1) / 2;

            if (arr[parent] >= arr[i])
                break;

            // Swap parent and child
            int temp = arr[parent];
            arr[parent] = arr[i];
            arr[i] = temp;

            i = parent;
        }
    }

    // Delete maximum element
    void deleteMax() {
        if (size == 0) {
            cout << "Heap is empty\n";
            return;
        }

        arr[0] = arr[size - 1];
        size--;

        // Move the root downward
        int i = 0;

        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < size && arr[left] > arr[largest])
                largest = left;

            if (right < size && arr[right] > arr[largest])
                largest = right;

            if (largest == i)
                break;

            // Swap
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            i = largest;
        }
    }

    // Display heap
    void display() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main() {
    MaxHeap h;

    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(10);
    h.insert(20);
    h.insert(60);

    cout << "Max Heap: ";
    h.display();

    h.deleteMax();

    cout << "After deleting maximum: ";
    h.display();

    return 0;
}
