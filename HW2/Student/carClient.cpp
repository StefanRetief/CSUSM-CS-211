#include <iostream>
#include "car.h"
using namespace std;

int main()
{
    Car celica("Toyota", "Celica", 2016, "White", 0, 0, 0);
    Car civic("Honda", "Civic", 2008, "Black", 20000, 2,2);
    
    celica.goForward(3);
    civic.goBackward(1);
    celica.goRight(2);
    civic.goLeft(5);
    
    cout << celica.getColor() << " " << celica.getMake() << " " << celica.getModel() << " (" << celica.getYear() << ") is at location (" << celica.getXPos() << "," << celica.getYPos() << ") with mileage " << celica.getMiles() << " miles." << endl;
    
    cout << civic.getColor() << " " << civic.getMake() << " " << civic.getModel() << " (" << civic.getYear() << ") is at location (" << civic.getXPos() << "," << civic.getYPos() << ") with mileage " << civic.getMiles() << " miles." << endl;
    
    celica.changeColor("Red");
    
    cout << celica.getColor() << " " << celica.getMake() << " " << celica.getModel() << " (" << celica.getYear() << ") is at location (" << celica.getXPos() << "," << celica.getYPos() << ") with mileage " << celica.getMiles() << " miles." << endl;
    
    return 0;
}