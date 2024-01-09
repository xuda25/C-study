在vim窗口 !gcc % && ./a.out 可以编译并允许源文件

    !表示在vim下用shell命令
    %表示当前文件
    !gcc -o a.out % 编译链接当前文件 生成a.out
    &&  同时运行
    ./a.out 运行a.out

gcc -E 可以宏展开，方便读代码


./a.out | python3 seven-seg.py