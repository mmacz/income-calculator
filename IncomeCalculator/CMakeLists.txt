add_library(IncomeCalculator STATIC
    IncomeCalculator.cpp include/IncomeCalculator.hxx
)
target_include_directories(IncomeCalculator PUBLIC include)

add_subdirectory(unit_tests)
