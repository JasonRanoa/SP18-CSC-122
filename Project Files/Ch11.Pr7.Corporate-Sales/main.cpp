#include <iostream>
#include <iomanip>
#include "DivSales.h"

int main() {
    DivSales div[6];
    int NUM_DIV = sizeof(div) / sizeof(div[0]);

    // Get sales for all four divs
    for (int i = 0; i < NUM_DIV; i++) {
        static double temp_q[4];
        std::cout << "Enter sales for Division " << i + 1 << " as prompted. \n";
        for (int q = 0; q < 4; q++) {
            std::cout << "   Quarter " << q + 1 << " Sales: ";
            std::cin >> temp_q[q];
        }
        div[i].setSales(temp_q[0], temp_q[1], temp_q[2], temp_q[3]);
        std::cout << "\n";
    }
    std::cout << "\n";

    // Display information in table.
    std::cout << std::fixed << std::showpoint;
    std::cout << "CORPORATE SALES DATA TABLE \n";
    std::cout << "-------------------------------------------------------------------- \n";
    std::cout << "DIVISION  |  Q1 SALES    |  Q2 SALES    |  Q3 SALES    |  Q4 SALES   \n";
    std::cout << "--------  |  ----------  |  ----------  |  ----------  |  ---------- \n";
    for (int i = 0; i < NUM_DIV; i++) {
        std::cout << std::setw(8) << std::setprecision(0) << std::right
                  << i + 1 << "  ";
        for (int q = 0; q < 4; q++) {
            std::cout << "|  " << std::setw(10) << std::setprecision(2)
                      << div[i].getSales(q) << "  ";
        }
        std::cout << "\n";
    }
    std::cout << "-------------------------------------------------------------------- \n";
    std::cout << "TOTAL CORPORATE SALES: ";
    std::cout << std::setw(45) << std::setprecision(2) << std::right
              << DivSales::getTotalCorporateSales() << "\n";
    std::cout << "-------------------------------------------------------------------- \n";
    std::cout << "                                                                 END \n";

    return 0;
}