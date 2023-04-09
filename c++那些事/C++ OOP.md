[OOP特性](./.cpp/OOP特性.cpp)

面向对象编程（Object-Oriented Programming，OOP）是一种常用的编程范式，它通过抽象和封装来简化复杂的软件设计。C++ 提供了多种语言特性来支持面向对象编程，其中一些核心概念包括：

- **类（Class）**：类是一种用户自定义的数据类型，它封装了数据和操作数据的函数。在 C++ 中，可以使用 `class` 或 `struct` 关键字定义类。

- **对象（Object）**：对象是类的实例。可以使用类定义的构造函数来创建对象。

- **封装（Encapsulation）**：封装是指将数据和操作数据的函数包装在一起，以保护数据不被外部访问。在 C++ 中，可以使用访问修饰符 `public`、`private` 和 `protected` 来控制成员的访问权限。

- **继承（Inheritance）**：继承允许一个类从另一个类继承成员变量和成员函数。这样可以实现代码复用和多态。在 C++ 中，可以使用冒号 `:` 来指定一个类继承自另一个类。

- **多态（Polymorphism）**：多态允许子类重写父类中定义的虚函数，并根据调用虚函数时所用对象的实际类型来确定调用哪个版本的虚函数。这样可以实现运行时动态绑定。在 C++ 中，可以使用关键字 `virtual` 来声明虚函数。

下面是一个简单的例子，演示了如何在 C++ 中使用这些概念：

```c++
#include <iostream>
#include <string>

class Animal {
public:
    Animal(const std::string& name) : name(name) {}

    virtual void makeSound() const {
        std::cout << "Animal makes sound" << std::endl;
    }

protected:
    std::string name;
};

class Dog : public Animal {
public:
    Dog(const std::string& name) : Animal(name) {}

    void makeSound() const override {
        std::cout << "Dog barks" << std::endl;
    }
};

int main() {
    Animal animal("animal");
    Dog dog("dog");

    animal.makeSound(); // 输出 "Animal makes sound"
    dog.makeSound(); // 输出 "Dog barks"

    return 0;
}
```



