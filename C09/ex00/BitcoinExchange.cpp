#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open database file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;
        float price;

        if (std::getline(ss, date, ',') && ss >> price) {
            _priceData[date] = price;
        }
    }
    file.close();
}

float BitcoinExchange::getPriceForDate(const std::string &date) const {
    std::map<std::string, float>::const_iterator it = _priceData.lower_bound(date);

    // Si la fecha está antes del primer elemento
    if (it == _priceData.begin() && it->first > date) {
        throw std::runtime_error("Error: no data for the given date.");
    }

    // Si la fecha es mayor que cualquier elemento en la base de datos
    if (it == _priceData.end() || it->first != date) {
        --it; // Retrocede al elemento más cercano anterior
    }

    return it->second;
}

bool BitcoinExchange::isValidDate(const std::string &date) const {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    return year > 0 && (month >= 1 && month <= 12) && (day >= 1 && day <= 31);
}

bool BitcoinExchange::isValidValue(const std::string &value) const {
    double val = std::atof(value.c_str());
    return val >= 0.0 && val <= 1000.0;
}
