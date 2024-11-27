#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::processInput(const std::vector<int>& input) {

    std::vector<int> vectorData(input.begin(), input.end());
    std::deque<int> dequeData(input.begin(), input.end());

    printContainer("Before:", input);

    vectorData = measureTime(vectorData, &PmergeMe::sortWithVector, "std::vector");
    dequeData = measureTime(dequeData, &PmergeMe::sortWithDeque, "std::deque");

    printContainer("After:", vectorData);
}

void PmergeMe::sortWithVector(std::vector<int>& data) {
    if (data.size() <= 1) {
        return;
    }
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

    // Si hay un elemento impar, añadirlo a los elementos para insertar
    if (data.size() % 2 != 0) {
        toInsert.push_back(data.back());
    }

    // Paso 2: Ordenar la lista principal
    std::sort(mainList.begin(), mainList.end());

    // Paso 3: Insertar los elementos restantes
    for (size_t i = 0; i < toInsert.size(); ++i) {
        std::vector<int>::iterator pos = mainList.begin();
        while (pos != mainList.end() && *pos < toInsert[i]) {
            ++pos;
        }
        mainList.insert(pos, toInsert[i]);
    }
    data = mainList;
}

void PmergeMe::sortWithDeque(std::deque<int>& data) {
    if (data.size() <= 1) {
        return;
    }

    std::deque<int> mainList;
    std::deque<int> toInsert;

    // Paso 1: Dividir en pares y ordenar cada par
    for (size_t i = 0; i + 1 < data.size(); i += 2) {
        if (data[i] > data[i + 1]) {
            mainList.push_back(data[i]);     // Mayor va a la lista principal
            toInsert.push_back(data[i + 1]); // Menor va a la lista secundaria
        } else {
            mainList.push_back(data[i + 1]);
            toInsert.push_back(data[i]);
        }
    }

    // Si hay un número impar, añadirlo a los elementos secundarios
    if (data.size() % 2 != 0) {
        toInsert.push_back(data.back());
    }

    std::sort(mainList.begin(), mainList.end());

    for (size_t i = 0; i < toInsert.size(); ++i) {
        std::deque<int>::iterator pos = mainList.begin();
        while (pos != mainList.end() && *pos < toInsert[i]) {
            ++pos;
        }
        mainList.insert(pos, toInsert[i]);
    }

    data = mainList;
}

template <typename Container, typename SortFunction>
Container PmergeMe::measureTime(Container data, SortFunction sortFunction, const std::string& containerName) {
    clock_t start = clock();

    (this->*sortFunction)(data);

    clock_t end = clock();

    double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << data.size() << " elements with "
              << containerName << ": " << elapsedTime << " us" << std::endl;

    return data;
}

template <typename Container>
void PmergeMe::printContainer(const std::string& message, const Container& data) {
    std::cout << message;
    for (typename Container::const_iterator it = data.begin(); it != data.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;
}
