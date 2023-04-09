/*
主要是性能问题，对于内置类型，如int, float等，使用初始化类表和在构造函数体内初始化差别不是很大，
但是对于类类型来说，最好使用初始化列表，为什么呢？使用初始化列表少了一次调用默认构造函数的过程，这对于数据密集型的类来说，是非常高效的。
*/

#include<iostream>
using namespace std;

class Foo
{
public:
    int a;
    Foo(){cout<<"Foo()"<<endl;}
    Foo(const Foo& foo){cout<<"Foo(const Foo&)"<<endl;this->a =foo.a ; }
    Foo& operator=(const Foo& f){cout<<"Foo& operator=(const Foo&)"<<endl;this->a = f.a;return *this;}
};

class test1
{   
public:
    Foo foo;    //cout<<"Foo()"<<endl;
    test1(const Foo& f):foo(f){cout<<"test1(const Foo&) 成员初始化列表"<<endl;}
};

class test2
{
    
public:
    Foo foo;  //cout<<"Foo()"<<endl;
    test2(const Foo& f){foo = f;cout<<"test2(const Foo&) 函数体内赋值"<<endl;}
};

int main()
{
    Foo f1;    //cout<<"Foo()"<<endl;
    cout<<"-f1()-"<<endl;
    test1 t1(f1);
    cout<<"-----------------"<<endl;
    Foo f2;    //cout<<"Foo()"<<endl;
    cout<<"-f2()-"<<endl;
    test2 t2(f2);
    return 0;
}
/**
 * 输出结果：
Foo()
-f1()-
Foo(const Foo&)
test1(const Foo&) 成员初始化列表
-----------------
Foo()
-f2()-
Foo()       //多执行了一次 默认构造函数
Foo& operator=(const Foo&)
test2(const Foo&) 函数体内赋值

*/