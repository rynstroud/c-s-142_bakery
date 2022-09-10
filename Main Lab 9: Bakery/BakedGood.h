//
//  BakedGood.h
//  Main Lab 9: Bakery
//
//  Created by Ryn Stroud on 11/28/19.
//  Copyright © 2019 Ryn Stroud. All rights reserved.
//

#ifndef BakedGood_h
#define BakedGood_h

#include <iostream>

using namespace std;

//create pure virtual BakedGood class
class BakedGood {
public:
    BakedGood();
    BakedGood(double basePrice);
    void SetQuantity(int quantity);
    int GetQuantity();
    virtual string ToString();
    virtual double GetBasePrice() = 0;
    virtual double DiscountedPrice() = 0;
protected:
    double basePrice;
    double discountPrice;
    int quantity;
};
#endif /* BakedGood_h */
