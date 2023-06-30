#include <iostream>
#include <stdio.h>
#include <ctime>
#include <stdlib.h>
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

// int main()
// {
//     time_t rawtime;
//     tm *info;
//     char buffer[80];

//     time(&rawtime);

//     info = localtime(&rawtime);

//     cout << asctime(info);
//     return 0;
// }

//clock()

// int main()
// {
//     clock_t start_t, end_t, total_t;

//     start_t = clock();
//     cout << "start:" << start_t << endl;

//     for (int i = 0; i < 9999999; ++i)
//     {
//         ;
//     }
//     end_t = clock();
//     cout << "end:" << end_t << endl;

//     total_t = (end_t - start_t) / CLOCKS_PER_SEC;
//     cout << "total:" << total_t << endl;
//     return 0;
// }

//asctime() gmtime()

// #define BST (+1)
// #define CCT (+8)
// int main()
// {
//     time_t rawtime;
//     tm *info;
    
//     time(&rawtime); //获取当前时间
//     info = localtime(&rawtime);
//     cout << asctime(info) << endl;

//     info = gmtime(&rawtime);

//     cout << "伦敦" << (info->tm_hour + BST) % 24 << "," << info->tm_min << endl;
//     cout << "中国" << (info->tm_hour + CCT) % 24 << "," << info->tm_min << endl;
// }

// strftime()
// int main()
// {
//     time_t rawtime;
//     tm* info;
//     char buffer[80];

//     time(&rawtime); //获取现在时间

//     info = localtime(&rawtime);

//     strftime(buffer, 80, "%x - %I:%M%p", info);
//     cout << buffer << endl;
//     return 0;
// }

//mktime()
// int main ()
// {
//    int ret;
//    struct tm info;
//    char buffer[80];

//    info.tm_year = 2001 - 1900;
//    info.tm_mon = 7 - 1;
//    info.tm_mday = 4;
//    info.tm_hour = 0;
//    info.tm_min = 0;
//    info.tm_sec = 1;
//    info.tm_isdst = -1;

//    ret = mktime(&info);
//    if( ret == -1 )
//    {
//        printf("错误：不能使用 mktime 转换时间。\n");
//    }
//    else
//    {
//       strftime(buffer, sizeof(buffer), "%c", &info );
//       cout << buffer;
//    }

//    return(0);
// }

// difftime()
int main()
{
    time_t start, end;
    double diff;

    time(&start);

    _sleep(5);

    time(&end);

    diff = difftime(end, start);

    cout << diff << endl;
    return 0;
}