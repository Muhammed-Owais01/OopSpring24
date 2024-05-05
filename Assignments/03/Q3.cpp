#include <iostream>

template <typename T>
class Matrix
{
protected:
    T **matrix;
    int rows, cols;
public:
    Matrix(int rows, int column) : rows(rows), cols(column)
    {
        this->matrix = new T*[rows];
        for (int i = 0; i < rows; i++)
        {
            this->matrix[i] = new T[cols];
        }
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                this->matrix[i][j] = 0;
            }
            
        }
        
    }
    ~Matrix()
    { 
        if (matrix != nullptr) {
            for (int i = this->rows - 1; i >= 0; i--) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
    }
    T getValue(int indexX, int indexY) {return this->matrix[indexX][indexY];}
    int getRows() {return this->rows;}
    int getCols() {return this->cols;}
    void setValue(int indexX, int indexY, int num) {this->matrix[indexX][indexY] = num;}

    Matrix<T>& operator+(Matrix<T>& obj)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                this->matrix[i][j] += obj.getValue(i, j);
            }
        }
        return *this;
    }

    Matrix<T>& operator-(Matrix<T>& obj)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                this->matrix[i][j] -= obj.getValue(i, j);
            }
        }
        return *this;
    }

    Matrix<T>& operator*(Matrix<T>& obj)
    {
        T temp[this->rows][obj.getCols()];
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < obj.getCols(); j++)
            {
                for (int k = 0; k < this->cols; k++)
                {
                    temp[i][j] += this->matrix[i][k] * obj.getValue(k, j);
                }
            }
        }

        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < obj.getCols(); j++)
            {
                matrix[i][j] = temp[i][j];
            }
        }
        return *this;
    }

  

    virtual void display() = 0;
};

class IntMatrix : public Matrix<int>
{
public:
    IntMatrix(int rows, int column) : Matrix<int>(rows, column) {}

    Matrix<int>& operator=(Matrix<int>& obj)
    {
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                this->matrix[i][j] = obj.getValue(i, j);
            }
        }
        return *this;
    }

    void display() override
    {
        for (int i = 0; i < getRows(); i++)
        {
            for (int j = 0; j < getCols(); j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

class DoubleMatrix : public Matrix<double>
{
public:
    DoubleMatrix(int rows, int column) : Matrix<double>(rows, column) {}

    Matrix<double>& operator=(Matrix<double>& obj)
    {
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                this->matrix[i][j] = obj.getValue(i, j);
            }
        }
        return *this;
    }

    void display() override
    {
        for (int i = 0; i < getRows(); i++)
        {
            for (int j = 0; j < getCols(); j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};


int main()
{
    IntMatrix intMatrix1(2, 2);
    intMatrix1.setValue(0, 0, 1);
    intMatrix1.setValue(0, 1, 2);
    intMatrix1.setValue(1, 0, 3);
    intMatrix1.setValue(1, 1, 4);

    IntMatrix intMatrix2(2, 2);
    intMatrix2.setValue(0, 0, 5);
    intMatrix2.setValue(0, 1, 6);
    intMatrix2.setValue(1, 0, 7);
    intMatrix2.setValue(1, 1, 8);

    DoubleMatrix doubleMatrix1(2, 2);
    doubleMatrix1.setValue(0, 0, 1.1);
    doubleMatrix1.setValue(0, 1, 2.2);
    doubleMatrix1.setValue(1, 0, 3.3);
    doubleMatrix1.setValue(1, 1, 4.4);

    DoubleMatrix doubleMatrix2(2, 2);
    doubleMatrix2.setValue(0, 0, 5.5);
    doubleMatrix2.setValue(0, 1, 6.6);
    doubleMatrix2.setValue(1, 0, 7.7);
    doubleMatrix2.setValue(1, 1, 8.8);

    // Perform matrix operations
    IntMatrix intResultAddition(2,2);
    IntMatrix intResultSubtraction(2,2);
    IntMatrix intResultMultiplication(2,2);
    intResultAddition = (intMatrix1 + intMatrix2);
    intResultSubtraction = intMatrix1 - intMatrix2;
    intResultMultiplication = intMatrix1 * intMatrix2;

    DoubleMatrix doubleResultAddition(2,2);
    DoubleMatrix doubleResultSubtraction(2,2);
    DoubleMatrix doubleResultMultiplication(2,2);
    doubleResultAddition = doubleMatrix1 + doubleMatrix2;
    doubleResultSubtraction = doubleMatrix1 - doubleMatrix2;
    doubleResultMultiplication = doubleMatrix1 * doubleMatrix2;

    // Display results
    std::cout << "IntResultAddition: \n";
    intResultAddition.display();
    std::cout << "intResultSubtraction: \n";
    intResultSubtraction.display();
    std::cout << "intResultMultiplication: \n";
    intResultMultiplication.display();

    std::cout << "doubleResultAddition: \n";
    doubleResultAddition.display();
    std::cout << "doubleResultSubtraction: \n";
    doubleResultSubtraction.display();
    std::cout << "doubleResultMultiplication: \n";
    doubleResultMultiplication.display();

}