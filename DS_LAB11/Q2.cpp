#include <iostream>
#define TABLESIZE 100

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
	void add_Record(std::string key, std::string value)
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

	int word_Search(std::string key, std::string value)
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

	void print_Dictionary()
	{
		Node* curr;
		for (int i = 0; i < TABLESIZE; i++)
		{
			curr = arr[i];
			while(curr)
			{
				std::cout << curr->value << "	";
				curr = curr->next;
			}
		}
	}

};
				
int main ()
{
	HashTable my_table;
	my_table.add_Record("A", "first");
	my_table.add_Record("E", "second");
	my_table.add_Record("A", "third");
	my_table.add_Record("A", "fourth");

	my_table.word_Search("A", "eleventh");
	my_table.word_Search("A", "third");
	my_table.word_Search("E", "second");
	my_table.word_Search("C", "first");

	my_table.print_Dictionary();
}



	
