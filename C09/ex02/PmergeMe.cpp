#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

template <typename Container>
void PmergeMe::printContainer(const std::string& message, const Container& data) {
    std::cout << message;
    for (typename Container::const_iterator it = data.begin(); it != data.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;
}

// 🔹 Instanciaciones explícitas para `std::vector<int>` y `std::deque<int>`
template void PmergeMe::printContainer<std::vector<int> >(const std::string&, const std::vector<int>&);
template void PmergeMe::printContainer<std::deque<int> >(const std::string&, const std::deque<int>&);


// Generar la secuencia de Jacobsthal
std::vector<int> PmergeMe::generateJacobsthalSequence(int n) {
    std::vector<int> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);
    while (jacobsthal.back() < n) {
        jacobsthal.push_back(jacobsthal[jacobsthal.size() - 1] + 
                             2 * jacobsthal[jacobsthal.size() - 2]);
    }
    return jacobsthal;
}


// Implementación de Ford-Johnson con std::vector
void PmergeMe::sortWithVector(std::vector<int>& data) {
    if (data.size() <= 1) return;

    std::vector<int> mainList;
    std::vector<int> toInsert;

    // Paso 1: Dividir en pares y ordenar
    for (size_t i = 0; i + 1 < data.size(); i += 2) {
        if (data[i] > data[i + 1]) {
            mainList.push_back(data[i]);
            toInsert.push_back(data[i + 1]);
        } else {
            mainList.push_back(data[i + 1]);
            toInsert.push_back(data[i]);
        }
    }

    if (data.size() % 2 != 0) {
        toInsert.push_back(data.back());
    }

    // Paso 2: Ordenar `mainList` de forma recursiva
    sortWithVector(mainList);

    // ✅ Asegurar que `toInsert` está ordenado correctamente antes de la inserción
    insertionSort(toInsert);

    // Paso 3: Insertar `toInsert` en `mainList` siguiendo la secuencia de Jacobsthal
    std::vector<int> jacobsthal = generateJacobsthalSequence(toInsert.size());

    for (size_t i = 0; i < toInsert.size(); ++i) {
        size_t index = (i < jacobsthal.size()) ? jacobsthal[i] - 1 : i;
        if (index >= mainList.size()) index = mainList.size();
        
        // 🔹 Buscar la posición correcta en `mainList`
        std::vector<int>::iterator pos = mainList.begin();
        while (pos != mainList.end() && *pos < toInsert[i]) {
            ++pos;
        }
        
        mainList.insert(pos, toInsert[i]);
    }

    data = mainList;
}

void PmergeMe::insertionSortq(std::deque<int>& arr) {
    for (std::deque<int>::iterator it = arr.begin() + 1; it != arr.end(); ++it) {
        int key = *it;
        std::deque<int>::iterator j = it;

        while (j != arr.begin() && *(j - 1) > key) {
            *j = *(j - 1);  // Mover el elemento hacia adelante
            --j;
        }
        *j = key;  // Insertar el valor en la posición correcta
    }
}


void PmergeMe::insertionSort(std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        int key = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

// Implementación de Ford-Johnson con std::deque
void PmergeMe::sortWithDeque(std::deque<int>& data) {
    if (data.size() <= 1) return;

    std::deque<int> mainList;
    std::deque<int> toInsert;

    // Paso 1: Dividir en pares y ordenar
    for (size_t i = 0; i + 1 < data.size(); i += 2) {
        if (data[i] > data[i + 1]) {
            mainList.push_back(data[i]);
            toInsert.push_back(data[i + 1]);
        } else {
            mainList.push_back(data[i + 1]);
            toInsert.push_back(data[i]);
        }
    }

    if (data.size() % 2 != 0) {
        toInsert.push_back(data.back());
    }

    // Paso 2: Ordenar `mainList` de forma recursiva
    sortWithDeque(mainList);

    // ✅ Asegurar que `toInsert` está ordenado correctamente antes de la inserción
    insertionSortq(toInsert);

    // Paso 3: Insertar `toInsert` en `mainList` siguiendo la secuencia de Jacobsthal
    std::vector<int> jacobsthal = generateJacobsthalSequence(toInsert.size());

    for (size_t i = 0; i < toInsert.size(); ++i) {
        size_t index = (i < jacobsthal.size()) ? jacobsthal[i] - 1 : i;
        if (index >= mainList.size()) index = mainList.size();
        
        // 🔹 Buscar la posición correcta en `mainList`
        std::deque<int>::iterator pos = mainList.begin();
        while (pos != mainList.end() && *pos < toInsert[i]) {
            ++pos;
        }
        
        mainList.insert(pos, toInsert[i]);
    }

    data = mainList;
}

// Procesamiento de entrada y ejecución del algoritmo
void PmergeMe::processInput(const std::vector<int>& input) {
    std::vector<int> vectorData(input.begin(), input.end());
    std::deque<int> dequeData(input.begin(), input.end());

    printContainer("Before:", input);

    clock_t start = clock();
    sortWithVector(vectorData);
    clock_t end = clock();
    double timeVector = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    start = clock();
    sortWithDeque(dequeData);
    end = clock();
    double timeDeque = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    printContainer("After:", vectorData);

    std::cout << "Time to process with std::vector: " << timeVector << " us" << std::endl;
    std::cout << "Time to process with std::deque: " << timeDeque << " us" << std::endl;
}
