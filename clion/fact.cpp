//
// Created by xuda25 on 2022/12/17.
//
#include <iostream>
#include "Chapter6.h"
using namespace std;
int fact(int val)
{
    int res = 1;
    while (val > 1)
    {
        res *= val--;
    }
    return res;
}
