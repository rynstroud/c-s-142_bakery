//
//  Cake.cpp
//  Main Lab 9: Bakery
//
//  Created by Ryn Stroud on 11/28/19.
//  Copyright © 2019 Ryn Stroud. All rights reserved.
//

#include "Cake.h"

using namespace std;

//Default constructor
Cake::Cake() : BakedGood() {
    flavor = "unassigned";
    frosting = "unassigned";
}

//Parameterized constructor
Cake::Cake(double price, string cakeFlavor, string cakeFrosting) : BakedGood(price) {
    flavor = cakeFlavor;
    frosting = cakeFrosting;
}

/*void Cake::SetFlavor(string cakeFlavor) {
    flavor = cakeFlavor;
}
void Cake::SetFrosting(string cakeFrosting) {
    frosting = cakeFrosting;
}
string Cake::GetFlavor() {
    return flavor;
}
string Cake::GetFrosting() {
    return frosting;
}*/

string Cake::ToString() {
    string newStr = "";
    newStr = "cake with " + frosting + " frosting ";
    return newStr;
}

