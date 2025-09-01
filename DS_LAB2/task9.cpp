#include <iostream>

class SparseMatrix
{
    float** matrix = nullptr;
    
    unsigned int row_size, col_size;

    public:
    SparseMatrix(unsigned int row_size, unsigned int col_size) : row_size(row_size), col_size(col_size)
    {
        matrix = new float*[row_size];

        for (int i = 0; i < row_size; i++)
        matrix[i] = new float[col_size];

        for (int i = 0; i < row_size; i++)
        {
            for (int j = 0; j < col_size; j++)
            {
                matrix[i][j] = 0;
            }
        }

    }

    SparseMatrix(const SparseMatrix& other)
    {
        row_size = other.getRowSize();
        col_size = other.getColSize();

        matrix = new float*[row_size];

        for (int i = 0; i < row_size; i++)
        matrix[i] = new float[col_size];

        for (int i = 0; i < row_size; i++)
        {
            for (int j = 0; j < col_size; j++)
            {
                matrix[i][j] = other.getValue(i, j);
            }
        }
    }

    SparseMatrix& operator=(const SparseMatrix& other)
    {
        if (&other == this)
        return *this;

        row_size = other.getRowSize();
        col_size = other.getColSize();

        delete [] matrix;
        matrix = new float*[row_size];

        for (int i = 0; i < row_size; i++)
        matrix[i] = new float[col_size];

        for (int i = 0; i < row_size; i++)
        {
            for (int j = 0; j < col_size; j++)
            {
                matrix[i][j] = other.getValue(i, j);
            }
        }

        return *this;
    }

    ~SparseMatrix()
    {
        for (int i = 0; i < row_size; i++)
        delete [] matrix[i];

        delete [] matrix;
    }

    unsigned int getRowSize() const
    {
        return row_size;
    }

    unsigned int getColSize() const
    {
        return col_size;
    }

    float getValue(unsigned int row, unsigned int col) const
    {
        return matrix[row][col];
    }

    void updateValue (unsigned int row, unsigned int col, float new_val)
    {
        if (row + 1 > row_size || col + 1 > col_size)
        {
            std::cout << "ROWS: " << row_size << "\nCOLS: " << col_size << "\nSIZE EXCEEDED\nTry again\n";
            return;
        }
        
        matrix[row][col] = new_val;
    }

    void displayNormal()
    {
        for (int i = 0; i < row_size; i++)
        {
            for (int j = 0; j < col_size; j++)
            {
                std::cout << matrix[i][j];

                if (j != col_size - 1)
                std::cout << ", ";
            }
            std::cout << std::endl;
        }
    }

    void displayCompressed()
    {
        for (int i = 0; i < row_size; i++)
        {
            for (int j = 0; j < col_size; j++)
            {
                if (matrix[i][j] != 0)
                std::cout << "\nRow: " << i + 1 << "\nColumn: " << j + 1 << "\nValue: " << matrix[i][j] << std::endl;
            }
        }
    }
};

int main ()
{
    unsigned int rows, cols;
    float value;

    std::cout << "rows: ";
    std::cin >> rows;
    
    std::cout << "columns: ";
    std::cin >> cols;

    SparseMatrix sp(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << "row " << i + 1 << " column " << j + 1 << "(value): ";
            std::cin >> value;
                
            sp.updateValue(i, j, value);
        }
    }

    sp.displayNormal();
    sp.displayCompressed();
}