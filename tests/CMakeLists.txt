# Configuração dos testes no CMake/GoogleTest

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)
set(CMAKE_CXX_STANDARD 17)

set(srcdir "${CMAKE_CURRENT_SOURCE_DIR}")
set(msrcdir "${CMAKE_CURRENT_SOURCE_DIR}/../src")
set(mainbinary "${CMAKE_CURRENT_SOURCE_DIR}/../bin")

file(
        GLOB PROJECT_SOURCES
        "${msrcdir}/Utils.cpp"
)

file(
        GLOB ALL_TESTS_SOURCES
        "${srcdir}/*.cpp"
)

set(TEST_COMPILE_FLAGS -Wno-disabled-macro-expansion -Wno-global-constructors -std=c++17 -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded -Wno-exit-time-destructors -Wno-global-constructors)

add_executable(maintest_binary ${ALL_TESTS_SOURCES} ${PROJECT_SOURCES})

target_compile_options(maintest_binary PUBLIC ${TEST_COMPILE_FLAGS})
target_link_libraries(maintest_binary GTest::GTest GTest::Main)
gtest_discover_tests(maintest_binary)

