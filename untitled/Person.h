//
// Created by xuda25 on 2023/1/14.
//

#ifndef UNTITLED_PERSON_H
#define UNTITLED_PERSON_H
#include <iostream>
#include <string>
#include <cctype>
#include <iterator>
#include <vector>
using namespace std;
struct Person;
istream &read(istream &io, Person &p);

struct Person
{
    friend istream &read(istream &io, Person &p);
    friend ostream &print(ostream &os, const Person &p);
public:
    Person() = default;
    Person(string &name, string &address) : name(name), address(address) {}
    explicit Person(istream &is)
    {
        read(is, *this);
    }
    string showName() const
    {
        return name;
    }
    string showAdd() const
    {
        return address;
    }
private:
    string name;
    string address;

};

istream &read(istream &io, Person &p)
{
    io >> p.name >> p.address;
    return io;
}

ostream &print(ostream &os, const Person &p)
{
    os << p.name << " " << p.address;
    return os;
}
#endif //UNTITLED_PERSON_H
