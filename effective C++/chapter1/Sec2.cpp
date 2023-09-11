// 尽可能用const, enum, inline 替换 #define

class Gameplayer
{
    static const int NumTurns = 5;  // 这是声明哦哦  想不到吧
    int scores[NumTurns];
};

const int Gameplayer::NumTurns;  // 这才是定义啊  但是不用幅值了  因为声明时候默认初始值了 

// 如果编译器不支持in class 初值设置 可以用 enum
class Gameplayer2
{
    enum {NumTurns = 5};
    int scores[NumTurns];
};

// 用 template inline 替代 #define 的宏

// 错误
#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))
// 虽然看得懂  但是每个参数要括号
// 容易出错
int a = 5, b = 0;
int f(int a)
{
    ;
}

int main()
{
CALL_WITH_MAX(++a, b);  //++a两次
CALL_WITH_MAX(++a, b + 10); //++a一次
}


// 正确
template <typename T>
inline void callWithMax(const T& a, const T& b)
{
    f(a > b ? a : b);
}

// 对于单纯常量 最好用const 和 enum
// 对于形式函数宏， 最好改为inline函数替代#define