//
//  CupCake.cpp
//  Main Lab 9: Bakery
//
//  Created by Ryn Stroud on 11/28/19.
//  Copyright © 2019 Ryn Stroud. All rights reserved.
//

#include "CupCake.h"

using namespace std;

const double BASE_PRICE = 1.95;

//Default constructor
CupCake::CupCake() : Cake() {
    sprinklesColor = "unassigned";
}

//Parameterized constructor
CupCake::CupCake(string cakeFlavor, string cakeFrosting, string newSprnklColor) : Cake(BASE_PRICE, cakeFlavor, cakeFrosting) {
    const double CREAM_CHEESE_PRICE = 0.2;
    sprinklesColor = newSprnklColor;
    if (frosting == "cream-cheese") {
        basePrice += CREAM_CHEESE_PRICE;
    }
}

double CupCake::GetBasePrice() {
    return basePrice;
}

string CupCake::ToString() {
    string newStr = "";
    newStr = flavor + " cup" + Cake::ToString() + "and " + sprinklesColor + " sprinkles " + BakedGood::ToString();
    return newStr;
}

double CupCake::DiscountedPrice() {
    const int FIRST_DISCOUNT_OCCUR = 2;
    const double FIRST_DISCOUNT_PRICE = 0.30;
    const int SECOND_DISCOUNT_OCCUR = 4;
    const double SECOND_DISCOUNT_PRICE = 0.40;
    double tempPrice = basePrice;
    if (quantity >= SECOND_DISCOUNT_OCCUR) {
        tempPrice = basePrice - SECOND_DISCOUNT_PRICE;
    }
    else if (quantity >= FIRST_DISCOUNT_OCCUR) {
        tempPrice = basePrice - FIRST_DISCOUNT_PRICE;
    }
    discountPrice = quantity * tempPrice;
    return discountPrice;
}
