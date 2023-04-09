#include<iostream>

using namespace std;

class A
{
public:
    explicit A(string name,int x=0):name_(name),x_(x)
    {
        printf("A::A(string):%s x:%d \n",name_.c_str(),x_);
    }
    ~A()
    {
        printf("A::~A():%s x:%d \n",name_.c_str(),x_);
    }

private:
    string name_;
    int x_;
};

class B
{
public:
    explicit B(int v):v_(v)
    {
        printf("B::B(int):%d \n",v_);
    }
    ~B()
    {
        printf("B::~B():%d \n",v_);
    }
    int v_;
};

class C
{
private:
    A a_;
    B b_;
public:
    explicit C(string aName,int bValue):b_(bValue),a_(aName,b_.v_) //初始化列表的顺序和声明的顺序不一样  初始化的顺序按照声明的顺序来的，而不是按照初始化列表的顺序来的
    {
        printf("C::C(string,int):%s %d \n",aName.c_str(),bValue);
    }
};

int main()
{
    C c("c",1);
    return 0;
}
/**
 * 输出结果: A::A(string):c x:268501009
            B::B(int):1
            C::C(string,int):c 1
            B::~B():1
            A::~A():c x:268501009


    *初始化的顺序按照声明的顺序来的，而不是按照初始化列表的顺序来的
    A a_;
    B b_;
    *这里的初始化顺序就是 a_先初始化，然后b_初始化 所以在C的构造函数中，初始化列表的顺序是b_(bValue),a_(aName,b_.v_)  但是实际上初始化的顺序是a_先初始化，然后b_初始化
     因为b_初始化的时候，b_.v_还没有初始化，所以b_.v_的值是随机的，所以在a_初始化的时候，a_的x_的值是随机的
    解决方法：
        *修改声明的顺序
            b_先声明，然后a_声明
            B b_;
            A a_;
*/