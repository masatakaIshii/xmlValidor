cmake_minimum_required(VERSION 3.17)
project(xmlValidor)

set(CMAKE_CXX_STANDARD 14)

set(SRCS
        src/use_case/simpleFunction.cpp
        src/use_case/simpleFunction2.cpp
        src/utils/FileReader.cpp
        src/models/ElementXml.cpp)
set(HEADERS
        src/use_case/simpleFunction.h
        src/use_case/simpleFunction2.h
        src/utils/FileReader.h
        src/models/ElementXml.h)
set(TESTSRCS
        test/use_case/simpleFunctionTest.cpp
        test/use_case/simpleFunction2Test.cpp
        test/models/ElementXmlTest.cpp)
set(TESTHEADERS
        test/use_case/MockRng.h
        )

add_executable(xmlValidor src/cli/main.cpp ${SRCS} ${HEADERS})
add_executable(xmlValidatorTest test/main.cpp ${SRCS} ${HEADERS} ${TESTSRCS})

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTEST REQUIRED gtest)
if (GTEST_FOUND)
    message("gtest found")
    target_include_directories(xmlValidatorTest PUBLIC ${GTEST_INCLUDE_DIRS})
    target_link_libraries(xmlValidatorTest PUBLIC ${GTEST_LIBRARIES})
endif ()