#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 函数模板
template <typename T>
int compare(const T& v1, const T& v2)
{
    if (v1 < v2) return -1;
    if (v1 > v2) return 1;
    return 0;
}

template <typename I, typename T>
I find (I b, I e, const T& v)
{
    while (b != e && *b != v)
        ++b;
    return b;
}

template <typename T, unsigned N>
void print(T (&arr)[N])
{
    for (T elem : arr)
        cout << elem << endl;
}

template <typename T, size_t N>
const T* begin(const T (&a)[N])
{
    return &a[0];
}

template <typename T, size_t N>
const T* end(const T (&a)[N])
{
    return &(a[0] + N);
}

template <typename T, size_t N>
constexpr int arr_size(const T (&arr)[N])
{
    return N;
}

template <typename T, size_t N>
void print(const T (&arr)[N])
{
    for (int i = 0; i < arr_size(arr); ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    cout << compare(1, 1) << endl;
    cout << compare<double>(1.1, 1.2) << endl;

    vector<int> hh{1, 2, 3, 4, 5};
    auto it = find(hh.begin(), hh.end(), 2);
    if (it != hh.end())
        cout << "find" << endl;
}