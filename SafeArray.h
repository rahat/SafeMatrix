#include <iostream>

// templatized Safe Array Class
template<class T>
class SafeArray {
private:
    int low, high;
    T *p;
public:

    SafeArray() {
        low = 0;
        high = -1;
        p = NULL;
    }

    SafeArray(int l, int h) {
        if ((h - l + 1) <= 0) {
            std::cout << "constructor error in bounds definition" << std::endl;
            exit(1);
        }
        low = l;
        high = h;
        p = new T[h - l + 1];
    }

    explicit SafeArray(int i) {
        low = 0;
        high = i - 1;
        p = new T[i];
    }

    SafeArray(const SafeArray<T> &s) {
        int size = s.high - s.low + 1;
        p = new T[size];
        for (int i = 0; i < size; i++)
            p[i] = s.p[i];
        low = s.low;
        high = s.high;
    }

    ~SafeArray() {
        delete[] p;
    }

    T &operator[](int i) {
        if (i < low || i > high) {
            std::cout << "Error: Index " << i << " out of range!" << std::endl;
            exit(1);
        }
        return p[i - low];
    }

    SafeArray &operator=(const SafeArray<T> &s) {
        if (this == &s)return *this;
        delete[] p;
        int size = s.high - s.low + 1;
        p = new T[size];
        for (int i = 0; i < size; i++)
            p[i] = s.p[i];
        low = s.low;
        high = s.high;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, SafeArray<T> s) {
        int size = s.high - s.low + 1;
        for (int i = 0; i < size; i++)
            os << s.p[i] << "\t";
        os << std::endl;
        return os;
    }
};