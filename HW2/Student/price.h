/****************************************************************************/
/* INFO: Price.h                                                            */
/* IMPLEMENTED BY: Stefan Retief                                            */
/* DATE: February 24, 2016                                                  */
/****************************************************************************/

#ifndef PRICE_H
#define PRICE_H
//using namepace std;

class Price
{
private:
    int dollars;
    int cents;
public:
    Price();
    Price(int, int);
    Price operator+(const Price&);
    Price operator-(const Price&);
    int getDollars() const;
    int getCents() const;
};

#endif //PRICE_H
