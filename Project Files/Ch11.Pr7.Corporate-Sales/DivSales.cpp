//
// Created by TheLoneWoof on 2/12/18.
//

#include <numeric>
#include <algorithm>
#include <iostream>
#include "DivSales.h"

double DivSales::totalCorporateSales = 0;

double DivSales::getTotalCorporateSales() {
    return totalCorporateSales;
}

void DivSales::setSales(
    double salesQ1, double salesQ2, double salesQ3, double salesQ4
) {
    quarterSales[0] = salesQ1;
    quarterSales[1] = salesQ2;
    quarterSales[2] = salesQ3;
    quarterSales[3] = salesQ4;
    totalCorporateSales += std::accumulate(quarterSales, quarterSales + 4, 0);
}

double DivSales::getSales(int idx) const {
    if (idx < 0 || idx >= 4) {
        std::cout << "Error: Invalid index for quarter. \n";
        std::cout << "Index must be from 0 to 3 inclusive. \n";
        exit(-404);
    }
    return quarterSales[idx];
}