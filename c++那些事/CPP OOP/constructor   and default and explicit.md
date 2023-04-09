# 构造函数

### 默认构造函数

* 不带任何参数的构造函数
* 参数全是带默认实参的构造函数

示例

```c++
#include<iostream>
class X
{
public:
    int a_;
    double b_;

    X(){}//无参默认构造函数
    X(int a=1,double b=1.222):a_(a),b_(b){}  //带默认参数的默认构造函数
};

int main()
{
            //使用默认构造函数
    X x;   //报错编译器无法识别到底是哪一个构造函数
           // call of overloaded 'X()' is ambiguous
    
    X x();  //这种方法是错误的定义了一个函数而非对象 并不能调用默认无参的构造函数
    std::cout << x.a_<<x.b_<<std::endl;
}
```

当我们把删除其中一个构造函数就可以构造对象

### 自定义构造函数

如果构造函数==只接受一个实参==，则它实际上定义了转换为此类类型的隐式转换机制，我们把这种构造函数称作==转换构造函数==

```c++
#include<iostream>
class X
{
public:
    int a_;
    double b_;
    X();  //X()=default;
    X(int a):a_(a){}
};

int main()
{
    X x;  
    /*
     * 报错 没有匹配的构造函数 这里的默认无参构造函数只进行了声明没有定义如果要使用默认构造函数可以有两种方法 
     * 1 X(){} 手动定义
     * 2 X()=default 自动生成 X(){}
     */
    X x=1; //成功 隐式转换
    std::cout << x.a_<<x.b_<<std::endl;
}
```

如果要抑制 上面的隐式转换 可以在带参的构造函数前用 `explicit `关键字显式的声明构造函数  **`explicit` 关键字只能用于只接受一个实参的构造函数的显式声明** 。在后面介绍`explicit `与带默认实参的构造函数的关系

```c++
#include<iostream>
class X
{
public:
    int a_;
    double b_;
    X()=default;
    explicit X(int a):a_(a){}  //显式声明
    X(int a,double b):a_(a),b_(b){}
};

int main()
{
    X x=1; //报错 使用 explicit 抑制了隐式转换  
    std::cout << x.a_<<" "<<x.b_<<std::endl;
}
```

### 构造函数默认实参

```c++
#include<iostream>
class X
{
public:
    int a_;
    double b_;
    char c_;
    X(int a):a_(a){}
    X(int a,double b=0,char c='0'):a_(a),b_(b),c_(c){}
};

int main()
{
    X x(1); //报错 无法区分到第一X(int),还是X(int ,doubel =0)
    //std::cout << x.a_<<x.b_<<std::endl;
    system("pause");
}
```

接下来我们看这加上 `explicit `的几种情况

1. 

```c++
{
    explicit X(int a):a_(a){}
    X(int a,double b=0,char c='0'):a_(a),b_(b),c_(c){}
}
{
    X x=1 //成功 调用第二个带有一个默认实参的构造函数
}
```

2. 

```c++
{
    X(int a):a_(a){}
    explicit X(int a,double b=0,char c='0'):a_(a),b_(b),c_(c){}
}
{
    X x=1 //成功 调用第一个带有一个参数的构造函数
}
```

3. 

```c++
{
    explicit X(int a):a_(a){}
    explicit X(int a,double b=0,char c='0'):a_(a),b_(b),c_(c){}
}
{
    X x=1 //错误 这里我们将两个构造函数都进行了显式的声明
}
```



