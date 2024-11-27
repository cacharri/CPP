#include "BitcoinExchange.hpp"

std::string removeSpaces(const std::string &input) {
    std::string result;
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] != ' ') {
            result += input[i];
        }
    }
    return result;
}


// Procesa un archivo de entrada con pares "fecha | valor"
void processInputFile(const std::string &filename, BitcoinExchange &exchange) {
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        throw std::runtime_error("Error: could not open input file.");
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string date, value;

        // Divide la línea en fecha y valor con el delimitador '|'
        if (std::getline(ss, date, ',') && std::getline(ss, value)) {
            date = removeSpaces(date);  // Elimina espacios en la fecha
            value = removeSpaces(value);  // Elimina espacios en el valor


            try {
                // Valida la fecha y el valor
                if (!exchange.isValidDate(date)) {
                    std::cerr << "Error: Invalid date format -> " << date << std::endl;
                    continue;
                }
                if (!exchange.isValidValue(value)) {
                    std::cerr << "Error: Invalid value -> " << value << std::endl;
                    continue;
                }

                // Obtiene el precio más cercano y calcula el resultado
                float price = exchange.getPriceForDate(date);
                float inputValue = std::atof(value.c_str());
                std::cout << date << " => " << value << " = " << (price * inputValue) << std::endl;
            } catch (const std::exception &e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        } else {
            std::cerr << "Error: Malformed line -> " << line << std::endl;
        }
    }

    inputFile.close();
}


int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }
    try {
        BitcoinExchange exchange;
        exchange.loadDatabase("data.csv");  // Archivo CSV con precios.
        processInputFile(argv[1], exchange);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
