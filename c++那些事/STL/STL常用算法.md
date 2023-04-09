### 算法概述

算法主要是由头文件`algorithm`  `functional`  `numeric`组成。
* `algorithm`是所有STL头文件中最大的一个,其中常用的功能涉及到比较，交换，查找,遍历，复制，修改，反转，排序，合并等…
* `numeric`体积很小，只包括在几个序列容器上进行的简单运算的模板函数.
* `functional` 定义了一些模板类,用以声明函数对象。

##### 常用遍历算法 

```C++
/*
    遍历算法 遍历容器元素
	@param beg 开始迭代器
	@param end 结束迭代器
	@param _callback  函数回调或者函数对象
	@return 函数对象
*/
for_each(iterator beg, iterator end, _callback);
//STL 定义
template<class _InIt,class _Fn1> inline
void for_each(_InIt _First, _InIt _Last, _Fn1 _Func)
{
	for (; _First != _Last; ++_First)
		_Func(*_First);
}
/*
	transform算法 将指定容器区间元素搬运到另一容器中
	注意 : transform 不会给目标容器分配内存，所以需要我们提前分配好内存
	@param beg1 源容器开始迭代器
	@param end1 源容器结束迭代器
	@param beg2 目标容器开始迭代器
	@param _cakkback 回调函数或者函数对象
	@return 返回目标容器迭代器
*/
transform(iterator beg1, iterator end1, iterator beg2, _callbakc)


template<class _InIt, class _OutIt, class _Fn1> inline 
	_OutIt _Transform(_InIt _First, _InIt _Last,_OutIt _Dest, _Fn1 _Func)
	{	

		for (; _First != _Last; ++_First, ++_Dest)
			*_Dest = _Func(*_First);
		return (_Dest);
	}

	template<class _InIt1,class _InIt2,class _OutIt,class _Fn2> inline
	_OutIt _Transform(_InIt1 _First1, _InIt1 _Last1,_InIt2 _First2, _OutIt _Dest, _Fn2 _Func)
	{	
		for (; _First1 != _Last1; ++_First1, ++_First2, ++_Dest)
			*_Dest = _Func(*_First1, *_First2);
		return (_Dest);
	}

```

**for_each 测试**
```c++
#include<iostream>
#include<vector>
#include<algorithm>

//普通函数

void print1(int val)
{
    std::cout << val << " ";
}

//对象函数
struct print2
{
    void operator () (int val)
    {
        std::cout << val << " ";
    }
    /* data */
};

int main()
{

    std::vector<int> vec = {1, 2, 3, 3, 4, 5, 6, 6, 7,  8, 8};
    std::cout << "普通函数测试" << std::endl;
    for_each(vec.begin(), vec.end(), print1);
    std::cout << std::endl;
    std::cout << "对象函数测试" << std::endl;
    for_each(vec.begin(), vec.end(), print2());
}
/*
普通函数测试
1 2 3 3 4 5 6 6 7 8 8
对象函数测试
1 2 3 3 4 5 6 6 7 8 8
*/