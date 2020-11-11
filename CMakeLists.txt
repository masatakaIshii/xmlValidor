cmake_minimum_required(VERSION 3.17)
project(xmlValidor)

set(CMAKE_CXX_STANDARD 14)

set(SRCS
        src/use_cases/example_gtest/simpleFunction.cpp
        src/use_cases/example_gtest/simpleFunction2.cpp
        src/utils/FileReader.cpp
        src/models/ElementXml.cpp
        src/models/ChildDtd/ChildDtd.cpp
        src/models/ElementDtd.cpp
        src/models/DTD.cpp
        src/infrastructures/factories/ElementDtdFactory.cpp
        src/infrastructures/factories/ChildDtdFactory.cpp
        src/use_cases/example_gtest/Turtle.cpp
        src/use_cases/example_gtest/Painter.cpp
        )

set(HEADERS
        src/use_cases/example_gtest/simpleFunction.h
        src/use_cases/example_gtest/simpleFunction2.h
        src/utils/FileReader.h
        src/models/ElementXml.h
        src/models/ChildDtd/ChildDtd.h
        src/models/ElementDtd.h
        src/models/DTD.h
        src/infrastructures/factories/ElementDtdFactory.h
        src/infrastructures/factories/ChildDtdFactory.h
        src/use_cases/example_gtest/Turtle.h
        src/use_cases/example_gtest/Painter.h
        src/models/ChildDtd/OccurrenceChildDtd.h
        src/models/ChildDtd/IChildDtd.h
        )

set(TESTSRCS
        tests/use_cases/example_gtest/simpleFunctionTest.cpp
        tests/use_cases/example_gtest/simpleFunction2Test.cpp
        tests/use_cases/example_gtest/PainterTests.cpp
        tests/models/ElementXmlTest.cpp
        tests/integration/infrastructures/ElementDtdFactoryTest.cpp
        tests/models/ChildDtdTest.cpp
        tests/models/ElementDtdTest.cpp
        )

set(TESTHEADERS
        tests/use_cases/example_gtest/Mock/MockTurtle.h
        tests/models/Mock/MockChildDtd.h
        )

add_executable(xmlValidor src/cli/main.cpp ${SRCS} ${HEADERS})
add_executable(xmlValidatorTest tests/main.cpp ${SRCS} ${HEADERS} ${TESTHEADERS} ${TESTSRCS})

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTEST REQUIRED gtest)
if (GTEST_FOUND)
    message("gtest found")
    target_include_directories(xmlValidatorTest PUBLIC ${GTEST_INCLUDE_DIRS})
    target_link_libraries(xmlValidatorTest PUBLIC ${GTEST_LIBRARIES})
endif ()

pkg_check_modules(GMOCK REQUIRED gmock)
if (GMOCK_FOUND)
    message("gmock found")
    target_include_directories(xmlValidatorTest PUBLIC ${GMOCK_INCLUDE_DIRS})
    target_link_libraries(xmlValidatorTest PUBLIC ${GMOCK_LIBRARIES})
endif ()