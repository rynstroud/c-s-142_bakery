//
//  LayerCake.h
//  Main Lab 9: Bakery
//
//  Created by Ryn Stroud on 11/28/19.
//  Copyright © 2019 Ryn Stroud. All rights reserved.
//

#ifndef LayerCake_h
#define LayerCake_h

//create a LayerCake class derived from cake
#include "Cake.h"

using namespace std;

class LayerCake : public Cake {
public:
    LayerCake();
    LayerCake(string cakeFlavor, string cakeFrosting, int newNumLayers);
    void SetNumLayers(int cakeNumLayers);
    int GetNumLayers();
    double GetBasePrice();
    string ToString();
    double DiscountedPrice();
private:
    int numLayers;
};

#endif /* LayerCake_h */
