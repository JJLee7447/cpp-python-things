在 Python 代码中，我们经常会看到

```py
if __name__ == '__main__':
```

​		先给出结论，对该语句用法简单的解释就是： **如果`if __name__ == '__main__'` 所在模块是被直接运行的，则该语句下代码块被运行，如果所在模块是被导入到其他的python脚本中运行的，则该语句下代码块不被运行。**

### 程序入口
​		对于很多编程语言来说，程序都必须要有一个入口，比如 C，C++，以及完全面向对象的编程语言 Java，C# 等。其中C 和 C++ 都需要有一个 main 函数来作为程序的入口，也就是程序的运行会从 main 函数开始。同样的，Java 和 C# 则必须要有一个包含 Main 方法的主类来作为程序入口。

​		但和C，C++、Java 以及 C# 等有所不同的是，Python属于脚本语言，不像编译型语言那样先将程序编译成二进制再运行，python是动态的逐行解释运行，也就是从脚本第一行开始运行，没有统一的入口。

另外我们知道，python文件有两种使用方法：

​		第一种：直接作为脚本执行
​		第二种：import到其他的python脚本中被调用（模块重用）执行，也就是作为模块（库）被导入执行
​		不管是直接运行还是导入，最顶层的代码都会被运行（Python 用缩进来区分代码层次）。但实际使用过程中，python文件作为模块被其它python脚本调用执行的时候，有的代码我们是不希望被运行的。

而`if __name__ == '__main__'` 的作用就是定义这两种情况执行代码的执行方式，在该语句下的代码只有在文件作为脚本直接执行情况下才会被执行，而import到其他脚本中是不会被执行的。

### 案例

要计算一个圆形的面积，公式是S = л * r^2（其中r是半径）

第一步：首先创建一个 param.py 的文件

```py
# param.py
pi = 3.1415926

def main():
    print("pi:", pi)
 
main()
```

直接执行该文件输出：

```py
pi: 3.1415926
```

第二步：然后创建 calculate.py 文件，用于计算圆的面积，该文件里边需要用到 param.py 文件中的 pi 参数，需要我们从 param.py 中把 pi 变量导入到 calculate.py 中

```py
#calculate.py
from param import pi
 
def area_calculate(r):
    s = pi * (r ** 2)	
    return s
 
def main():
    print("The area of the circle: ", area_calculate(2))

main()
```

运行 calculate.py

```py
pi: 3.1415926
The area of the circle:  12.5663704
```

从输出结果可以看出，param.py 中的 main 函数也被运行了，实际上我们不希望它被运行，这时我们就可以用`if __name__ == '__main__'` 对 param.py 做修改：

```py
pi = 3.1415926

def main():
    print("pi:", pi)

if __name__ == "__main__":
    main()
```

再次运行 calculate.py，输出如下：

```py
The area of the circle:  12.5663704
```

对比可以看出，再次运行 param.py ，`if __name__ == '__main__'`语句之前和之后的代码都被执行，仍然输出 pi: 3.1415926 ，但再次运行 calculate.py，导入的 param.py 里`if __name__ == '__main__'`语句之后的代码已经不被执行，输出已经不包含 `pi: 3.1415926`。

`if __name__ == '__main__'`就相当于是 Python 模拟的程序入口。Python 本身并没有规定这么写，这只是一种编码习惯。由于模块之间相互引用，不同模块可能都有这样的定义，而入口程序只能有一个。到底哪个入口程序被选中，这取决于`__name__`的值。而`__name__`是内置变量，用于表示当前模块的名字。

运行原理
每个python模块（python文件，也就是此处的 param.py 和 calculate.py）都包含内置的变量`__name__`，当运行模块被执行的时候`__name__`等于文件名（包含了后缀.py）；如果import到其他模块中，则`__name__`等于模块名称（不包含后缀.py）。而`'__main__'`等于当前执行文件的名称（包含了后缀.py）。进而当模块被直接执行时，`__name__ == '__main__'`结果为真，所以后续代码可以继续执行。

```py
pi = 3.1415926

def main():
    print("pi:", pi)

print(__name__)

if __name__ == "__main__":
    main()
''' output
__main__
pi: 3.1415926

'''
```

再执行 calculate.py，执行结果如下：

```py
param
The area of the circle:  12.5663704
```

此时，param.py 中的`__name__`变量值为 param，`__name__ == '__main__'`条件为假，所以无法执行其后的代码。