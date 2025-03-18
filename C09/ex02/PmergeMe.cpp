#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    (void)other;
    return *this;
}
PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::generateJacobsthalSequence(int n) {
    std::vector<int> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);

    while (jacobsthal.back() < n) {
        jacobsthal.push_back(jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2]);
    }
    return jacobsthal;
}

// VECTOR IMPLEMENTATION
void PmergeMe::createPairs(const std::vector<int>& vec, std::vector<std::pair<int, int> >& pairs, int& extra) {
    pairs.clear();
    extra = -1;
    for (size_t i = 0; i + 1 < vec.size(); i += 2) {
        pairs.push_back(std::make_pair(std::max(vec[i], vec[i+1]), std::min(vec[i], vec[i+1])));
    }
    if (vec.size() % 2 != 0) extra = vec.back();
}

void PmergeMe::pairInsertionSort(std::vector<std::pair<int, int> >& pairs) {
    for (size_t i = 1; i < pairs.size(); ++i) {
        std::pair<int, int> key = pairs[i];
        size_t j = i;

        // Orden descendente (mayor a menor según first)
        while (j > 0 && pairs[j - 1].first < key.first) {
            pairs[j] = pairs[j - 1];
            --j;
        }
        pairs[j] = key;
    }
}

void PmergeMe::insertPend(std::vector<int>& mainList, const std::vector<std::pair<int, int> >& pairs) {
    for (size_t i = 0; i < pairs.size(); ++i)
        mainList.insert(std::lower_bound(mainList.begin(), mainList.end(), pairs[i].second), pairs[i].second);
}

void PmergeMe::insertExtra(std::vector<int>& mainList, int extra) {
    if (extra != -1)
        mainList.insert(std::lower_bound(mainList.begin(), mainList.end(), extra), extra);
}

void PmergeMe::fordJohnsonSort(std::vector<int>& mainList) {
    if (mainList.size() <= 1) return;
    std::vector<std::pair<int, int> > pairs;
    int extra;
    createPairs(mainList, pairs, extra);
    mainList.clear();
    for (size_t i = 0; i < pairs.size(); ++i)
        mainList.push_back(pairs[i].first);
    pairInsertionSort(pairs);
    fordJohnsonSort(mainList);
    insertPend(mainList, pairs);
    insertExtra(mainList, extra);
}

void PmergeMe::sortWithVector(std::vector<int>& data) {
    fordJohnsonSort(data);
}

// DEQUE IMPLEMENTATION (similar structure as vector)
void PmergeMe::createPairs(const std::deque<int>& deq, std::deque<std::pair<int, int> >& pairs, int& extra) {
    pairs.clear();
    extra = -1;
    for (size_t i = 0; i + 1 < deq.size(); i += 2) {
        pairs.push_back(std::make_pair(std::max(deq[i], deq[i+1]), std::min(deq[i], deq[i+1])));
    }
    if (deq.size() % 2 != 0) extra = deq.back();
}

void PmergeMe::pairInsertionSort(std::deque<std::pair<int, int> >& pairs) {
    for (size_t i = 1; i < pairs.size(); ++i) {
        std::pair<int, int> key = pairs[i];
        size_t j = i;

        // Orden descendente (mayor a menor según first)
        while (j > 0 && pairs[j - 1].first < key.first) {
            pairs[j] = pairs[j - 1];
            --j;
        }
        pairs[j] = key;
    }
}

void PmergeMe::insertPend(std::deque<int>& mainList, const std::deque<std::pair<int, int> >& pairs) {
    for (size_t i = 0; i < pairs.size(); ++i)
        mainList.insert(std::lower_bound(mainList.begin(), mainList.end(), pairs[i].second), pairs[i].second);
}

void PmergeMe::insertExtra(std::deque<int>& mainList, int extra) {
    if (extra != -1)
        mainList.insert(std::lower_bound(mainList.begin(), mainList.end(), extra), extra);
}

void PmergeMe::fordJohnsonSort(std::deque<int>& mainList) {
    if (mainList.size() <= 1) return;
    std::deque<std::pair<int, int> > pairs;
    int extra;
    createPairs(mainList, pairs, extra);
    mainList.clear();
    for (size_t i = 0; i < pairs.size(); ++i)
        mainList.push_back(pairs[i].first);
    pairInsertionSort(pairs);
    fordJohnsonSort(mainList);
    insertPend(mainList, pairs);
    insertExtra(mainList, extra);
}

void PmergeMe::sortWithDeque(std::deque<int>& data) {
    fordJohnsonSort(data);
}

void PmergeMe::processInput(const std::vector<int>& input) {
    std::vector<int> vectorData(input);
    std::deque<int> dequeData(input.begin(), input.end());

    printContainer("Before:", input);

    clock_t start = clock();
    sortWithVector(vectorData);
    double timeVector = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1000000;

    start = clock();
    sortWithDeque(dequeData);
    double timeDeque = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1000000;

    printContainer("After (vector):", vectorData);
    printContainer("After (deque):", dequeData);
    
    std::cout << "Time with std::vector: " << timeVector << " us\n";
    std::cout << "Time with std::deque: " << timeDeque << " us\n";
}
