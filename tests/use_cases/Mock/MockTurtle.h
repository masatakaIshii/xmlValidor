//
// Created by masat on 07/11/2020.
//

#ifndef XMLVALIDOR_MOCKTURTLE_H
#define XMLVALIDOR_MOCKTURTLE_H
#include <gmock/gmock.h>
#include "../../../src/use_cases/Turtle.h"

class MockTurtle : public Turtle {
public:
    MOCK_METHOD(void, PenUp, (), (override));
    MOCK_METHOD(void, PenDown, (), (override));
    MOCK_METHOD(void, Forward, (int distance), (override));
    MOCK_METHOD(void, Turn, (int degrees), (override));
    MOCK_METHOD(void, GoTo, (int x, int y), (override));
    MOCK_METHOD(int, GetX, (), (const, override));
    MOCK_METHOD(int, GetY, (), (const, override));
};

#endif //XMLVALIDOR_MOCKTURTLE_H
