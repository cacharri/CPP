template <typename T>
Array<T>::Array() : data(NULL), len(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]()), len(n) {}

template <typename T>
Array<T>::Array(const Array& other) : data(new T[other.len]()), len(other.len) {
    for (unsigned int i = 0; i < len; ++i) {
        data[i] = other.data[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] data;
        len = other.len;
        data = new T[len]();
        for (unsigned int i = 0; i < len; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= len) {
        throw OutOfBoundsException();
    }
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= len) {
        throw OutOfBoundsException();
    }
    return data[index];
}
