//
//  Bread.h
//  Main Lab 9: Bakery
//
//  Created by Ryn Stroud on 11/28/19.
//  Copyright © 2019 Ryn Stroud. All rights reserved.
//

#ifndef Bread_h
#define Bread_h

#include "BakedGood.h"

using namespace std;

//create Bread class derived from BakedGood
class Bread : public BakedGood {
public:
    Bread();
    Bread(string breadVariety);
    double GetBasePrice();
    string ToString();
    double DiscountedPrice();
private:
    string variety;
};

#endif /* Bread_h */
