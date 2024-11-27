#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>

class BitcoinExchange {
private:
    std::map<std::string, float> _priceData; // Almacena la base de datos (fecha -> precio)

public:
    BitcoinExchange();
    ~BitcoinExchange();

    void loadDatabase(const std::string &filename);

    float getPriceForDate(const std::string &date) const;

    bool isValidDate(const std::string &date) const;

    bool isValidValue(const std::string &value) const;
};

#endif
