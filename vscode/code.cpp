#include <iostream>
#include <string>
#include <cctype>
#include <iterator>
#include <vector>
#include "Sales_data.h"
using namespace std;

class Screen
{
public:
    using pos = string::size_type;
    Screen() = default;
    Screen(char c, pos het, pos wih) : contents(het * wih, c), height(het), width(wih) {}

    char get() const {return this->contents[cursor];}
    inline char get(pos het, pos wih) const;
    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen &display(ostream &os) const
    {
        do_display(os);
        return *this;
    }
private:
    string contents;
    pos cursor = 0;
    pos height = 0, width = 0;
    void do_display(ostream &os) const
    {
        os << contents;
    }
};

inline
Screen &Screen::move(Screen::pos r, Screen::pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}
char Screen::get(Screen::pos r, Screen::pos c) const
{
    pos row = r *width;
    return contents[row + c];
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(Screen::pos r, Screen::pos col, char ch)
{
    contents[r*width + col] = ch;
    return *this;
}

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << '\n';
    myScreen.display(cout);
    cout << '\n';
    return 0;
}