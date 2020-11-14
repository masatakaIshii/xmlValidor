cmake_minimum_required(VERSION 3.17)
project(xmlValidor)

set(CMAKE_CXX_STANDARD 14)

set(SRCS
        src/use_cases/example_gtest/Turtle.cpp
        src/use_cases/example_gtest/Painter.cpp
        src/use_cases/example_gtest/simpleFunction.cpp
        src/use_cases/example_gtest/simpleFunction2.cpp
        src/utils/FileReader.cpp
        src/models/ElementXml.cpp
        src/models/ChildDtd/ChildDtdRef.cpp
        src/models/ElementDtd/ElementDtdRef.cpp
        src/models/DTD/DTDRef.cpp
        src/infrastructures/factories/ElementDtdFactory/ElementDtdFactoryRef.cpp
        src/infrastructures/factories/ChildDtdFactory/ChildDtdFactoryRef.cpp
        src/use_cases/parseDTD/ParseChildDtdRef.cpp
        src/utils/StringUtils.cpp
        )

set(HEADERS
        src/use_cases/example_gtest/Turtle.h
        src/use_cases/example_gtest/Painter.h
        src/use_cases/example_gtest/simpleFunction.h
        src/use_cases/example_gtest/simpleFunction2.h
        src/utils/FileReader.h
        src/models/ElementXml.h
        src/models/ChildDtd/ChildDtdRef.h
        src/models/DTD/DTD.h
        src/models/DTD/DTDRef.h
        src/infrastructures/factories/ElementDtdFactory/ElementDtdFactory.h
        src/infrastructures/factories/ElementDtdFactory/ElementDtdFactoryRef.h
        src/infrastructures/factories/ChildDtdFactory/ChildDtdFactory.h
        src/infrastructures/factories/ChildDtdFactory/ChildDtdFactoryRef.h
        src/models/ChildDtd/OccurrenceChildDtd.h
        src/models/ChildDtd/ChildDtdOnlyOneNameException.h
        src/models/ChildDtd/ChildDtd.h
        src/models/ElementDtd/ElementDtdRef.h
        src/models/ElementDtd/ElementDtd.h
        src/models/ElementDtd/ChildDtdNotFoundException.h
        src/models/DTD/ElementDtdNotFoundException.h
        src/use_cases/parseDTD/ParseChildDtd.h
        src/use_cases/parseDTD/ParseChildDtdRef.h
        src/utils/StringUtils.h
        )

set(TESTSRCS
        tests/use_cases/example_gtest/simpleFunctionTest.cpp
        tests/use_cases/example_gtest/simpleFunction2Test.cpp
        tests/use_cases/example_gtest/PainterTests.cpp
        tests/models/ElementXmlTest.cpp
        tests/integration/infrastructures/ElementDtdFactoryIntegration.cpp
        tests/integration/infrastructures/ChildDtdFactoryIntegration.cpp
        tests/models/ChildDtdTest.cpp
        tests/models/ElementDtdTest.cpp
        tests/models/DTDTest.cpp
        tests/use_cases/parseDTD/ParseChildDtdTest.cpp
        tests/utils/StringUtilsTest.cpp
        tests/integration/parseDTD/ParseChildDtdIntegration.cpp
        )

set(TESTHEADERS
        tests/use_cases/example_gtest/Mock/MockTurtle.h
        tests/models/Mock/MockChildDtd.h
        tests/models/Mock/MockElementDtd.h
        tests/infrastructures/Mock/MockChildDtdFactory.h
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