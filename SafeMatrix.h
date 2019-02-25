#include <iostream>

// templatized Safe Matrix class
template<class T>
class SafeMatrix {
private:

    // row lower and upper bounds
    int rlow, rhigh;

    // column lower and upper bounds
    int clow, chigh;

    // safe matrix alias
    typedef SafeArray<SafeArray<T>> safe_matrix;

    // safe array alias
    typedef SafeArray<T> safe_array;

    // 2-dimensional Safe Array (Safe Matrix)
    safe_matrix sm;

public:

    // default constructor
    SafeMatrix() {
        rlow = clow = 0;
        rhigh = chigh = -1;
        sm = NULL;
    }

    // upper and lower bounds specified for both dimensions
    SafeMatrix(int rl, int rh, int cl, int ch) {

        // check bounds first for both rows and columns
        if (((rh - rl + 1) <= 0) || (ch - cl + 1) <= 0) {
            std::cout << "Error: Out of bounds!" << std::endl;
            exit(1);
        }
        rlow = rl;
        rhigh = rh;
        clow = cl;
        chigh = ch;

        sm = safe_matrix(rlow, rhigh);
        for (int i = rlow; i <= rhigh; i++)
            sm[i] = safe_array(clow, chigh);
    }

    // only upper bounds specified for both dimensions
    SafeMatrix(int rh, int ch) {
        rlow = clow = 0;
        rhigh = rh - 1;
        chigh = ch - 1;

        sm = safe_matrix(rh);
        for (int i = 0; i < rh; i++)
            sm[i] = safe_array(ch);
    }

    // overload [] operator
    SafeArray<T> &operator[](int i) {
        if (i < rlow || i > rhigh) {
            std::cout << "Error: Index " << i << " is out of range" << std::endl;
            exit(1);
        }
        return sm[i];
    }

    // overload << operator
    friend std::ostream &operator<<(std::ostream &os, SafeMatrix<T> s) {
        for (int i = s.rlow; i <= s.rhigh; i++)
            os << s[i];
        return os;
    }

    // multiplication operator
    SafeMatrix<T> operator*(SafeMatrix &sm) {
        int rows = rhigh - rlow; // first matrix rows
        int cols = sm.chigh - sm.clow; // second matrix columns

        // # of columns of the first matrix must be equal to # of rows in the second matrix
        if (chigh - clow != sm.rhigh - sm.rlow) {
            std::cout << "Error: Wrong dimensions!" << std::endl;
            exit(1);
        }

        SafeMatrix<T> result(0, rows, 0, cols); // resulting matrix
        for (int i = 0; i <= rows; i++) {
            for (int j = 0; j <= cols; j++) {
                result[i][j] = 0; // initialize to zero first
                for (int k = 0; k < sm.rhigh - sm.rlow + 1; k++) {
                    // multiply each value of ith row by the corresponding value of the jth column
                    // add the resulting products together and store it in our resulting matrix
                    result[i][j] += this->sm[rlow + i][clow + k] * sm.sm[sm.rlow + k][sm.clow + j];
                }
            }
        }
        return result;
    }
};

