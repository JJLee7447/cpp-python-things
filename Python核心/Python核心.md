# Python核心



## 目录

1. [第一部分：通用主题](#第一部分：通用主题)

* [chapter1 正则表达式](#chapter1 正则表达式)
* [chapter2  网络编程](#chapter2  网络编程)
* [chapter3  多线程编程](#chapter3  多线程编程)
* [chapter4  GUI编程](#chapter4  GUI编程)
* [chapter5  数据库编程](chapter5  数据库编程)
* [chapter6  *Microsoft Office 编程](#chapter6  *Microsoft Office 编程)
* [chapter7  扩展Python](#chapter7  扩展Python)

2. [第二部分：web开发](#第二部分：web开发)

* [chapter8  Web客户端与服务器](#chapter8  Web客户端与服务器)
* [chapter9  Web编程：CGI和WSGI](#chapter9  Web编程：CGI和WSGI)
* [chapter10  Web框架：Django](#chapter10  Web框架：Django)
* [chapter11  云计算：Google App Engine](#chapter11  云计算：Google App Engine)
* [chapter12  Web服务](#chapter12  Web服务)

## 第一部分：通用主题

### chapter1 正则表达式

[正则表达式](./正则表达式（regex）.md)

[Python` re 模块`](https://blog.csdn.net/qq_44159028/article/details/120575621)

​		正则表达式是对字符串提取的一套规则，我们把这个规则用正则里面的特定语法表达出来，去匹配满足这个规则的字符串。正则表达式具有通用型，不仅python里面可以用，其他的语言也一样适用。	
​		Python中`re`模块提供了正则表达式的功能。

#### `re.match`函数

​		`re.match` 尝试从字符串的起始位置匹配一个模式，如果不是起始位置匹配成功的话，`match()`就返回`None`。

​		语法格式：

​													       	`re.match(pattren,string,flags=0)`

```py
import re
re.match(pattren,string,flags=0)

'''
函数参数说明：
'''
```

函数参数说明：

|   参数    |                             描述                             |
| :-------: | :----------------------------------------------------------: |
| `pattern` |                       匹配的正则表达式                       |
| `string`  |                        要匹配的字符串                        |
|  `flags`  | 标志位，用于控制正则表达式的匹配方式，如：是否区分大小写，多行匹配等等[正则表达式修饰符 - 可选标志](#正则表达式修饰符 - 可选标志) |

​		我们可以使用`group(num) `或` groups()` 匹配对象函数来获取匹配表达式。

| 匹配对象方法   | 描述                                                         |
| -------------- | ------------------------------------------------------------ |
| `group(num=0)` | 匹配的整个表达式的字符串，group() 可以一次输入多个组号，在这种情况下它将返回一个包含那些组所对应值的元组。 |
| `groups()`     | 返回一个包含所有小组字符串的元组，从 1 到 所含的小组号。     |

示例：

```py
import re
print(re.match('www', 'www.runoob.com').span())  # 在起始位置匹配
print(re.match('com', 'www.runoob.com'))         # 不在起始位置匹配

'''
(0, 3)
None
'''
```

```py
import re
 
line = "Cats are smarter than dogs"
# .* 表示任意匹配除换行符（\n、\r）之外的任何单个或多个字符
# (.*?) 表示"非贪婪"模式，只保存第一个匹配到的子串
matchObj = re.match( r'(.*) are (.*?) .*', line, re.M|re.I)
 
if matchObj:
   print ("matchObj.group() : ", matchObj.group())
   print ("matchObj.group(1) : ", matchObj.group(1))
   print ("matchObj.group(2) : ", matchObj.group(2))
else:
   print ("No match!!")

'''
matchObj.group() :  Cats are smarter than dogs
matchObj.group(1) :  Cats
matchObj.group(2) :  smarter
'''
```

#### `re.search`方法

​		`re.search` 扫描整个字符串并返回第一个成功的匹配。

语法格式：

​														`re.search(pattern, string, flags=0)`

示例：

```py
import re
 
print(re.search('www', 'www.runoob.com').span())  # 在起始位置匹配
print(re.search('com', 'www.runoob.com').span())         # 不在起始位置匹配

'''
(0, 3)
(11, 14)
'''
```

```py
import re
 
line = "Cats are smarter than dogs"
 
searchObj = re.search( r'(.*) are (.*?) .*', line, re.M|re.I)
 
if searchObj:
   print ("searchObj.group() : ", searchObj.group())
   print ("searchObj.group(1) : ", searchObj.group(1))
   print ("searchObj.group(2) : ", searchObj.group(2))
else:
   print ("Nothing found!!")

'''
searchObj.group() :  Cats are smarter than dogs
searchObj.group(1) :  Cats
searchObj.group(2) :  smarter
'''
```

#### `re.match`与`re.search`的区别

​		`re.match` 只匹配字符串的开始，如果字符串开始不符合正则表达式，则匹配失败，函数返回 `None`，而 `re.search `匹配整个字符串，直到找到一个匹配。

```py
import re
 
line = "Cats are smarter than dogs"
 
matchObj = re.match( r'dogs', line, re.M|re.I)
if matchObj:
   print ("match --> matchObj.group() : ", matchObj.group())
else:
   print ("No match!!")
 
matchObj = re.search( r'dogs', line, re.M|re.I)
if matchObj:
   print ("search --> matchObj.group() : ", matchObj.group())
else:
   print ("No match!!")

'''
No match!!
search --> matchObj.group() :  dogs
'''
```

#### 检索和替换

​		Python 的`re`模块提供了`re.sub`用于替换字符串中的匹配项。

语法格式：

·										`re.sub(pattern, repl, string, count=0, flags=0)`

参数：

- `pattern` : 正则中的模式字符串。
- `repl` : 替换的字符串，也可为一个函数。
- `string `: 要被查找替换的原始字符串。
- `count `: 模式匹配后替换的最大次数，默认 0 表示替换所有的匹配。
- `flags` : 编译时用的匹配模式，数字形式。

前三个为必选参数，后两个为可选参数。

```py
import re
 
phone = "2004-959-559 # 这是一个电话号码"
 
# 删除注释
num = re.sub(r'#.*$', "", phone)
print ("电话号码 : ", num)
 
# 移除非数字的内容
num = re.sub(r'\D', "", phone)
print ("电话号码 : ", num)

'''
电话号码 :  2004-959-559 
电话号码 :  2004959559
'''
```

##### ` repl` 参数是一个函数

```py
import re
 
# 将匹配的数字乘以 2
def double(matched):
    value = int(matched.group('value'))
    return str(value * 2)
 
s = 'A23G4HFD567'
print(re.sub('(?P<value>\d+)', double, s))

'''
A46G8HFD1134
'''
```

##### `compile` 函数

​		`compile` 函数用于编译正则表达式，生成一个正则表达式（ Pattern ）对象，供` match() `和 `search()` 这两个函数使用。

语法格式为：

​											`re.compile(pattern[, flags])`

参数：

- pattern : 一个字符串形式的正则表达式
- flags 可选，表示匹配模式，比如忽略大小写，多行模式等，具体参数为：
- - re.I 忽略大小写

	- re.L 表示特殊字符集 \w, \W, \b, \B, \s, \S 依赖于当前环境
	- re.M 多行模式
	- re.S 即为' . '并且包括换行符在内的任意字符（' . '不包括换行符）
	- re.U 表示特殊字符集 \w, \W, \b, \B, \d, \D, \s, \S 依赖于 Unicode 字符属性数据库
	- re.X 为了增加可读性，忽略空格和' # '后面的注释

```py
>>>import re
>>> pattern = re.compile(r'\d+')                    # 用于匹配至少一个数字
>>> m = pattern.match('one12twothree34four')        # 查找头部，没有匹配
>>> print( m )
None
>>> m = pattern.match('one12twothree34four', 2, 10) # 从'e'的位置开始匹配，没有匹配
>>> print( m )
None
>>> m = pattern.match('one12twothree34four', 3, 10) # 从'1'的位置开始匹配，正好匹配
>>> print( m )                                        # 返回一个 Match 对象
<_sre.SRE_Match object at 0x10a42aac0>
>>> m.group(0)   # 可省略 0
'12'
>>> m.start(0)   # 可省略 0
3
>>> m.end(0)     # 可省略 0
5
>>> m.span(0)    # 可省略 0
(3, 5)
```

在上面，当匹配成功时返回一个 Match 对象，其中：

- `group([group1, …])` 方法用于获得一个或多个分组匹配的字符串，当要获得整个匹配的子串时，可直接使用 `group()` 或 `group(0)`；
- `start([group])` 方法用于获取分组匹配的子串在整个字符串中的起始位置（子串第一个字符的索引），参数默认值为 0；
- `end([group])` 方法用于获取分组匹配的子串在整个字符串中的结束位置（子串最后一个字符的索引+1），参数默认值为 0；
- `span([group])` 方法返回 `(start(group), end(group))`。



```py
>>>import re
>>> pattern = re.compile(r'([a-z]+) ([a-z]+)', re.I)   # re.I 表示忽略大小写
>>> m = pattern.match('Hello World Wide Web')
>>> print( m )                            # 匹配成功，返回一个 Match 对象
<_sre.SRE_Match object at 0x10bea83e8>
>>> m.group(0)                            # 返回匹配成功的整个子串
'Hello World'
>>> m.span(0)                             # 返回匹配成功的整个子串的索引
(0, 11)
>>> m.group(1)                            # 返回第一个分组匹配成功的子串
'Hello'
>>> m.span(1)                             # 返回第一个分组匹配成功的子串的索引
(0, 5)
>>> m.group(2)                            # 返回第二个分组匹配成功的子串
'World'
>>> m.span(2)                             # 返回第二个分组匹配成功的子串索引
(6, 11)
>>> m.groups()                            # 等价于 (m.group(1), m.group(2), ...)
('Hello', 'World')
>>> m.group(3)                            # 不存在第三个分组
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
IndexError: no such group
```

##### `findall`

​		在字符串中找到正则表达式所匹配的所有子串，并返回一个列表，如果有多个匹配模式，则返回元组列表，如果没有找到匹配的，则返回空列表。

​		**注意：** `match` 和 `search` 是匹配一次` findall` 匹配所有。

语法格式为：

```py
re.findall(pattern, string, flags=0)
#或
pattern.findall(string[, pos[, endpos]])
```

参数：

- **pattern** 匹配模式。
- **string** 待匹配的字符串。
- **pos** 可选参数，指定字符串的起始位置，默认为 0。
- **endpos** 可选参数，指定字符串的结束位置，默认为字符串的长度。

查找字符串中的所有数字：
```py
import re
 
result1 = re.findall(r'\d+','runoob 123 google 456')
 
pattern = re.compile(r'\d+')   # 查找数字
result2 = pattern.findall('runoob 123 google 456')
result3 = pattern.findall('run88oob123google456', 0, 10)
 
print(result1)
print(result2)
print(result3)

'''
['123', '456']
['123', '456']
['88', '12']
'''
```

多个匹配模式，返回元组列表：

```py
import re

result = re.findall(r'(\w+)=(\d+)', 'set width=20 and height=10')
print(result)

'''
[('width', '20'), ('height', '10')]
'''
```

#####` re.finditer`

​		和 `findall` 类似，在字符串中找到正则表达式所匹配的所有子串，并把它们作为一个迭代器返回。

语法格式： `re.finditer(pattern, string, flags=0)`

```py
import re
 
it = re.finditer(r"\d+","12a32bc43jf3") 
for match in it: 
    print (match.group() )
    
'''
12 
32 
43 
3
'''
```

##### ` re.split`

​		`split `方法按照能够匹配的子串将字符串分割后返回列表，它的使用形式如下：

​									`re.split(pattern, string[, maxsplit=0, flags=0])`

* `maxsplit`   分割次数，`maxsplit=1 `分割一次，默认为 0，不限制次数

```py
>>>import re
>>> re.split('\W+', 'runoob, runoob, runoob.')
['runoob', 'runoob', 'runoob', '']
>>> re.split('(\W+)', ' runoob, runoob, runoob.') 
['', ' ', 'runoob', ', ', 'runoob', ', ', 'runoob', '.', '']
>>> re.split('\W+', ' runoob, runoob, runoob.', 1) 
['', 'runoob, runoob, runoob.']
 
>>> re.split('a*', 'hello world')   # 对于一个找不到匹配的字符串而言，split 不会对其作出分割
['hello world']
```

#### 正则表达式对象

##### `re.RegexObject`

`re.compile()` 返回 `RegexObject` 对象。

#####` re.MatchObject`

`group() `返回被 RE 匹配的字符串。

- **`start()`** 返回匹配开始的位置
- **`end()`** 返回匹配结束的位置
- **`span()`** 返回一个元组包含匹配 (开始,结束) 的位置

#### 正则表达式修饰符 - 可选标志

正则表达式可以包含一些可选标志修饰符来控制匹配的模式。修饰符被指定为一个可选的标志。多个标志可以通过按位 `OR(|)` 它们来指定。如 `re.I` |` re.M` 被设置成` I `和` M` 标志：

| 修饰符 |                             描述                             |
| :----: | :----------------------------------------------------------: |
|  re.I  |                     使匹配对大小写不敏感                     |
|  re.L  |               做本地化识别（locale-aware）匹配               |
|  re.M  |                    多行匹配，影响 ^ 和 $                     |
|  re.S  |               使 . 匹配包括换行在内的所有字符                |
|  re.U  |   根据Unicode字符集解析字符。这个标志影响 \w, \W, \b, \B.    |
|  re.X  | 该标志通过给予你更灵活的格式以便你将正则表达式写得更易于理解。 |



### chapter2  网络编程

**本章内容：**

* 简介：
* 客户端/服务架构：
* 套接字：通信端点：
* Python 中的网络编程：
* `*SocketServer` 模块：
* `*Twisted` 框架介绍：
* 相关模块。



### chapter3  多线程编程

### chapter4  GUI编程

### chapter5  数据库编程

### chapter6  *Microsoft Office 编程

### chapter7  扩展Python

## 第二部分：web开发

### chapter8  Web客户端与服务器

### chapter9  Web编程：CGI和WSGI

### chapter10  Web框架：Django

### chapter11  云计算：Google App Engine

### chapter12  Web服务