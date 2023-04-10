### 条款4 对象使用前应该被初始化

```cpp
class PhoneNumber {
public:
    PhoneNumber(std::string number) {
        // 解析号码信息
    }

private:
    std::string areaCode;
    std::string exchange;
    std::string lineNumber;
};

class ABEntry {
public:
    ABEntry(const std::string &name, const std::string &address, const std::list<PhoneNumber> &phones) {
        theName = name;
        theAddress = address;
        thePhones = phones;
    }

private:
    std::string theName;
    std::string theAddress;
    std::list<PhoneNumber> thePhones;
    int thePriority;
    static int numberOfEntries;
};
```

在上面的代码中，`ABEntry` 类中包含了一个 `std::list` 类型的成员 `thePhones`，这个成员是一个电话号码列表。电话号码是用一个名为 `PhoneNumber` 的类表示的，这个类也在代码中定义了。为了简化示例，这里没有给出 `PhoneNumber` 类的定义。

现在假设你尝试创建一个 `ABEntry` 对象，但在把参数传递给构造函数之前，系统会先创建类的成员变量。所以，在这个例子中，`thePhones` 首先就被创建了。然而，它是一个电话号码列表，而电话号码是使用 `PhoneNumber` 类型的对象进行表示的，而这些对象又依赖于成员变量 `areaCode`、`exchange` 和 `lineNumber`，这些成员变量只有在 `PhoneNumber` 对象创建时才能被初始化。但现在问题来了，如果我们没有特别的把成员变量在构造函数中进行初始化，那它们的构造函数就不会被调用，`PhoneNumber` 对象就无法被正确的创建，这将最终导致程序崩溃。

为了避免这种问题，我们需要正确的管理类成员的初始化顺序，确保对象可以被正确的创建和初始化。



​		为了正确地初始化 `PhoneNumber` 对象，我们需要将 `thePhones` 成员的初始化放在最后进行，并在初始化列表中为 `thePhones` 指定一个空的电话号码列表。然后，我们就可以在构造函数体中通过 `push_back` 函数将电话号码逐个添加到 `thePhones` 成员中。这么做的代码如下所示：

```cpp
class ABEntry {
public:
    ABEntry(const std::string &name, const std::string &address, const std::list<PhoneNumber> &phones)
    : theName{name}, theAddress{address}, thePhones{}, thePriority{} {
        for (const auto &phone : phones) {
            thePhones.push_back(phone);
        }
    }

private:
    std::string theName;
    std::string theAddress;
    std::list<PhoneNumber> thePhones;
    int thePriority;
    static int numberOfEntries;
};
```

以上代码中，我们通过初始化列表为 `theName`、`theAddress` 和 `thePriority` 成员变量进行了初始化，同时在列表中也创建了一个空的电话号码列表，即 `thePhones{}`。然后，在构造函数体中，我们利用 `push_back` 函数将传入的电话号码逐个添加到 `thePhones` 中。

这样，我们就可以正确地初始化 `ABEntry` 对象，也保证了 `PhoneNumber` 成员对象在使用之前先被初始化。