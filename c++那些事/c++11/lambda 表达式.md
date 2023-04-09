#lambda 表达式

语法形式 

`[ capture list ] ( params ) opt -> ret { body; };`

其中carpture是捕获列表，params是参数，opt是选项，ret则是返回的类型，body则是函数的具体实现。

1. 捕获列表描述了`lambda`表达式可以访问上下文中的哪些变量。
	**`[]` :表示不捕获任何变量**
	**`[=]`：表示按值捕获变量**
	**`[&]`：表示按引用捕获变量**
	**`[this]`：值传递捕获当前的this**
	但是捕获列表不允许变量的重复传递：例如

	`[=,x]`

	上面这种捕获是不允许的，=表示按值的方式捕获所有的变量，x相当于被重复捕获了。

2. `params`表示`lambda`的参数，用在{}中

3. `opt`表示`lambda`的选项

4. `ret`表示`lambda`的返回值，也可以显示指明返回值，`lambda`会自动推断返回值，但是值得注意的是只有当`lambda`的表达式仅有一条`return`语句时，自动推断才是有效的。像下面这种的表达式就需要加上返回类型。



实例演示

```c++
#include <algorithm>
#include <cmath>

void abssort(float* x, unsigned n) {
    std::sort(x, x + n,
        // Lambda expression begins
        [](float a, float b) {
            return (std::abs(a) < std::abs(b));
        } // end of lambda expression
    );
}
```

### lambda capture list

​		Lambda表达式与普通函数最大的区别是，除了可以使用参数以外，Lambda函数还可以通过捕获列表访问一些上下文中的数据。具体地，捕捉列表描述了上下文中哪些数据可以被Lambda使用，以及使用方式（以值传递的方式或引用传递的方式）。语法上，在“`[]`”包括起来的是捕获列表，捕获列表由多个捕获项组成，并以逗号分隔。捕获列表有以下几种形式：

- `[]`表示不捕获任何变量

```cpp
auto function = ([]{
		std::cout << "Hello World!" << std::endl;
	}
);

function();
```

- `[var]`表示值传递方式捕获变量`var`

```cpp
int num = 100;
auto function = ([num]{
		std::cout << num << std::endl;
	}
);

function();
```

- `[=]`表示值传递方式捕获所有**父作用域**的变量（包括`this`）

```cpp
int index = 1;
int num = 100;
auto function = ([=]{
			std::cout << "index: "<< index << ", " 
                << "num: "<< num << std::endl;
	}
);

function();
```

- `[&var]`表示**引用传递**捕捉变量`var`

```cpp
int num = 100;
auto function = ([&num]{
		num = 1000;
		std::cout << "num: " << num << std::endl;
	}
);

function();
```

- `[&]`表示引用传递方式捕捉所有父作用域的变量（包括`this`）

```cpp
int index = 1;
int num = 100;
auto function = ([&]{
		num = 1000;
		index = 2;
		std::cout << "index: "<< index << ", " 
            << "num: "<< num << std::endl;
	}
);

function();
```

- `[this]`表示值传递方式捕捉当前的`this`指针

```cpp
#include <iostream>
using namespace std;
 
class Lambda
{
public:
    void sayHello() {
        std::cout << "Hello" << std::endl;
    };

    void lambda() {
        auto function = [this]{ 
            this->sayHello(); 
        };

        function();
    }
};
 
int main()
{
    Lambda demo;
    demo.lambda();
}
```

- ```c++
	[=, &]
	```

	拷贝与引用混合

	- `[=, &a, &b]`表示以引用传递的方式捕捉变量`a`和`b`，以值传递方式捕捉其它所有变量。

```cpp
int index = 1;
int num = 100;
auto function = ([=, &index, &num]{
		num = 1000;
		index = 2;
		std::cout << "index: "<< index << ", " 
            << "num: "<< num << std::endl;
	}
);

function();
```

- `[&, a, this]`表示以值传递的方式捕捉变量`a`和`this`，引用传递方式捕捉其它所有变量。

不过值得注意的是，捕捉列表**不允许变量重复传递**。下面一些例子就是典型的重复，会导致编译时期的错误。例如：

