//
// Created by xuda25 on 2023/1/14.
//

#ifndef UNTITLED_ACCOUNT_H
#define UNTITLED_ACCOUNT_H
#include <iostream>
#include <string>
using namespace std;
class Account
{
public:
    void calculate() {amount += amount * interestRate;}
    static double rate() {return interestRate;}
    static void rate(double);

private:
    string owner;
    double amount;
    static double interestRate;
    static double initRate();
};

void Account::rate(double r)
{

}

double Account::initRate()
{

}
#endif //UNTITLED_ACCOUNT_H
