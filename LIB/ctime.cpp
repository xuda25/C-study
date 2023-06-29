#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;
// time()
// int main()
// {
//     time_t seconds;

//     time(&seconds);

//     printf("自1970-1-1以来的小时数 = %ld\n", seconds / 3600);
//     return 0;
// }

// ctime()

// int main()
// {
//     time_t curtime;
//     time(&curtime);

//     cout << "当前时间：" << ctime(&curtime) << endl;
//     return 0;
// }


//localtime()

int main()
{
    time_t rawtime;
    tm *info;
    char buffer[80];

    time(&rawtime);

    info = localtime(&rawtime);

    cout << asctime(info);
    return 0;
}