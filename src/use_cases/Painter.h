//
// Created by masat on 07/11/2020.
//

#ifndef XMLVALIDOR_PAINTER_H
#define XMLVALIDOR_PAINTER_H

#include "Turtle.h"

class Painter {
public:
    Painter(Turtle *pTurtle);
    bool DrawCircle(int x, int y, int h);
    int testGetX();
    void testForward(int distance);
    void testGoTo();

private:
    Turtle *pTurtle;
};
#endif //XMLVALIDOR_PAINTER_H
