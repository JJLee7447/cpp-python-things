编译并生成可执行文件
`g++ filename.cpp -o output`
此命令会将filename.cpp编译成可执行文件，并将该可执行文件设为`output`。

编译并加入调试信息
`g++ -g filename.cpp -o output`
此命令会将filename.cpp编译成可执行文件，并加入调试信息。

指定编译器版本
`g++-version filename.cpp -o output`
该命令可指示使用特定版本的编译器进行编译和链接。

强制编译
`g++ -Werror filename.cpp -o output`
该命令会强制编译并产生编译错误。

指定编译器选项
`g++ -std=c++11 filename.cpp -o output`
该命令会指定使用C++11标准进行编译。

编译多个源文件
`g++ file1.cpp file2.cpp -o output`
该命令会将file1.cpp和file2.cpp编译成可执行文件，并将该可执行文件设为``output`。

批量编译
`g++ *.cpp -o output`
该命令会将当前目录下所有.cpp文件编译成可执行文件，并将该可执行文件设为`output`。

以上是一些常用的g++编译命令，更多详细信息可以使用`"g++ --help"`来获得。