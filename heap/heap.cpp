#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class MaxHeap {
private:
    int heap[101];
    int size;

public:
    MaxHeap() {
        size = 0;
    }

    bool isFull() {
        return size == 100;
    }
    bool isEmpty() {
        return size == 0;
    }


    void insert(int value) {
        if (isFull()) {//returns if array size reached
            cout << "Heap is full.\n";
            return;
        }

        size++;
        heap[size] = value;

        // Heapify up
        int current = size;
        while (current > 1 && heap[current] > heap[current / 2]) {//swaps child with parent until sorted
            swap(heap[current], heap[current / 2]);
            current = current / 2;
        }
    }
    void remove() {//remoes largest element
        if (isEmpty()) {
            cout << "Heap is empty.\n";
            return;
        }

        cout << heap[1] << endl; // output largest

        heap[1] = heap[size];//sets head as the last element
        size--;

        // heapify down
        int current = 1;//starts at top

        while (true) {
            int left = current * 2;        // left child index
            int right = current * 2 + 1;   // right child index
            int largest = current;         // assume current is largest

            // check if left child exists AND is larger
            if (left <= size && heap[left] > heap[largest]) {
                largest = left;
            }

            // check if right child exists AND is larger
            if (right <= size && heap[right] > heap[largest]) {
                largest = right;
            }

            // if one of the children is larger, swap
            if (largest != current) {
                swap(heap[current], heap[largest]);

                //move down to the child we swapped with
                current = largest;
            }
            else {
                //if current is larger than both children, stop
                break;
            }
        }
    }

    // remove all elements
    void removeAll() {
        while (!isEmpty()) {
            remove();
        }
    }
    // prints the entire heap as a sideways tree
    void printTree() {
        // start displaying from the root at index 1 with depth 0
        display(1, 0);
    }

// recursive function to display the heap
    void display(int index, int depth) {
        // if index is outside current heap size, stop
        if (index > size)
            return;

        // first display the right child
        // this makes the tree appear sideways
        display(index * 2 + 1, depth + 1);

        // deeper levels are indented further
        for (int i = 0; i < depth; i++) {
            cout << "\t";
        }

        // print the current node value
        cout << heap[index] << endl;

        // then display the left child
        display(index * 2, depth + 1);
    }
};

