//
//  BakedGood.cpp
//  Main Lab 9: Bakery
//
//  Created by Ryn Stroud on 11/28/19.
//  Copyright © 2019 Ryn Stroud. All rights reserved.
//

#include "BakedGood.h"
//Default constructor
BakedGood::BakedGood() {
    basePrice = 0;
}

//Parameterized constructor
BakedGood::BakedGood(double basePrice) {
    this->basePrice = basePrice;
}

string BakedGood::ToString() {
    string newStr = "";
    newStr = "($" + to_string(basePrice) + ")";
    return newStr;
}

void BakedGood::SetQuantity(int quantity) {
    this->quantity = quantity;
}

int BakedGood::GetQuantity() {
    return quantity;
}
