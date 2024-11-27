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
    // Constructor y destructor
    BitcoinExchange();
    ~BitcoinExchange();

    // Carga la base de datos de precios desde un archivo CSV
    void loadDatabase(const std::string &filename);

    // Obtiene el precio más cercano a la fecha dada
    float getPriceForDate(const std::string &date) const;

    // Valida si una fecha tiene el formato correcto
    bool isValidDate(const std::string &date) const;

    // Valida si un valor es positivo y está en el rango permitido
    bool isValidValue(const std::string &value) const;
};

#endif
