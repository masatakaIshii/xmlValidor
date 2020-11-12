//
// Created by masat on 07/11/2020.
//

#ifndef XMLVALIDOR_TURTLE_H
#define XMLVALIDOR_TURTLE_H
class Turtle {
public:
    virtual ~Turtle() {};
    virtual void PenUp() = 0;
    virtual void PenDown() = 0;
    virtual void Forward(int distance) = 0;
    virtual void Turn(int degrees) = 0;
    virtual void GoTo(int x, int y) = 0;
    virtual int GetX() const = 0;
    virtual int GetY() const = 0;
};
#endif //XMLVALIDOR_TURTLE_H
