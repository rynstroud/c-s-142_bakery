//
//  Bread.cpp
//  Main Lab 9: Bakery
//
//  Created by Ryn Stroud on 11/28/19.
//  Copyright © 2019 Ryn Stroud. All rights reserved.
//

#include "Bread.h"

using namespace std;

const double BASE_PRICE = 4.50;

//Default constructor
Bread::Bread() : BakedGood() {
    variety = "unassigned";
}

//Parameterized constructor
Bread::Bread(string breadVariety) : BakedGood(BASE_PRICE){
    variety = breadVariety;
}

string Bread::ToString() {
    string newStr = "";
    newStr = variety + " Bread "  + BakedGood::ToString();
    return newStr;
}

double Bread::GetBasePrice() {
    return basePrice;
}

double Bread::DiscountedPrice() {
    const int FREE_BREAD = 3;
    discountPrice = basePrice * (quantity - (quantity / FREE_BREAD) );
    return discountPrice;
}
