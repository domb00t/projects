#include <iostream> 

template<typename T,size_t _COLS,size_t _ROWS>
class Matrix { 
public:
    Matrix() : _matrix(new T*[_cols]) {
        for(size_t _index = 0;_index < _cols;++_index) {
            _matrix[_index] = new T[_rows];
        }

        for(size_t _index = 0; _index < _cols; ++_index) {
            for(size_t __index = 0; __index < _rows; ++__index) {
                _matrix[_index][__index] = T();
            }
        }
    }

    Matrix(T _value) : _matrix(new T*[_cols]) {
        for(size_t _index = 0;_index < _cols;++_index) {
            _matrix[_index] = new T[_rows];
        }

        for(size_t _index = 0; _index < _cols; ++_index) {
            for(size_t __index = 0; __index < _rows; ++__index) {
                _matrix[_index][__index] = _value;
            }
        }
    }

    Matrix(const Matrix& _other) : _matrix(nullptr) {

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

    Matrix& operator=(const Matrix* other) { 
        Matrix<T,other._cols,other._rows> copy = other;
        swap(copy);
        return *this;
    }

    ~Matrix() {
        if(_matrix != nullptr) {
            for(size_t _index = 0; _index < _cols; ++_index) {
                delete[] _matrix[_index];
            }

        delete[] _matrix;
        }
    }
private:
    T** _matrix;
    static constexpr size_t _cols = _COLS;
    static constexpr size_t _rows = _ROWS;

    void swap(Matrix& _other) {
        std :: swap(_matrix,_other._matrix);
    }

    friend std :: ostream& operator<<(std :: ostream& os,const Matrix& __matrix) {
         for(size_t _index = 0; _index < __matrix._cols; ++_index) {
            for(size_t __index = 0; __index < __matrix._rows; ++__index) {
                os << __matrix._matrix[_index][__index] << " ";
            }
            os << std :: endl;
        }
        return os;
    }

    friend std :: istream& operator>>(std :: istream& is, Matrix& __matrix) {
        for(size_t _index = 0;_index < __matrix._cols;++_index) {
            for(size_t __index = 0; __index < __matrix._rows; ++__index) {
                std :: cout << "Matrix [" << _index << "][" << __index << "]: ";
                is >> __matrix._matrix[_index][__index];
            }
        }
        return is;
    }
};

// gets type of T
template <typename T> 
void test(T) = delete;

int main() {
    Matrix<int,3,3> matrix;
    Matrix<int,3,3> _matrix(matrix);
    Matrix<int,3,3> __matrix = _matrix;    std :: cout << &matrix << std :: endl << matrix << std :: endl;
    std :: cout << &_matrix << std :: endl << _matrix << std :: endl;
    std :: cout << &__matrix << std :: endl << __matrix << std :: endl;

    
}