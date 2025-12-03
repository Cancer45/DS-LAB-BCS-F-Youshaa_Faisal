#include <iostream>
#define TABLESIZE 101

int hash(std::string input)
{
	int str_len = input.length();
	int sum = 0;

	for (int i = 0; i < str_len; i++) sum += input[i];
	return sum % TABLESIZE;
}

class Node
{
	public:
	std::string value;
	Node* next = nullptr;

	Node() {}
	Node(std::string value) : value(value) {}
};

class HashTable
{
	Node* arr[TABLESIZE];

	public:
	HashTable()
	{
		for (int i = 0; i < TABLESIZE; i++) arr[i] = nullptr;
	}
	void insert(std::string key, std::string value)
	{
		int hash_val = hash(key);
		if (!arr[hash_val])
		arr[hash_val] = new Node(value);

		else
		{
			Node* curr = arr[hash_val];
			while(curr->next && curr->value != value) curr = curr->next;
			if (!curr->next && curr->value != value) curr->next = new Node(value);
		}
	}

	int search(std::string key, std::string value)
	{
		int hash_val = hash(key);
		if (!arr[hash_val])
		{
			std::cout << "not found\n";
			return 0;
		}

		else
		{
			Node* curr = arr[hash_val];
			while(curr->next && curr->value != value) curr = curr->next;
			if (curr->value == value)
			{
				std::cout << "found\n";
				return 1;
			}

			else
			{
				std::cout << "not found\n";
				return 0;
			}
		}
	}

};
				
int main ()
{
	HashTable my_table;
	my_table.insert("A", "first");
	my_table.insert("E", "second");
	my_table.insert("A", "third");
	my_table.insert("A", "fourth");

	my_table.search("A", "eleventh");
	my_table.search("A", "third");
	my_table.search("E", "second");
	my_table.search("C", "first");
}



	
