#include<iostream>

using namespace std;

class Bar
{
    int value;     //const int value;  //如果value是const的，编译器不会自动生成拷贝构造函数和赋值运算符
    string name;   //string &name;     //如果name是引用，编译器不会自动生成拷贝构造函数和赋值运算符

public:
    explicit Bar(string &n,int v=10) : value(v), name(n) {}  
};
int main()
{
    string s1("hello");
    string s2("world");
    Bar bar1(s1),bar2(s2);
    Bar bar3(bar1);                 //没有定义拷贝构造函数，编译器会自动生成一个
    Bar bar4(std::move(bar1));  //没有定义移动构造函数，编译器会自动生成一个
    bar3 = bar2;                    //没有定义赋值运算符，编译器会自动生成一个
    bar4 = std::move(bar2);    //没有定义移动赋值运算符，编译器会自动生成一个
    return 0;
}
