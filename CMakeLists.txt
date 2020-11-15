cmake_minimum_required(VERSION 3.17)
project(xmlValidor)

set(CMAKE_CXX_STANDARD 14)

set(SRCS
        src/use_cases/simpleFunction.cpp
        src/use_cases/simpleFunction2.cpp
        src/utils/FileReader.cpp
        src/models/ElementXml.cpp
        src/models/ChildDtd.cpp
        src/models/ElementDtd.cpp
        src/models/DTD.cpp
        src/infrastructures/factories/ElementDtdFactory.cpp
        src/infrastructures/factories/ChildDtdFactory.cpp
        src/use_cases/Turtle.cpp
        src/use_cases/Painter.cpp
        src/infrastructures/services/XmlParserService.cpp
        src/infrastructures/factories/ElementXmlFactory.cpp )

set(HEADERS
        src/use_cases/simpleFunction.h
        src/use_cases/simpleFunction2.h
        src/utils/FileReader.h
        src/models/ElementXml.h
        src/infrastructures/services/XmlParserService.h
        src/infrastructures/factories/ElementXmlFactory.h)
        
set(TESTSRCS
        test/use_case/simpleFunctionTest.cpp
        test/use_case/simpleFunction2Test.cpp
        test/models/ElementXmlTest.cpp
        src/models/ChildDtd.h
        src/models/ElementDtd.h
        src/models/DTD.h
        src/infrastructures/factories/ElementDtdFactory.h
        src/infrastructures/factories/ChildDtdFactory.h
        src/use_cases/Turtle.h
        src/use_cases/Painter.h
        )
        
set(TESTSRCS
        tests/use_cases/simpleFunctionTest.cpp
        tests/use_cases/simpleFunction2Test.cpp
        tests/use_cases/PainterTests.cpp
        tests/models/ElementXmlTest.cpp
        )

set(TESTHEADERS
        tests/use_cases/Mock/MockTurtle.h
        )

add_executable(xmlValidor src/cli/main.cpp ${SRCS} ${HEADERS})
add_executable(xmlValidatorTest tests/main.cpp ${SRCS} ${HEADERS} ${TESTSRCS})

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