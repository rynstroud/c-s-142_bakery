//
//  LayerCake.cpp
//  Main Lab 9: Bakery
//
//  Created by Ryn Stroud on 11/28/19.
//  Copyright © 2019 Ryn Stroud. All rights reserved.
//

#include "LayerCake.h"
using namespace std;

const double BASE_PRICE = 9.00;

//Default constructor
LayerCake::LayerCake() : Cake(){
    numLayers = 0;
}

//Parameterized constructor
LayerCake::LayerCake(string cakeFlavor, string cakeFrosting, int newNumLayers) : Cake(BASE_PRICE, cakeFlavor, cakeFrosting) {
    const double SUBSQ_LAYERS_PRICE = 3.0;
    const double CREAM_CHEESE_PRICE = 1.00;
    const int BEGINNING_LAYERS = 1;
    numLayers = newNumLayers;
    if (numLayers > BEGINNING_LAYERS) {
        basePrice += SUBSQ_LAYERS_PRICE * (numLayers - 1);
    }
    if (frosting == "cream-cheese") {
        basePrice += (CREAM_CHEESE_PRICE * numLayers);
    }
}

void LayerCake::SetNumLayers(int cakeNumLayers) {
    numLayers = cakeNumLayers;
}

int LayerCake::GetNumLayers() {
    return numLayers;
}

double LayerCake::GetBasePrice() {
    return 0.0;
}

string LayerCake::ToString() {
    string newStr = "";
    newStr = to_string(numLayers) + "-layer " + flavor + " " + Cake::ToString() + BakedGood::ToString();
    return newStr;
}

double LayerCake::DiscountedPrice() {
    const int DISCOUNT_PRICE_OCCURS = 3;
    const double DISCOUNT = 2.0;
    double tempPrice = basePrice;
    if (quantity >= DISCOUNT_PRICE_OCCURS) {
        tempPrice = basePrice - DISCOUNT;
    }
    discountPrice = tempPrice * quantity;
    return discountPrice;
}
