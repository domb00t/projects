#pragma once

#include <iostream>


template<typename T,size_t _COLS,size_t _ROWS>
class Matrix { 
public:

    Matrix();
    Matrix(T _value);
    Matrix(const Matrix& _other);

    Matrix& operator=(const Matrix& other);
    ~Matrix() ;

private:
    T** _matrix;
    static constexpr size_t _cols = _COLS;
    static constexpr size_t _rows = _ROWS;

    void swap(Matrix& _other);

    
    friend  std :: ostream& operator<<(std :: ostream& os,const Matrix& __matrix) {
        for(size_t _index = 0; _index < __matrix._cols; ++_index) {
            for(size_t __index = 0; __index < __matrix._rows; ++__index) {
                os << __matrix._matrix[_index][__index] << " ";
            }
            os << std :: endl;
        }
        return os;
    }

    friend  std :: istream& operator>>(std :: istream& is, Matrix& __matrix) {
        for(size_t _index = 0;_index < __matrix._cols;++_index) {
            for(size_t __index = 0; __index < __matrix._rows; ++__index) {
                std :: cout << "Matrix [" << _index << "][" << __index << "]: ";
                is >> __matrix._matrix[_index][__index];
            }
        }
        return is;
    }
};






