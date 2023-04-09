#include<vector>
#include<iostream>

using std::vector;
using std::cout;
using std::endl;


// rule of three 
// copy assignment/constructor , destructor
/*
    1. 如果类需要析构函数，那么就需要拷贝构造函数和拷贝赋值运算符
    2. 如果类需要拷贝构造函数，那么就需要拷贝赋值运算符
    3. 如果类需要拷贝赋值运算符，那么就需要拷贝构造函数
    定义了这三个函数的任意一个，那么就需要定义其他两个
*/

// rule of five
// copy assignment/constructor , move assignment/constructor , destructor
/*
    1. 如果类需要析构函数，那么就需要拷贝构造函数和拷贝赋值运算符
    2. 如果类需要拷贝构造函数，那么就需要拷贝赋值运算符
    3. 如果类需要拷贝赋值运算符，那么就需要拷贝构造函数
    4. 如果类需要移动构造函数，那么就需要移动赋值运算符
    5. 如果类需要移动赋值运算符，那么就需要移动构造函数
    定义了这五个函数的任意一个，那么就需要定义其他四个
*/

/*
    左值 指的是具有确定的存储地址的对象，可以取地址，并且可以被修改的表达式。例如：变量、数组元素、函数返回左值引用的表达式等。
    右值 指的是没有存储地址、即将被销毁的临时对象或表达式。例如：字面常量、函数返回右值的表达式、移动语义中的右值引用等。
        * 右值 临时存在 容易消失
        * 右值 不会有其他变量使用它
        * 左值 持久存在
    & 左值引用
    && 右值引用
    int a = 10 + 5;             * a是左值 持久存在 有存储地址
                                  10 + 5 是右值  10 + 5 字面值的表达式没有存储地址
    int &r=a;                   * r是左值 持久存在 有存储地址
                                  a是左值 持久存在 有存储地址
    int &&rr = a;               * 错误，右值引用不能绑定到左值上
    int &r2 = i * 10;           * 错误，右值不能绑定到左值引用上  i * 10 是右值
    const int &r3 = i * 10;     * 正确，const左值引用 可以绑定 到右值上
    int &&rr2 = i * 10;         * 正确，右值引用可以绑定到右值上

    总结 ：
        * 左值引用 只能绑定到左值上
        * 右值引用 只能绑定到右值上
        * const左值引用 可以绑定到右值上
    
    Rvalue reference refer to objects that about to be destroyed. Hence,we can "steal" state from an object bound to an rvalue reference.
*/
//示例

class Move
{
public:
    int a_;

    Move(int a) : a_(a) { cout << " in constructor " << a_ <<endl; }
    //copy constructor
    Move(const Move &m) { cout << " in copy constructor " << m.a_ << endl; 
        this->a_ = m.a_; 
    }
    //move constructor
    Move(Move &&m) noexcept {  // noexcept 保证不会抛出异常
         cout << " in move constructor " << m.a_ << endl;
         this->a_ = m.a_; 
        }
    //copy assignment
    Move &operator=(const Move &m) { 
        cout << " in copy assignment " << m.a_ << endl; 
        this->a_ = m.a_;
        return *this; 
    }
    //move assignment
    Move &operator=(Move &&m) noexcept {
        cout << " in move assignment " << m.a_ << endl; 
        this->a_ = m.a_; 
        return *this; 
    }
    ~Move() { cout << " in destructor " << a_ << endl; }
};
/**
 *  vec
 *      1 2 3 4
 *    
 *      * * * * * * * * 
*/
int main()
{
    vector<Move> vec;
    vec.push_back(Move(1)); // 1. 临时对象 2. 临时对象被移动到vec中
}