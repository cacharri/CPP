#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void processInput(const std::vector<int>& input);

private:
    void sortWithVector(std::vector<int>& data);
    void sortWithDeque(std::deque<int>& data);
    std::vector<int> generateJacobsthalSequence(int n);

    template <typename Container>
    void printContainer(const std::string& message, const Container& data);
    void insertionSort(std::vector<int>& arr);
    void insertionSortq(std::deque<int>& arr);

};

#endif
