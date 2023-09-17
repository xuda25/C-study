#ifndef SCREEN_H
#define SCREEN_H

#include<string>
#include<iostream>

using namespace std;

template<int H, int W>
class Screen
{
public:
    Screen() : contents(H * W, ' ') {}
    Screen(char c) : contents(H * W, c) {}
    friend class Window_mgr;
    char get() const {return contents[cursor];}  //隐式内连
    inline char get(int, int) const;  //显示内联
    Screen& clear(char = bkground);

    Screen& move(int r, int c);
    Screen& set(char);
    Screen& set(int, int, char);
    Screen& display(ostream& os) {do_display(os); return *this;}
    const Screen& display(ostream& os) const {do_display(os); return *this;}

private:
    static const char bkground = ' ';
    int cursor = 0;
    string contents;
    void do_display(ostream& os) const {os << contents;}
};

#endif