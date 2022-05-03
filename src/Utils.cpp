#include "Utils.hpp"
#include <algorithm>
#include <numeric>
#include <string>

auto Utils::sumIntegers(std::vector<std::uint64_t> vec) -> std::uint64_t {
    std::uint64_t vec_length = vec.size() - 1;
    std::uint64_t maior_soma{0};

    std::sort(vec.begin(), vec.end());

    for(std::uint64_t i = 0; i < vec_length; i++) {
        if(i == 0) {
            maior_soma = vec[i] + vec[i+1];
        }

        auto soma = vec[i] + vec[i+1];

        if(soma > maior_soma) {
            maior_soma = soma;
        }
    }

    return maior_soma;
}

auto Utils::verificaPalindromo(std::string palavra) -> bool {
    if(palavra.empty()) {
        std::cerr << "Erro: Palavra vazia" << "\n";

        return false;
    }


    auto palavra_ao_contrario = std::accumulate(palavra.rbegin(), palavra.rend(), std::string());

    std::cout << "Palavra: " << palavra << std::endl;

    if(palavra == palavra_ao_contrario) return true;

    return false;
}


auto Utils::transformDate(const std::string &date) -> std::string {
    auto splited = Utils::split(date, "/");

    auto invertedDate = std::accumulate(splited.rbegin(), splited.rend(), std::string());

    return invertedDate;
}

auto Utils::rsortDates(const std::string &date1, const std::string &date2) -> std::pair<std::string, std::string> {

    if (date1 > date2) {
        return {date1, date2};
    }

    return {date2, date1};
}