在vim窗口 !gcc % && ./a.out 可以编译并允许源文件

    !表示在vim下用shell命令
    %表示当前文件
    !gcc -o a.out % 编译链接当前文件 生成a.out
    &&  同时运行
    ./a.out 运行a.out

gcc -E 可以宏展开，方便读代码

./a.out | python3 seven-seg.py

程序就是状态机

    状态=堆+栈
    初始状态 main函数第一条语句
    迁移 = 执行一条简答语句
     程序的状态机模型 (语义，semantics)

    状态 = stack frame 的列表 (每个 frame 有 PC) + 全局变量
    初始状态 = main(argc, argv), 全局变量初始化
    迁移 = 执行 top stack frame PC 的语句; PC++
    函数调用 = push frame (frame.PC = 入口)
    函数返回 = pop frame

程序 = 计算 + syscall