#pragma once
#ifndef SALE_H
#define SALE_H
#include <vector>
#include "Reservation.h"


class Sale {
public:
    Sale();
    void showMenu(Reservation& r);
    void makeSale();
    void showSales();
    

    Reservation reservation;
    struct mySale
    {
        int id;
        std::string code;
        int card;

        mySale(int _id, std::string _code, int _card)
            : id(_id), code(_code), card(_card) {}
    };
    
    std::vector<mySale>sales;


private:
   
};


#endif 
