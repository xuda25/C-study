//
// Created by xuda25 on 2023/1/14.
//

#ifndef UNTITLED_DEBUG_H
#define UNTITLED_DEBUG_H
using namespace std;
class Debug
{
public:
    constexpr explicit Debug(bool b = true) : hw(b), io(b), other(b) {}
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
    constexpr bool any() {return hw || io || other;}
    void set_io(bool b) {io = b;}
    void set_hw(bool b) {hw = b;}
    void set_other(bool b) {other = b;}
private:
    bool hw; //硬件错误，而非IO错误

    bool io; //IO错误
    bool other; //其他错误
};
#endif //UNTITLED_DEBUG_H
