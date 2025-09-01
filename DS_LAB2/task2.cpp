#include <iostream>

class ClassSeating
{
    bool** seats = nullptr;
    unsigned int rows, cols;
    
    public:
    ClassSeating (unsigned int rows, unsigned int cols) : rows(rows), cols(cols)
    {
        this->seats = new bool*[rows];
        
        for (int i = 0; i < rows; i++)
        {
            this->seats[i] = new bool[cols];
        }
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                seats[i][j] = false;
            }
        }
    }
    
    ~ClassSeating ()
    {
        for (int i = 0; i < rows; i++)
        delete [] seats[i];
        
        delete [] seats;
    }
    
    void updateValue (unsigned int row, unsigned int col, bool new_bool)
    {
        if (row + 1 > rows || col + 1 > cols)
        {
            std::cout << "ROWS: " << rows << "\nCOLS: " << cols << "\nSIZE EXCEEDED\nTry again\n";
            return;
        }
        
        if(seats[row][col] == new_bool)
        std::cout << "seat already " << new_bool << std::endl;
        
        else
        seats[row][col] = new_bool;
    }
    
    void printAll ()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                std::cout << seats[i][j];

                if (j != cols - 1)
                std::cout << ", ";
            }
            std::cout << std::endl;
        }
    }
};

int main ()
{
    int row_size, col_size;
    
    do
    {
        std::cout << "row size: ";
        std::cin >> row_size;
    }while(row_size < 0);

    do
    {
        std::cout << "column size: ";
        std::cin >> col_size;
    }while(col_size < 0);
    
    ClassSeating seats(row_size, col_size);
    
    int row, col;
    bool new_bool;
    std::string ans;
    while(1)
    {
        std::cout << "Edit Array? ('y' if yes)" << std::endl;
        std::cin >> ans;
        if (ans[0] == 'y')
        {
            do
            {
                std::cout << "Row: ";
                std::cin >> row; 
            }while(row < 1);

            do
            {
                std::cout << "Column: ";
                std::cin >> col; 
            }while(col < 1);
            
            std::cout << "New Value (0 if false, 1 true): ";
            std::cin >> new_bool;
            
            seats.updateValue(row - 1, col - 1, new_bool);
        }
        
        else
        {
            seats.printAll();
            return 0;
        }
    }
}