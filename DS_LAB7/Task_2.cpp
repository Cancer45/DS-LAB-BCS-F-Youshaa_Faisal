#include <iostream>
#include <vector>

class IntNode
{
	public:
	int value;
	IntNode* next = nullptr;

    IntNode() {}
    IntNode(int value) : value(value) {}
};

class List
{
    public:
    IntNode* head = nullptr;
    IntNode* tail = nullptr;

    void addToTail(int value)
    {
        IntNode* new_node = new IntNode(value);

        if (!head)
        head = new_node;

        else
        tail->next = new_node;

        tail = new_node;
    }

    void addToHead(int value)
    {
        IntNode* new_node = new IntNode(value);
        
        new_node->next = head;
        head = new_node;
    }

    IntNode* deleteFromHead()
    {
        if (!head)
        return nullptr;

        IntNode* tmp = head;
        head = head->next;

        delete tmp;
        return head;
    }
};

int intLength(int input)
{
    int i = 1;
    while(input >= 10)
    {
        input /= 10;
        i++;
    }

    return i;
}

int getNthDigit(int num, int n)
{
    int divisor = 1;

    for (int i = 0; i < n; i++)
    divisor *= 10;

    return (num / divisor) % 10;
}

void radixSort(std::vector<int>& input, bool ascending)
{
    int vec_size = input.size(), max_length = 0, curr_length;
    List* buckets = new List[10];
    
    //get greatest length
    for (int i = 1; i < vec_size; i++)
    {
        curr_length = intLength(input[i]);

        if (curr_length > max_length)
        max_length = curr_length;
    }

    for (int i = 0; i < max_length; i++)
    {
        //fill buckets
        for (int j = 0; j < vec_size; j++)
        buckets[getNthDigit(input[j], i)].addToTail(input[j]);
        
        int bucket_count = 9 * !ascending;
        IntNode* curr = nullptr;
        //refill array
        for (int j = 0; j < vec_size; j++)
        {
            if (ascending)
            {
                while(!curr && bucket_count < 10)
                curr = buckets[bucket_count++].head;
            }

            else
            {
                while(!curr && bucket_count >= 0)
                curr = buckets[bucket_count--].head;
            }
            

            input[j]= curr->value;
            
            if (ascending)
            curr = buckets[bucket_count - 1].deleteFromHead();
            
            else
            curr = buckets[bucket_count + 1].deleteFromHead();
        }
    }

    delete [] buckets;
}

void printVec(std::vector<int> input)
{
	int size = input.size();
	std::cout << "{";
	for (int i = 0; i < size; i++)
	{
		std::cout << input[i];

		if(i != size - 1)
		std::cout << ", ";
	}

	std::cout << "}" << std::endl;
}

int main ()
{
    std::vector<int> my_vec = {4, 7, 3, 11, 1, 9, 10, 6, 105, 56};
    
    radixSort(my_vec, false);
    printVec(my_vec);

    radixSort(my_vec, true);
    printVec(my_vec);
}