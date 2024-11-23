#include "matrix.h"
#include "matrix.cpp"



#include <iostream> 

int main() {

  
    Matrix<int,3,3> matrix;
    Matrix<int,3,3> _matrix(matrix);
    Matrix<int,3,3> __matrix = _matrix;
    std :: cout << &matrix << std :: endl << matrix << std :: endl;
    std :: cout << &_matrix << std :: endl << _matrix << std :: endl;
    std :: cout << &__matrix << std :: endl << __matrix << std :: endl;
    
}