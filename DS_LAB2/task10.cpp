#include <iostream>

class Book
{
    std::string name, genre;
    unsigned int ID;
    bool available = true;

    public:
    Book() {}
    Book(std::string& name, std::string& genre, unsigned int& ID) : name(name), genre(genre), ID(ID) {}
    
    std::string getName()
    {
        return name;
    }

    unsigned int getID()
    {
        return ID;
    }

    void issue()
    {
        available = false;
    }

    void receive()
    {
        available = true;
    }

    bool isAvail()
    {
        return available;
    }
};

class Category
{
    Book* books = nullptr;
    std::string name;
    unsigned int size;

    public:
    Category() {}
    Category(std::string& name, unsigned int& size) : name(name), size(size)
    {
        this->books = new Book[size];

        for (int i = 0; i < size; i++)
        this->books[i] = books[i];
    }

    ~Category()
    {
        delete [] books;
    }

    void addBook(unsigned int index, Book& to_add)
    {
        if (index > size - 1)
        return;

        books[index] = to_add;
    }

    bool searchAndDisplay(unsigned int ID)
    {
        for (int i = 0; i < size; i++)
        {
            if (ID == books[i].getID())
            {
                std::cout << "BOOK FOUND" << "\nName: " << books[i].getName() << "\nID: " << books[i].getID();
                
                if (books[i].isAvail())
                std::cout << "\nAvailable";
                else
                std::cout << "\nNot Available";

                std::cout << std::endl;

                return true;
            }
        }

        return false;
    }
};

int main ()
{
    Category* genres = nullptr;
    Book* books = nullptr;
    unsigned int num_genre, num_books, ID;
    std::string name, genre;

    std::cout << "Number of Books: ";
    std::cin >> num_books;

    for (int i = 0; i < num_books; i++)
    {
        std::cout << "BOOK " << i + 1 << std::endl;
        
        std::cout << "Name: ";
        std::cin >> name;

        std::cout << "ID: ";
        std::cin >> ID;

        std::cout << "Genre: ";
        std::cin >> genre;

        Book()
    }

}