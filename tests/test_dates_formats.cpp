#include <gtest/gtest.h>
#include "../src/Utils.hpp"

static auto fillDates() -> std::vector<std::pair<std::string, std::string>> {
    std::vector<std::pair<std::string, std::string>> vec;
    vec.emplace_back("01/01/2021", "20220101");
    vec.emplace_back("01/06/2005", "20050801");
    vec.emplace_back("02/04/2015", "20500928");
    vec.emplace_back("28/09/2050", "20150928");
    vec.emplace_back("31/08/2007", "20200220");
    vec.emplace_back("25/03/2010", "20080419");
    vec.emplace_back("20/02/2020", "20040230");
    vec.emplace_back("19/04/2008", "20070525");
    vec.emplace_back("25/01/2022", "20220401");
    vec.emplace_back("02/05/2022", "20220302");
    vec.emplace_back("03/05/2022", "20050601");


    return vec;
}
// NOLINTNEXTLINE(hicpp-special-member-functions)
TEST(ConvertDateFormat, TestaVariosFormatos) {
    EXPECT_EQ(Utils::transformDate("01/01/2021"), "20210101");
    EXPECT_EQ(Utils::transformDate("01/01/2022"), "20220101");
    EXPECT_EQ(Utils::transformDate("05/03/2009"), "20090305");
    EXPECT_EQ(Utils::transformDate("01/06/2005"), "20050601");
    EXPECT_EQ(Utils::transformDate("02/04/2015"), "20150402");
    EXPECT_EQ(Utils::transformDate("28/09/2050"), "20500928");
    EXPECT_EQ(Utils::transformDate("31/08/2007"), "20070831");
    EXPECT_EQ(Utils::transformDate("25/03/2010"), "20100325");
    EXPECT_EQ(Utils::transformDate("20/02/2020"), "20200220");
    EXPECT_EQ(Utils::transformDate("19/04/2008"), "20080419");
    EXPECT_EQ(Utils::transformDate("25/01/2022"), "20220125");
    EXPECT_EQ(Utils::transformDate("02/05/2022"), "20220502");
    EXPECT_EQ(Utils::transformDate("03/05/2022"), "20220503");
}

// NOLINTNEXTLINE(hicpp-special-member-functions)
TEST(RSortDates, TestaOrdenacaoDasDatasInvertidas) {
    auto vec = fillDates();

    for(const auto &dates : vec) {
        auto formatedDate = Utils::transformDate(dates.first);
        auto result = Utils::rsortDates(formatedDate, dates.second);

        std::cout << "Data1: " << dates.first << " Data2: " << dates.second << std::endl;
        std::cout << "Maior: " << result.first << std::endl;
        std::cout << "Menor: " << result.second << std::endl;
    }
}

TEST(sumIntegers, TestMaiorSoma) {
    std::vector<std::uint64_t> my_vec{5, 2, 3, 4, 1};
    auto result = Utils::sumIntegers(my_vec);

    EXPECT_TRUE(result);
    std::cout << result << std::endl;
}

TEST(verificaPalindromo, TestPalavraIgual) {

    std::string palavra = "subinoonibus1";
    auto result = Utils::verificaPalindromo(palavra);
    if(result) {
        std::cout << palavra << " é um palindromo" << std::endl;
    } else {
        std::cout << palavra << " não é um palindromo" << std::endl;
    }

    EXPECT_TRUE(result);
}

