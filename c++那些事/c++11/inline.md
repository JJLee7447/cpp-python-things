# inline

​		在C++中，`inline`关键字用于建议编译器在编译过程中将函数调用替换为函数体，以避免函数调用的开销，从而加快代码执行速度。

以下是有关C++中`inline`的一些详细信息：

1. `inline`函数应该很小：`inline`关键字用于建议编译器将函数内联，因此`inline`函数应该简单且短小，最好不超过几行代码。如果一个函数太大，将其内联可能会增加代码大小并降低性能。
2. `inline`关键字是一个建议：`inline`关键字仅是向编译器发出的一个建议，它可能被采纳也可能被忽略。如果一个函数太复杂或被从太多地方调用，编译器可能会决定不内联这个函数。
3. `inline`函数可以在头文件中定义：由于`inline`函数在编译过程中被替换为其函数体，因此应该在头文件中定义`inline`函数。这是因为头文件被多个源文件包含，将`inline`函数定义在头文件中可以确保该函数在包含该头文件的所有源文件中都可用。
4. 不要在多个编译单元中定义`inline`函数：通常不建议在多个编译单元（源文件）中定义`inline`函数。这样做可能会导致链接器错误。
5. `inline`可以用于成员函数：`inline`也可以用于定义类的成员函数。在这种情况下，函数定义应包含在类定义中。
6. `inline`函数仍然可以有地址：尽管`inline`函数在编译过程中被替换为其函数体，但它们仍然可以有地址。这是因为在某些情况下可能需要该函数，例如取函数地址或将其用作模板参数时。

​		

----



​		在 C++ 中，`inline` 是一种用于告诉编译器将函数展开为内联函数的关键字。内联函数是在编译时直接插入到调用位置的函数，而不是在运行时调用。

使用 `inline` 可以提高程序的执行效率，因为它避免了函数调用的开销。然而，对于函数体较大的函数，`inline` 并不一定能带来性能提升，因为内联函数的代码会增加程序的大小。

以下是一些使用 `inline` 的示例：

### 1. 简单的函数

```cpp
inline int add(int a, int b) {
    return a + b;
}
```

这是一个简单的函数，用于将两个整数相加。在调用该函数时，编译器将在调用点插入函数的代码。

### 2. 复杂的函数

```cpp
inline int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
```

这个函数计算阶乘。尽管函数体很大，但它可能会在多个地方调用。因此，使用 `inline` 可以提高程序的执行效率。

### 3. 类成员函数

```cpp
class Rectangle {
public:
    inline int area() const {
        return width * height;
    }

    int width;
    int height;
};
```

这个类有一个内联函数，用于计算矩形的面积。由于这个函数的实现非常简单，因此它适合使用 `inline`。

### 4. 模板函数

```cpp
template<typename T>
inline T max(T a, T b) {
    return a > b ? a : b;
}
```

这是一个模板函数，用于比较两个值的大小并返回较大的值。由于这个函数的实现非常简单，因此它适合使用 `inline`。

需要注意的是，使用 `inline` 关键字并不一定会使函数成为内联函数。编译器可以根据自己的策略决定是否将函数展开为内联函数。因此，对于一些复杂的函数或者仅在程序中少量调用的函数，使用 `inline` 可能不会带来性能提升。