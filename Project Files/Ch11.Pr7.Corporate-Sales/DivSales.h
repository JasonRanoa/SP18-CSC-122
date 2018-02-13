//
// Created by TheLoneWoof on 2/12/18.
//

#ifndef CH11_PR7_CORPORATE_SALES_DIVSALES_H
#define CH11_PR7_CORPORATE_SALES_DIVSALES_H


class DivSales {

private:
    static double totalCorporateSales;
    double quarterSales[4];

public:
    static double getTotalCorporateSales();
    void setSales(double, double, double, double);
    double getSales(int) const;

};


#endif //CH11_PR7_CORPORATE_SALES_DIVSALES_H
