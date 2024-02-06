cmake_minimum_required(VERSION 3.15)
project(IncomeCalculator 
    VERSION 1.0.0 
    LANGUAGES C CXX
)
enable_testing()

set(CMAKE_C_STANDARD_REQUIRED YES)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_STANDARD 11)
set(EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(bundle_static_library)
include(conan)

conan_cmake_autodetect(settings)
conan_cmake_install(
    PATH_OR_REFERENCE ${CMAKE_SOURCE_DIR}/conanfile.py
    SETTINGS ${settings}
    BUILD missing
    UPDATE
)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS NO_OUTPUT_DIRS)

include(GoogleTest)
add_subdirectory(IncomeCalculator)

