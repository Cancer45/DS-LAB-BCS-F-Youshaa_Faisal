#include <iostream>

void swap(int& num1, int& num2)
{
    int tmp = num1;
    num1 = num2;
    num2 = tmp;
}

class maxHeap
{
    int heap[100];
    int size;

    public:
    maxHeap() : size(-1) {}

    void insert(int val)
    {
        if (size >= 100)
        {
            std::cout << "Heap Overflow\n";
            return;
        }

        heap[++size] = val;
        heapifyUp(size);
    }

    void deleteRoot()
    {
        if (size < 0)
        {
            std::cout << "Heap Underflow\n";
            return;
        }
        swap(heap[0], heap[size--]);
        heapifyDown(heap[0]);
    }

    int left(int index)
    {
        return 2 * (index) + 1;
    }

    int right(int index)
    {
        return 2 * (index) + 2;
    }

    int parent(int index)
    {
        return (index - 1) / 2;
    }

    void heapifyUp(int index)
    {
        while(index != 0 && heap[index] > heap[parent(index)])
        {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index)
    {
        int largest = index;
        int l = left(index);
        int r = right(index);
    
        if (l < size && heap[l] > heap[largest])
        largest = l;
        if (r < size && heap[r] > heap[largest])
        largest = r;

        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    bool checkMaxHeap()
    {
        for (int i = 0; i < (size - 2) / 2; i++)
        {
            int l = left(i);
            int r = right(i);

            if(l < size && heap[i] < heap[l])
            return false;

            if (r < size && heap[i] < heap[r])
            return false;
        }

        return true;
    }

    void display()
    {
        for (int i = 0; i <= size; i++)
        std::cout << heap[i] << std::endl;
    }
};

int main()
{
    maxHeap my_heap;
}