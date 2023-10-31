#include "mylist.h"

template <typename Item>
struct ListIter
{
    Item* ptr; // 迭代器咯

    ListIter(Item* p = 0) : ptr(p) {}

    Item& operator*() const {return *ptr;}
    Item* operator->() const {return ptr;}

    ListIter& operator++()
    {
        ptr = ptr->next();
        return *this;
    }

    ListItem operator++(int)
    {
        ListIter tmp = *this;
        ++*this;
        return tmp;
    }

    bool operator==(const ListIter& i) const
    {
        return ptr == i.ptr;
    }

    bool operator!=(const ListIter& i) const
    {
        return ptr != i.ptr;
    }

};
