#include <vector>
#include <iostream>

using namespace std;
int main()
{
    # if defined(__sgi)
        cout << "sig" << endl;
    # endif

    # if defined(__GNUC__)
        cout << "1" << endl;
    # endif

    # ifdef __SGI_STL_VECTOR
        cout << " 2" << endl;
    #endif
}