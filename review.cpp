#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#define WTH 5
#define LEN 10;
#define NEXTLINE '\n'

double getAver(int arr[], int size)
{
    int sum = 0;
    double avg;

    for (int i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    avg = sum / size;
    return avg;
}

int main()
{
    srand((unsigned)time(NULL));

    for (int i = 0; i < 10; ++i)
    {
        int j = rand();
        cout << j << " ";
    }
    cout << endl;
    return 0;
}