- `[=,a]`这里已经以值传递方式捕捉了所有变量，但是重复捕捉`a`了，会报错的；
- `[&,&this]`这里`&`已经以引用传递方式捕捉了所有变量，再捕捉`this`也是一种重复。

如果Lambda主体`total`通过引用访问外部变量，并`factor`通过值访问外部变量，则以下捕获子句是等效的：

```cpp
[&total, factor]
[factor, &total]
[&, factor]
[factor, &]
[=, &total]
[&total, =]
```

### lambda parameters

除了捕获列表之外，Lambda还可以接受输入参数。参数列表是可选的，并且在大多数方面类似于函数的参数列表。

```cpp
auto function = [] (int first, int second){
    return first + second;
};
	
function(100, 200);
```

##### 可变规格mutable

`mutable`修饰符， 默认情况下Lambda函数总是一个`const`函数，`mutable`可以取消其常量性。在使用该修饰符时，参数列表不可省略（即使参数为空）。

```cpp
#include <iostream>
using namespace std;

int main()
{
   int m = 0;
   int n = 0;
   [&, n] (int a) mutable { m = ++n + a; }(4);
   cout << m << endl << n << endl;
}
```

##### 异常说明

你可以使用 `throw()` 异常规范来指示 Lambda 表达式不会引发任何异常。与普通函数一样，如果 Lambda 表达式声明 C4297 异常规范且 Lambda 体引发异常，Visual C++ 编译器将生成警告 `throw()` 。

```cpp
int main() // C4297 expected 
{ 
 	[]() throw() { throw 5; }(); 
}
```

在MSDN的异常规范中，明确指出异常规范是在 C++11 中弃用的 C++ 语言功能。因此这里不建议不建议大家使用。

### 返回类型

Lambda表达式的**返回类型会自动推导**。除非你指定了返回类型，否则不必使用关键字。返回型类似于通常的方法或函数的返回型部分。但是，返回类型必须在参数列表之后，并且必须在返回类型->之前包含类型关键字。如果Lambda主体仅包含一个`return`语句或该表达式未返回值，则可以省略Lambda表达式的`return-type`部分。如果Lambda主体包含一个`return`语句，则编译器将从`return`表达式的类型中推断出`return`类型。否则，编译器将返回类型推导为`void`。

```cpp
auto x1 = [](int i){ return i; };
```

### Lambda函数体

Lambda表达式的Lambda主体（标准语法中的复合语句）可以包含普通方法或函数的主体可以包含的任何内容。普通函数和Lambda表达式的主体都可以访问以下类型的变量：

- 捕获变量
- 形参变量
- 局部声明的变量
- 类数据成员，当在类内声明`this`并被捕获时
- 具有静态存储持续时间的任何变量，例如全局变量

```cpp
#include <iostream>
using namespace std;

int main()
{
   int m = 0;
   int n = 0;
   [&, n] (int a) mutable { m = ++n + a; }(4);
   cout << m << endl << n << endl;
}
```

### Lambda表达式的优缺点

##### Lambda表达式的优点

- 可以直接在需要调用函数的位置定义短小精悍的函数，而不需要预先定义好函数

```cpp
std::find_if(v.begin(), v.end(), [](int& item){return item > 2});
```

- 使用Lamdba表达式变得更加紧凑，结构层次更加明显、代码可读性更好

##### Lambda表达式的缺点

- Lamdba表达式语法比较灵活，增加了阅读代码的难度
- 对于函数复用无能为力

### Lambda表达式工作原理

##### Lambda表达式工作原理

编译器会把一个Lambda表达式生成一个匿名类的**匿名对象**，并在类中**重载函数调用运算符**，实现了一个`operator()`方法。

```cpp
auto print = []{cout << "Hello World!" << endl; };
```

编译器会把上面这一句翻译为下面的代码：

```cpp
class print_class
{
public:
	void operator()(void) const
	{
		cout << "Hello World!" << endl;
	}
};
// 用构造的类创建对象，print此时就是一个函数对象
auto print = print_class();
```

##### C++仿函数

仿函数（functor）又称为函数对象（function object）是一个能行使函数功能的类。仿函数的语法几乎和我们普通的函数调用一样，不过作为仿函数的类，都必须重载`operator()`运算符，仿函数与Lamdba表达式的作用是一致的。举个例子：

