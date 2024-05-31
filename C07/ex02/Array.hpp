#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <exception>
#include <iostream>
#include <cstdlib>

template <typename T>
class Array {
private:
    T* data;
    unsigned int len;

public:
    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Index out of bounds";
        }
    };

    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    unsigned int size() const;
};

#include "Array.tpp"

#endif
