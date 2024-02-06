add_executable(income_calculator_tests 
    IncomeCalculatorTest.cpp
    IncomeCalculatorFixture.hxx
)
target_include_directories(income_calculator_tests PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(income_calculator_tests
    PRIVATE
        CONAN_PKG::gtest
        IncomeCalculator
)

gtest_discover_tests(income_calculator_tests)
