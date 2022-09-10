//
//  CupCake.h
//  Main Lab 9: Bakery
//
//  Created by Ryn Stroud on 11/28/19.
//  Copyright © 2019 Ryn Stroud. All rights reserved.
//

#ifndef CupCake_h
#define CupCake_h
//create a CupCake class derived from Cake
#include "Cake.h"

using namespace std;

class CupCake : public Cake {
public:
    CupCake();
    CupCake(string cakeFlavor, string cakeFrosting, string newSprnklColor);
    void SetSprinklesColor(string color);
    double GetBasePrice();
    string ToString();
    double DiscountedPrice();
private:
    string sprinklesColor;
};

#endif /* CupCake_h */