```cpp
#include <iostream>
#include <string>
using namespace std;
 
class Functor
{
public:
    void operator() (const string& str) const
    {
        cout << str << endl;
    }
};
 
int main()
{
    Functor myFunctor;
    myFunctor("Hello world!");
    return 0;
}
```

### Lamdba表达式适用场景

#### Lamdba表达式应用于STL算法库

##### `for_each`应用实例

```cpp
int a[4] = {11, 2, 33, 4};
sort(a, a+4, [=](int x, int y) -> bool { return x%10 < y%10; } );
for_each(a, a+4, [=](int x) { cout << x << " ";} );
```

##### `find_if`应用实例

```cpp
int x = 5;
int y = 10;
deque<int> coll = { 1, 3, 19, 5, 13, 7, 11, 2, 17 };
auto pos = find_if(coll.cbegin(), coll.cend(), [=](int i) {                 
    return i > x && i < y;
});
```

##### `remove_if`应用实例

```cpp
std::vector<int> vec_data = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int x = 5;
vec_data.erase(std::remove_if(vec.date.begin(), vec_data.end(), [](int i) { 
    return n < x;}), vec_data.end());

std::for_each(vec.date.begin(), vec_data.end(), [](int i) { 
    std::cout << i << std::endl;});
```

#### 短小不需要复用函数场景

###### `sort`函数

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int data[6] = { 3, 4, 12, 2, 1, 6 };
    vector<int> testdata;
    testdata.insert(testdata.begin(), data, data + 6);

    // 对于比较大小的逻辑，使用lamdba不需要在重新定义一个函数
    sort(testdata.begin(), testdata.end(), [](int a, int b){ 
        return a > b; });

    return 0;
}
```

#### Lamdba表达式应用于多线程场景

```cpp
#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

int main()
{
    // vector 容器存储线程
    std::vector<std::thread> workers;
    for (int i = 0; i < 5; i++) 
    {
        workers.push_back(std::thread([]() 
        {
            std::cout << "thread function\n";
        }));
    }
    std::cout << "main thread\n";

    // 通过 for_each 循环每一个线程
    // 第三个参数赋值一个task任务
    // 符号'[]'会告诉编译器我们正在用一个匿名函数
    // lambda函数将它的参数作为线程的引用t
    // 然后一个一个的join
    std::for_each(workers.begin(), workers.end(), [](std::thread &t;) 
    {
        t.join();
    });

    return 0;
}
std::mutex mutex;
std::condition_variable condition;
std::queue<std::string> queue_data;

std::thread threadBody([&]{
	std::unique_lock<std::mutex> lock_log(mutex);
	condition.wait(lock_log, [&]{
		return !queue_data.front();
	});
	std::cout << "queue data: " << queue_data.front();
	lock_log.unlock();
});

queue_data.push("this is my data");
condition.notity_one();

if(threadBody.joinable())
{
	threadBody.join();
}
```

#### Lamdba表达式应用于函数指针与function

```cpp
#include <iostream>
#include <functional>
using namespace std;

int main(void)
{
    int x = 8, y = 9;
    auto add = [](int a, int b) { return a + b; };
    std::function<int(int, int)> Add = [=](int a, int b) { return a + b; };

    cout << "add: " << add(x, y) << endl;
    cout << "Add: " << Add(x, y) << endl;

    return 0;
}
```

#### Lamdba表达式作为函数的入参

```cpp
using FuncCallback = std::function<void(void)>;

void DataCallback(FuncCallback callback)
{
	std::cout << "Start FuncCallback!" << std::endl;
	callback();
	std::cout << "End FuncCallback!" << std::endl;
}

auto callback_handler = [&](){
	std::cout << "This is callback_handler";
};

DataCallback(callback_handler);
```

#### Lamdba表达式在QT中的应用

```cpp
QTimer *timer=new QTimer;
timer->start(1000);
QObject::connect(timer, &QTimer::timeout, [&](){
        qDebug() << "Lambda表达式";
});
int a = 10;
QString str1 = "汉字博大精深";
connect(pBtn4, &QPushButton::clicked, [=](bool checked){
	qDebug() << a <<str1;
	qDebug() << checked;
	qDebug() << "Hua Windows Lambda Button";
});
```
