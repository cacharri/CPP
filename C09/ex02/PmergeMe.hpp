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
    std::vector<int> generateJacobsthalSequence(int n);

    // Ford-Johnson for vector
    void createPairs(const std::vector<int>& vec, std::vector<std::pair<int, int> >& pairs, int& extra);
    void pairInsertionSort(std::vector<std::pair<int, int> >& pairs);
    void insertPend(std::vector<int>& mainList, const std::vector<std::pair<int, int> >& pairs);
    void insertExtra(std::vector<int>& mainList, int extra);
    void fordJohnsonSort(std::vector<int>& mainList);
    void sortWithVector(std::vector<int>& data);

    // Ford-Johnson for deque
    void createPairs(const std::deque<int>& deq, std::deque<std::pair<int, int> >& pairs, int& extra);
    void pairInsertionSort(std::deque<std::pair<int, int> >& pairs);
    void insertPend(std::deque<int>& mainList, const std::deque<std::pair<int, int> >& pairs);
    void insertExtra(std::deque<int>& mainList, int extra);
    void fordJohnsonSort(std::deque<int>& mainList);
    void sortWithDeque(std::deque<int>& data);

    // Print container
    template <typename Container>
    void printContainer(const std::string& message, const Container& data) {
        std::cout << message;
        for (typename Container::const_iterator it = data.begin(); it != data.end(); ++it) {
            std::cout << " " << *it;
        }
        std::cout << std::endl;
    }
};

#endif
