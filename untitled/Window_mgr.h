//
// Created by xuda25 on 2022/12/29.
//

#ifndef UNTITLED_WINDOW_MGR_H
#define UNTITLED_WINDOW_MGR_H
#include <iostream>
#include <string>
#include <vector>
#include "Screen.h"
using namespace std;

class Window_mgr
{
public:
    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex);
private:
    vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(Window_mgr::ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}
#endif //UNTITLED_WINDOW_MGR_H
