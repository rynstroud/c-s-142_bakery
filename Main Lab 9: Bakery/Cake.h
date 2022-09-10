//
//  Cake.h
//  Main Lab 9: Bakery
//
//  Created by Ryn Stroud on 11/28/19.
//  Copyright © 2019 Ryn Stroud. All rights reserved.
//

#ifndef Cake_h
#define Cake_h

#include "BakedGood.h"
//create pure virtual Cake class derived from BakedGood
class Cake : public BakedGood {
public:
    Cake();
    Cake(double price, string cakeFlavor, string cakeFrosting);
    virtual double GetBasePrice() = 0;
    virtual string ToString();
    virtual double DiscountedPrice() = 0;
protected:
    string flavor;
    string frosting;
};
#endif /* Cake_h */
