#include "car.h"
using namespace std;

Car::Car(string mk, string mdl, int yr, string cl, int mi, int x, int y){
    make = mk;
    model = mdl;
    year = yr;
    color = cl;
    miles = mi;
    xpos = x;
    ypos = y;
}

void Car::goForward(int y)
{
    ypos += y;
    miles += y;
}

void Car::goBackward(int y)
{
    ypos -= y;
    miles += y;
}

void Car::goLeft(int x)
{
    xpos -= x;
    miles += x;
}

void Car::goRight(int x)
{
    xpos += x;
    miles += x;
}

void Car::changeColor(string cl)
{
    color = cl;
}

string Car::getMake()
{
    return make;
}

string Car::getModel()
{
    return model;
}

int Car::getYear()
{
    return year;
}

string Car::getColor()
{
    return color;
}

int Car::getMiles()
{
    return miles;
}

int Car::getXPos()
{
    return xpos;
}

int Car::getYPos()
{
    return ypos;
}