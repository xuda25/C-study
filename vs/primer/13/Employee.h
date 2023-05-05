#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

using namespace std;


class Employee
{
public:
    Employee() {id = idd++};
    Employee(string nm) : name(nm) {id = idd++;}
    Employee &operator= (Employee &em)
    {
        name = em.name;
        return *this;
    }
    Employee(Employee &em)
    {
        name = em.name;
        id = idd++;
    }
    
private:
    string name;
    int id;
    static int idd;
};

int Employee::idd = 0;


#endif