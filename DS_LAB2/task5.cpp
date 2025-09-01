#include <iostream>

class Matrix
{
    float** matrix = nullptr;
    
    unsigned int row_size, col_size;

    public:
    Matrix() {}
    Matrix(unsigned int row_size, unsigned int col_size) : row_size(row_size), col_size(col_size)
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
    
    Matrix(const Matrix& other) : row_size(other.getRowSize()), col_size(other.getColSize())
    {
        matrix = new float*[row_size];
        
        for (int i = 0; i < row_size; i++)
        matrix[i] = new float[col_size];
        
        for (int i = 0; i < row_size; i++)
        {
            for (int j = 0; j < col_size; j++)
            {
                setValue(i, j, other.getValue(i, j));
            }
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < row_size; i++)
        delete [] matrix[i];

        delete [] matrix;
    }

    float getValue(unsigned int row, unsigned int col) const
    {
        return matrix[row][col];
    }

    void setValue(unsigned int row, unsigned int col, float value) const
    {
        matrix[row][col] = value;
    }

    unsigned int getRowSize() const
    {
        return row_size;
    }

    unsigned int getColSize() const
    {
        return col_size;
    }

    Matrix operator+(Matrix& other)
    {
        if (row_size != other.getRowSize() || col_size != other.getColSize())
        {
            std::cout << "ERROR. Both Matrices should be of equal dimensions\n";
            return *this;
        }

        Matrix tmp(row_size, col_size);

        for (int i = 0; i < row_size; i++)
        {
            for (int j = 0; j < col_size; j++)
            {
                tmp.setValue(i, j, matrix[i][j] + other.getValue(i, j));
            }
        }
        
        return tmp;
    }

    Matrix operator-(const Matrix& other) 
    {
        if (row_size != other.getRowSize() || col_size != other.getColSize())
        {
            std::cout << "ERROR. Both Matrices should be of equal dimensions\n";
            return *this;
        }

        Matrix tmp(row_size, col_size);

        for (int i = 0; i < row_size; i++)
        {
            for (int j = 0; j < col_size; j++)
            {
                tmp.setValue(i, j, matrix[i][j] - other.getValue(i, j));
            }
        }
        
        return tmp;
    }
    
    Matrix& operator=(const Matrix& other)
    {
        if (this == &other)
        return *this;
        
        if (matrix != nullptr)
        {
            for (int i = 0; i < row_size; i++)
            delete [] matrix[i];
            
            delete [] matrix;
        }
        
        row_size = other.getRowSize();
        col_size = other.getColSize();
        
        matrix = new float*[row_size];
        
        for (int i = 0; i < row_size; i++)
        matrix[i] = new float[col_size];
        
        for (int i = 0; i < row_size; i++)
        {
            for (int j = 0; j < col_size; j++)
            {
                setValue(i, j, other.getValue(i, j));
            }
        }
        
        return *this;
    }
    
    void displayMatrix ()
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
};

int main ()
{
    unsigned int rows, cols;
    Matrix matrices[2];
    
    std::cout << "rows: ";
    std::cin >> rows;
    
    std::cout << "columns: ";
    std::cin >> cols;
        
    matrices[0] = Matrix(rows, cols);
    matrices[1] = Matrix(rows, cols);
    
    float value;
    for (int k = 0; k < 2; k++)
    {
        std::cout << "\nMATRIX " << k + 1 << std::endl;
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                std::cout << "row " << i + 1 << " column " << j + 1 << "(value): ";
                std::cin >> value;
                matrices[k].setValue(i, j, value);
            }
        }
    }
    
    std::cout << "\nADDITION OF MATRICES" << std::endl;
    Matrix tmp = matrices[0] + matrices[1];
    tmp.displayMatrix();
    
    std::cout << "\nMATRIX 1 - MATRIX 2" << std::endl;
    tmp = matrices[0] - matrices[1];
    tmp.displayMatrix();
}