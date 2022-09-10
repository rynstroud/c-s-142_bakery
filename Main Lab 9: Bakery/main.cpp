//
//  main.cpp
//  Main Lab 9: Bakery
//
//  Created by Ryn Stroud on 11/28/19.
//  Copyright © 2019 Ryn Stroud. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>

#include "CupCake.h"
#include "LayerCake.h"
#include "Bread.h"

using namespace std;

void AddBread(vector<BakedGood*>& itemList) {
    string breadVariety = "unassigned";
    int itemQuantity = 0;
    Bread* newBread = nullptr;
    cin >> breadVariety;
    cin >> itemQuantity;
    for (int i = 0; i < itemQuantity; i++) {
        newBread = new Bread(breadVariety);
        itemList.push_back(newBread);
    }
    
}

void AddCupCake(vector<BakedGood*>& itemList) {
    string cupCakeFlavor = "unassigned";
    string cupCakeFrosting = "unassigned";
    string cupCakeSprinkles = "unassigned";
    int itemQuantity = 0;
    CupCake* newCupCake = nullptr;
    cin >> cupCakeFlavor;
    cin >> cupCakeFrosting;
    cin >> cupCakeSprinkles;
    cin >> itemQuantity;
    for (int i = 0; i < itemQuantity; i++) {
        newCupCake = new CupCake(cupCakeFlavor, cupCakeFrosting, cupCakeSprinkles);
        itemList.push_back(newCupCake);
    }
}

void AddLayerCake(vector<BakedGood*>& itemList) {
    string layerCakeFlavor = "unassigned";
    string layerCakeFrosting = "unassigned";
    int cakeNumLayers = 0;
    int itemQuantity = 0;
    LayerCake* newLayerCake = nullptr;
    cin >> layerCakeFlavor;
    cin >> layerCakeFrosting;
    cin >> cakeNumLayers;
    cin >> itemQuantity;
    for (int i = 0; i < itemQuantity; i++) {
        newLayerCake = new LayerCake(layerCakeFlavor, layerCakeFrosting, cakeNumLayers);
        itemList.push_back(newLayerCake);
    }
}

void PrintOrder(vector<BakedGood*> order) {
    cout << "\nOrder Confirmations:\n";
    for (int i = 0; i < order.size(); i++) {
        cout << order.at(i)->ToString() << endl;
    }
}

void PrintInvoice(vector<BakedGood*> order) {
    const int NUM_ROWS = 3;
    const int COL_ONE_WIDTH = 75;
    const int OTHER_COLS_WIDTH = 9;
    const int NUM_DIGITS = 2; //number of digits past decimal place in output
    int quantity = 0;
    int totalQuantity = 0;
    double totalPrice = 0.0;
    bool AlreadyListed = false;
    vector<BakedGood*> invoice;
    string header[NUM_ROWS] = {"Baked Good", "Quantity", "Total"};
    cout << "\n\nInvoice:\n";
    //prints the header
    for (int i = 0; i < NUM_ROWS; i++) {
        if (i == 0) {
            cout << setw(COL_ONE_WIDTH) << left << header[i];
        }
        else {
            cout << setw(OTHER_COLS_WIDTH) << header[i];
        }
    }
    cout << endl;
    
    //finds quantity of each baked good
    for (int i = 0; i < order.size(); i++) {
        quantity = 0;
        AlreadyListed = false;
        for (int j = 0; j < order.size(); j++) {
            if (order.at(i)->ToString() == order.at(j)->ToString()) {
                ++quantity;
            }
        }
        for (int k = 0; k < invoice.size(); k++) {
            if (order.at(i)->ToString() == invoice.at(k)->ToString()) {
                AlreadyListed = true;
            }
        }
        if (!AlreadyListed) {
            order.at(i)->SetQuantity(quantity);
            invoice.push_back(order.at(i));
        }
    }
    
    //Prints array
    for (int i = 0; i < invoice.size(); i++) {
        cout << setw(COL_ONE_WIDTH) << left << invoice.at(i)->ToString() << setw(OTHER_COLS_WIDTH) << invoice.at(i)->GetQuantity() << setw(OTHER_COLS_WIDTH) << fixed << setprecision(NUM_DIGITS) <<  invoice.at(i)->DiscountedPrice() << endl;
        totalQuantity += invoice.at(i)->GetQuantity();
        totalPrice += invoice.at(i)->DiscountedPrice();
    }
    cout << setw(COL_ONE_WIDTH) << left << "Totals" << setw(OTHER_COLS_WIDTH) << totalQuantity << setw(OTHER_COLS_WIDTH) << fixed << setprecision(NUM_DIGITS) <<  totalPrice << endl;
    cout << endl;
}

int main() {
    const string FINISH_SUBORDER = "done";
    string bakedGoodType = "unassigned";
    vector<BakedGood*> subOrder;
    
    cout << "**Bread and Cakes Bakery**\n\n";
    cout << "Enter sub-order (enter \"done\" to finish)\n";
    do {
        cout << "Sub-order: ";
        cin >> bakedGoodType;
        if (bakedGoodType == "Bread") {
            AddBread(subOrder);
        }
        else if (bakedGoodType == "Cupcake") {
            AddCupCake(subOrder);
        }
        else if (bakedGoodType == "Layer-cake") {
            AddLayerCake(subOrder);
        }
        
    } while (bakedGoodType != FINISH_SUBORDER);
    PrintOrder(subOrder);
    PrintInvoice(subOrder);
    cout << "Good Bye\n";
    return 0;
}
