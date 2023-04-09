#include<iostream>

using namespace std;

class TimeKeeper
{
public:
    TimeKeeper(/* args */){}
    ~TimeKeeper(){}
};

class AtomicClock: public TimeKeeper{};  // AtomicClock是TimeKeeper的派生类 
class WaterClock: public TimeKeeper{};   // WaterClock是TimeKeeper的派生类
class WristWatch: public TimeKeeper{};   // WristWatch是TimeKeeper的派生类

int main()
{
    TimeKeeper *getTiemKeeper(){}        // 返回一个指针，指向TimeKeeper的派生类（derived class）的动态分配对象
    TimeKeeper *ptk = getTiemKeeper();   //ptk指向TimeKeeper的派生类的动态分配对象

    delete ptk;                         // 释放动态分配的对象
    return 0;
}
