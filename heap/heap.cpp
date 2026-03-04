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
};

