#include "matrix.h"

template<typename T,size_t _COLS,size_t _ROWS>
inline Matrix<T,_COLS,_ROWS> :: Matrix() : _matrix(new T*[_cols]) {
    for(size_t _index = 0;_index < _cols;++_index) {
        _matrix[_index] = new T[_rows];
    }

    for(size_t _index = 0; _index < _cols; ++_index) {
        for(size_t __index = 0; __index < _rows; ++__index) {
            _matrix[_index][__index] = T();
        }
    }
}

template<typename T,size_t _COLS,size_t _ROWS>
inline Matrix<T,_COLS,_ROWS> :: Matrix(T _value) : _matrix(new T*[_cols]) {

    for(size_t _index = 0;_index < _cols;++_index) {
        _matrix[_index] = new T[_rows];
    }

    for(size_t _index = 0; _index < _cols; ++_index) {
        for(size_t __index = 0; __index < _rows; ++__index) {
            _matrix[_index][__index] = _value;
        }
    }
}

template<typename T,size_t _COLS,size_t _ROWS>
inline Matrix<T,_COLS,_ROWS> :: Matrix(const Matrix& _other) : _matrix(nullptr) {

    _matrix = new T*[_cols];
    for(size_t _index = 0;_index < _cols;++_index) {
        _matrix[_index] = new T[_rows];
    }

    for(size_t _index = 0; _index < _cols; ++_index) {
        for(size_t __index = 0; __index < _rows; ++__index) {
            _matrix[_index][__index] = _other._matrix[_index][__index];
        }
    }
}

template<typename T,size_t _COLS,size_t _ROWS>
inline Matrix<T,_COLS,_ROWS>& Matrix<T,_COLS,_ROWS> :: operator=(const Matrix<T,_COLS,_ROWS>& other) {
    Matrix<T,other._cols,other._rows> copy = other;
    swap(copy);
    return *this;

}

template<typename T,size_t _COLS,size_t _ROWS>
inline void Matrix<T,_COLS,_ROWS> :: swap(Matrix& _other) { 
    std :: swap(_matrix,_other._matrix);
}

template<typename T,size_t _COLS,size_t _ROWS> 
inline Matrix<T,_COLS,_ROWS> :: ~Matrix() {
    if(_matrix != nullptr) {
        for(size_t _index = 0; _index < _cols; ++_index) {
            delete[] _matrix[_index];
        }
        delete[] _matrix;
    }
}





