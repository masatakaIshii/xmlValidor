cmake_minimum_required(VERSION 3.17)
project(xmlValidor)

set(CMAKE_CXX_STANDARD 14)

set(SRCS
        src/use_case/simpleFunction.cpp
        src/use_case/simpleFunction2.cpp
        src/utils/FileReader.cpp
        src/model/ChildDtd.cpp
        src/model/ElementDtd.cpp
        src/model/DTD.cpp
        src/infrastructure/factory/ElementDtdFactory.cpp
        src/infrastructure/factory/ChildDtdFactory.cpp
        src/use_case/Turtle.cpp
        src/use_case/Painter.cpp
        )
set(HEADERS
        src/use_case/simpleFunction.h
        src/use_case/simpleFunction2.h
        src/utils/FileReader.h
        src/model/ChildDtd.h
        src/model/ElementDtd.h
        src/model/DTD.h
        src/infrastructure/factory/ElementDtdFactory.h
        src/infrastructure/factory/ChildDtdFactory.h
        src/use_case/Turtle.h
        src/use_case/Painter.h
        )
set(TESTSRCS
        test/use_case/simpleFunctionTest.cpp
        test/use_case/simpleFunction2Test.cpp
        test/use_case/PainterTests.cpp
        )
set(TESTHEADERS
        test/use_case/Mock/MockTurtle.h
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

pkg_check_modules(GMOCK REQUIRED gmock)
if (GMOCK_FOUND)
    message("gmock found")
    target_include_directories(xmlValidatorTest PUBLIC ${GMOCK_INCLUDE_DIRS})
    target_link_libraries(xmlValidatorTest PUBLIC ${GMOCK_LIBRARIES})
endif ()