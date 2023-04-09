### 条款1 视C++为一个语言联邦

### 条款2 尽量不使用#define

​		C++编译过程：预处理、编译、汇编、链接。对于`#define` 则是在预处理过程中。将条款改为“宁可以编译器替换预处理器”，可能比较好理解。

示例：

`#define ASPECT_RATIO 1.653`

在预处理阶段，预处理器会将代码中`ASPECT_RATIO` 替换成`1.653` ，则`ASPECT_RATIO` 不会被加入到符号表（symbol table）中。当运用此常量但获得一个编译错误信息的时候，错误信息会提示`1.653` 而不是`ASPECT_RATIO` 。如果这个`#define ASPECT_RATIO 1.653` 并非在你写的头文件内，你会这个错误`1.653` 特别茫然。

解决方法：

`const double AspectRatio=1.653;`



### 条款3 尽可能使用const

示例

```cpp
char greeting[]="hell0";
char *p=greeting;                   //p可以修改，greeting也可以修改
const char *p=greeting;				//p可以修改，greeting不可以修改
char *const p=greeting;				//p不可以修改，greeting可以修改
const char *constp=greeting;		//p不可以修改，greeting也不可以修改
```

如果`const` 出现在 ==`*` 左边==，则表式所指的==对象是常量==，`const` 出现在==`*` 号右边==，则==指针是常量。==

```cpp
void func1(const Widget *pw);
void func2(widget const *pw); //func1,func2  都是non-const-pointer,const data
```

STL中的应用：

```cpp
vector<int>vec;
const auto iter = vec.begin();  //iter like a T* const
*iter = 10;                     //OK
itet++;            				//error ,iter is const

auto iter = vec.cbegin();      //iter like const T*  
*iter = 10; 					//error (*iter) is const
it++;							//OK
```

==令函数返回值是一个常量==，往往可以降低因客户的错误而造成意外，又不至于放弃安全性和高效性。举个例子，考虑有理数（rational numbers）

```cpp
class Rational{…………};
const Rational operator * (const Rational &lhs,const Rational &rhs ){}


Rational a,b,c;
(a*b)=c;    //在a*b的结果上 调用operator = 

if(a*b=c)   //这里用户应该写成a*b==c ,但是这种写法如果a*b的返回值不是const ，编译器不会报错，返回值是const可以避免这样的错误。
```

`const` 成员函数

​	将`const` 使用与成员函数的目的，是为了该成员函数可以作用于`const` 对象身上。

注意：两个成员函数只是常量性（constness）不同，是可以重载的。



```cpp
class TextBlock
{
private:
    std::string text;
public:
    TextBlock(std::string str):text(str){}
    const char& operator [] (std::size_t position) const
    {return text[position];}
    char& operator [] (std::size_t position)
    {return text[position];}
};

TextBlock tb("hello");
const TextBlock ctb("world");
std::cout<<tb[0];          //调用 non-const operator []
tb[0]='x';					//OK   返回的是引用，可以修改。
std::cout<<ctb[0];		   //调用 const operator [] 这样子的使用太过造作
ctb[0]= 'x' ;				//error 返回的是const &

void print(const TextBlock &tb)  //作为const & 传参使用是最真实的。 
{std::cout<<tb[0];}               
```



```cpp
#include<iostream>

using std::cout;
class TextBlock
{
private:
    char *ptext;
public:
    TextBlock(char *str):ptext(str){}
     char& operator [] (std::size_t position) const
    {return ptext[position];}

};
int main()
{
    char a[] = "hello";
    const TextBlock tb(a);
    char *p = &tb[0];
    *p = 'k';              
    std::cout << a; //"kello" 
}
```

### 条款4 对象使用前应该被初始化

[成员初始化顺序](./.cpp/条款4对象使用前应该被初始化.cpp)

[构造函数成员初始化列表优于函数体内赋值](./.cpp/条款4构造函数成员初始化列表优于函数体内赋值.cpp)

### 条款5 了解C++默认生成的函数

[C++默认生成的函数](./.cpp/条款5了解C++默认生成的函数.cpp)

### 条款6 不想要的特种成员函数，明确禁止编译器自动生成

morden cpp 做法   

```cpp
class HomeForSale{
public:
    HomeForSale(const HomeForSale &) = delete;  // = delete 声明
    HomeForSale & operator = (const HomeForSale &) = delete;
};

HomeForSale h1;
HomeForSale h2;
HomeforSale h3(h1);  //attempt to copy h1 --should not compile
h1 = h2;			 //attempt to copy h2 --should not compile
```

cpp 98 就算了

### 条款7 为多态基类声明virtual析构函数

```cpp
class TimeKeeper
{
public:
    TimeKeeper(/* args */);
    ~TimeKeeper();
};

class AtomicClock: public TimeKeeper{};  // AtomicClock是TimeKeeper的派生类
class WaterClock: public TimeKeeper{};   // WaterClock是TimeKeeper的派生类
class WristWatch: public TimeKeeper{};   // WristWatch是TimeKeeper的派生类

int main()
{
    TimeKeeper *getTiemKeeper();        // 返回一个指针，指向TimeKeeper的派生类的动态分配对象
    TimeKeeper *ptk = getTiemKeeper();   //ptk指向TimeKeeper的派生类的动态分配对象

    delete ptk;                         // 释放动态分配的对象
    return 0;
}

```

​		当你通过基类指针使用子类，使用完毕后却只从基类删除。同时这个基类的析构函数并不是虚函数(virtual)，也就是不允许子类有自己版本的析构函数，这样就只能删除子类中基类的部分，而子类衍生出来的变量和函数所占用的资源并没有被释放，这就造成了这个对象只被释放了一部分资源的现象，依然会导致内存泄漏。

**解决方法:** 给基类一个虚的析构函数，这样子类就允许拥有自己的析构函数，就能保证被占用的所有资源都会被释放。

```cpp
class TimeKeeper{
  public:
    virtual ~TimeKeeper();
  ....
};
```

### 条款8 析构函数不要抛出异常



### 条款10 operator=返回自身引用

```cpp
```



### 条款20 const引用传递优于按值传递

​		宁以`pass-by-reference-to-const` 替代`pass-by-value`











### 条款30 理解inline

​     
