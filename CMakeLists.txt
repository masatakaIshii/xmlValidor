cmake_minimum_required(VERSION 3.17)
project(xmlValidor)

set(CMAKE_CXX_STANDARD 14)

set(SRCS
        src/use_case/simpleFunction.cpp
        src/use_case/simpleFunction2.cpp
        )
set(HEADERS
        src/use_case/simpleFunction.h
        src/use_case/simpleFunction2.h
        )
set(TESTSRCS
        test/use_case/simpleFunctionTest.cpp
        test/use_case/simpleFunction2Test.cpp
        )
set(TESTHEADERS
        test/use_case/MockRng.h
        )

add_executable(xmlValidor src/main.cpp)
add_executable(xmlValidatorTest test/main.cpp ${SRCS} ${HEADERS} ${TESTSRCS})

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTEST REQUIRED gtest)
if (GTEST_FOUND)
    message("gtest found")
    target_include_directories(xmlValidatorTest PUBLIC ${GTEST_INCLUDE_DIRS})
    target_link_libraries(xmlValidatorTest PUBLIC ${GTEST_LIBRARIES})
endif ()