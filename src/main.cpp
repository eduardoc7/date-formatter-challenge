#include <iostream>
#include "Utils.hpp"

auto main(int argc, const char *argv[]) -> int {
    if (argc != 3 || !Utils::validateEntries(argv[1], argv[2])) {
        std::cerr << "Sintax error\n" << "Usage: " << argv[0] << " DD/MM/AAAA AAAAMMDD" << std::endl;

        return 1;
    }

    // recebe uma lista de inteiro e retorna a maior soma entre dois números

    auto transformed_date = Utils::transformDate(std::string(argv[1]));

    std::cout << "Data formatada: " << transformed_date << std::endl;

    auto calculated_dates = Utils::rsortDates(transformed_date, argv[2]);

    std::cout << "A maior é: " << calculated_dates.first << std::endl;
    std::cout << "E a menor é: " << calculated_dates.second << std::endl;

    return 0;
}
