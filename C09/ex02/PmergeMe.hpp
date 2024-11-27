#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <sstream>
#include <cstdlib>
#include <algorithm>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();

    void processInput(const std::vector<int>& input);

private:
    void sortWithVector(std::vector<int>& data);
    void sortWithDeque(std::deque<int>& data);

    template <typename Container, typename SortFunction>
    Container measureTime(Container data, SortFunction sortFunction, const std::string& containerName);

    template <typename Container>
    void printContainer(const std::string& message, const Container& data);
};

#endif
