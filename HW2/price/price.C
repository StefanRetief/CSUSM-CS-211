#include "price.h"
//using namespace std;

Price::Price()
{
    dollars= 0;
    cents = 0;
}

Price::Price(int dollars, int cents)
{
    this->dollars = dollars;
    this->cents = cents;
}

Price Price::operator+(const Price& second)
{
    double newDollar = this->dollars + second.dollars;
    double newCents = this->cents + second.cents;
    
    do {
        newDollar += 1;
        newCents -= 100;
    } while (newCents >= 100);
    
    Price newPrice(newDollar, newCents);
    
    return newPrice;
}

Price Price::operator-(const Price& other)
{
    //convert each price to cents
    int p1 = this->dollars * 100 + this->cents; int p2 = other.dollars * 100 + other.cents;
    int diff;
    int d, c;
    
    //if the first price is greater than or equal to the second price
    if(p1 >= p2) {
        diff = p1 - p2;
        d = diff/100;
        c = diff%100;
    }
    else //if the first price is less than the second price
    {
        d = -9999999;
        c = -9999999;//Don't do the math if p2 is less than p1 return negOb;
    }
    Price diffob(d, c);
    return diffob;
}

int Price::getDollars() const
{
    return dollars;
}

int Price::getCents() const
{
    return cents;
}