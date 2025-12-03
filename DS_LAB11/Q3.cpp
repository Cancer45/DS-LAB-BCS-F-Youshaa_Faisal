#include <iostream>
#include <list>
#define TABLESIZE 101

int hash(std::string input)
{
    int sum = 0;
    for (char c : input) sum += c;
    return sum % TABLESIZE;
}

class HashTable
{
    std::list<std::string> arr[TABLESIZE];

public:
    HashTable() {}

    bool insert(std::string value)
    {
        int hash_val = hash(value);

        for (std::string tmp : arr[hash_val])
            if (tmp == value)
                return false;

        arr[hash_val].push_back(value);
        return true;
    }

    bool deleteVal(std::string value)
    {
        int hash_val = hash(value);

        for (auto it = arr[hash_val].begin(); it != arr[hash_val].end(); )
        {
            if (*it == value)
                return arr[hash_val].erase(it), true;
            else
                ++it;
        }

        return false;
    }

    bool search(std::string value)
    {
        int hash_val = hash(value);

        for (std::string tmp : arr[hash_val])
            if (tmp == value)
            {
                std::cout << "found\n";
                return true;
            }

        std::cout << "not found\n";
        return false;
    }

    void printTable()
    {
        for (int i = 0; i < TABLESIZE; ++i)
            if (!arr[i].empty())
            {
                std::cout << "Index " << i << ": ";
                for (std::string tmp : arr[i])
                    std::cout << tmp << " ";
                std::cout << "\n";
            }
    }
};

int main()
{
    HashTable ht;
    ht.insert("A");
    ht.insert("E");
    ht.insert("A");
    ht.insert("AB");
    ht.insert("CD");

    ht.printTable();

    ht.search("A");
    ht.search("B");
    ht.search("CD");

    ht.deleteVal("A");
    ht.deleteVal("EF");

    ht.printTable();

    return 0;
}
