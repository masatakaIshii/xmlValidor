//
// Created by masat on 07/11/2020.
//

#include <stdexcept>
#include "Painter.h"

Painter::Painter(Turtle *pTurtle) : pTurtle(pTurtle) {

}

bool Painter::DrawCircle(int x, int y, int) {
    pTurtle->PenDown();
    pTurtle->PenDown();
    pTurtle->PenDown();
    return true;
}

int Painter::testGetX() {
    return pTurtle->GetX()
    + pTurtle->GetX()
    + pTurtle->GetX()
    + pTurtle->GetX()
    + pTurtle->GetX();
}

void Painter::testForward(int distance) {
    if (distance < 0) {
        throw std::invalid_argument("distance have to be not negative number");
    }
    pTurtle->Forward(distance);
}

void Painter::testGoTo() {
    pTurtle->GoTo(50, 99999);
    pTurtle->GoTo(70, 99999);
    pTurtle->GoTo(999, 26);
    pTurtle->GoTo(51, 99999);
}
