// Llámame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib> // Для використання функції rand()

class Matrix {
private:
    int** data;
    size_t rows, cols;

public:
    Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
        data = new int* [rows];
        for (size_t i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (size_t j = 0; j < cols; j++) {
                data[i][j] = rand() % 10;
            }
        }
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);

        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix result(rows, cols);

        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }

        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(rows, other.cols);

        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < other.cols; j++) {
                for (size_t k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }

    void print() const {
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                std::cout << data[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }

    ~Matrix() {
        for (size_t i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
};

int main() {
    Matrix A(2, 3);
    std::cout << "Matrix A:" << std::endl;
    A.print();

    Matrix B(2, 3);
    std::cout << "\nMatrix B:" << std::endl;
    B.print();

    Matrix C = A + B;
    std::cout << "\nA + B:" << std::endl;
    C.print();

    Matrix D = A - B;
    std::cout << "\nA - B:" << std::endl;
    D.print();

    Matrix E(3, 2);
    std::cout << "\nMatrix E:" << std::endl;
    E.print();

    Matrix F = A * E;
    std::cout << "\nA * E:" << std::endl;
    F.print();
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
