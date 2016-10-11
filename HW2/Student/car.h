#include <string>
using namespace std;

class Car
{
private:
    string make;
    string model;
    int year;
    string color;
    int miles;
    int xpos;
    int ypos;
public:
    Car(string, string, int, string, int, int, int);
    void goForward(int);
    void goBackward(int);
    void goLeft(int);
    void goRight(int);
    void changeColor(string);
    string getMake();
    string getModel();
    int getYear();
    string getColor();
    int getMiles();
    int getXPos();
    int getYPos();
};