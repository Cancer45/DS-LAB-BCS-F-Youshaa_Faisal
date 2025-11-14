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

    void update_key(int index, int new_val)
    {
        heap[index] = new_val;
        heapifyUp(index);
        heapifyDown(index);
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
    my_heap.insert(4);
    my_heap.insert(3);
    my_heap.insert(5);
    my_heap.insert(1);

    my_heap.update_key(2, 9);
    my_heap.display();
}