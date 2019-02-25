#include "SafeArray.h"
#include "SafeMatrix.h"

int main() {

    std::cout << "Matrix 1 (using only upper bounds):" << std::endl;
    SafeMatrix<int> matrix(3, 3);
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;
    std::cout << matrix << std::endl;

    std::cout << "Matrix 2 (using both lower and upper bounds):" << std::endl;

    SafeMatrix<int> matrix2(2, 4, 6, 8);
    matrix2[2][6] = 10;
    matrix2[2][7] = 11;
    matrix2[2][8] = 12;
    matrix2[3][6] = 13;
    matrix2[3][7] = 14;
    matrix2[3][8] = 15;
    matrix2[4][6] = 16;
    matrix2[4][7] = 17;
    matrix2[4][8] = 18;
    std::cout << matrix2 << std::endl;

    SafeMatrix<int> result = matrix * matrix2;
    std::cout << "Matrix 1 x Matrix 2" << std::endl;
    std::cout << result << std::endl;

    std::cout << "Testing multiplication of 4x4 and 4x2 matrix with values of type short:" << std::endl;
    SafeMatrix<short> matrix3(4, 4);
    matrix3[0][0] = 19;
    matrix3[0][1] = 20;
    matrix3[0][2] = 21;
    matrix3[0][3] = 22;
    matrix3[1][0] = 23;
    matrix3[1][1] = 24;
    matrix3[1][2] = 25;
    matrix3[1][3] = 26;
    matrix3[2][0] = 27;
    matrix3[2][1] = 28;
    matrix3[2][2] = 29;
    matrix3[2][3] = 30;
    matrix3[3][0] = 31;
    matrix3[3][1] = 32;
    matrix3[3][2] = 33;
    matrix3[3][3] = 34;
    std::cout << "Matrix 3:" << std::endl << matrix3 << std::endl;


    SafeMatrix<short> matrix4(1, 4, 1, 2);
    matrix4[1][1] = 35;
    matrix4[1][2] = 36;
    matrix4[2][1] = 37;
    matrix4[2][2] = 38;
    matrix4[3][1] = 39;
    matrix4[3][2] = 40;
    matrix4[4][1] = 41;
    matrix4[4][2] = 42;
    std::cout << "Matrix 4:" << std::endl << matrix4 << std::endl;

    SafeMatrix<short> result2 = matrix3 * matrix4;
    std::cout << "Matrix 3 x Matrix 4" << std::endl;
    std::cout << result2 << std::endl;

    std::cout << "Testing multiplication of matricies but with values of type double:" << std::endl;
    std::cout << "Matrix 5:" << std::endl;
    SafeMatrix<double> matrix5(2, 2);
    matrix5[0][0] = 1.2312;
    matrix5[0][1] = 3.3235;
    matrix5[1][0] = 2.7657;
    matrix5[1][1] = 4.3276;

    std::cout << matrix5 << std::endl;

    SafeMatrix<double> matrix6(2, 3);
    std::cout << "Matrix 6: " << std::endl;
    matrix6[0][0] = 6.4354;
    matrix6[0][1] = 8.6746;
    matrix6[0][2] = 9.6459;
    matrix6[1][0] = 7.8344;
    matrix6[1][1] = 5.2943;
    matrix6[1][2] = 2.0984;
    std::cout << matrix6 << std::endl;

    SafeMatrix<double> result3 = matrix5 * matrix6;
    std::cout << "Matrix 5 x Matrix 6" << std::endl;
    std::cout << result3;

    return 0;
}
