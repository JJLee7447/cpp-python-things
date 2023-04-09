# STL学习笔记

## 常用容器

###顺序容器

#### string

##### string构造函数 （7钟）

```c++
string()
//创建一个空的对象
string(const string &str)
//使用一个string对象初始化另一个string对象
string(const char * s)  
//将string对象初始化为s指向NB	TS。NBTS为null-byte-temnated string的缩写，表示以空字符结束的字符串------传统的C字符串。
string(size_type n,char c)  
//创建一个包含n个元素的string对象，其中每个元素都被初始化为字符c
string(const string & str,string size_type pos=0,size_type n = npos)    
//将string对象初始化为对象str中从位置pos开始到结尾的字符，或从位置pos开始的n个字符
string(const char * s, size_type n)
//将string对象初始化为s指向的NBTS中的前n字符，即使超过了NBTS端
string(Iter begin,Iter end)
//将string对象初始化为区间[begin,end]内的字符，其中begin和end的行为就像指针，用于指定位置，范围包括begin在内，但不包括end
```

##### string 基本赋值操作

````c++
// 重载 = 操作符
string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
string& operator=(const string &s);//把字符串s赋给当前的字符串
string& operator=(char c);//字符赋值给当前的字符串

string& assign(const char *s);//把字符串s赋给当前的字符串
string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
string& assign(const string &s);//把字符串s赋给当前字符串
string& assign(int n, char c);//用n个字符c赋给当前字符串
string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串
````

##### string 存取字符操作

```c++
char& operator[](int n);//通过[]方式取字符
char& at(int n);//通过at方法获取字符
```

##### string拼接操作

```c++
string& operator+=(const string& str);//重载+=操作符
string& operator+=(const char* str);//重载+=操作符
string& operator+=(const char c);//重载+=操作符
string& append(const char *s);//把字符串s连接到当前字符串结尾
string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
string& append(const string &s);//同operator+=()
string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
string& append(int n, char c);//在当前字符串结尾添加n个字符c
```

##### string 查找替换

```c++
int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置
int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置

string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s
```

##### string 比较操作

```c++
//compare函数在>时返回 1，<时返回 -1，==时返回 0。比较区分大小写，比较时参考字典顺序，排越前面的越小。大写的A比小写的a小。
int compare(const string &s) const;//与字符串s比较
int compare(const char *s) const;//与字符串s比较

```

##### string 子串

```c++
string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串
```

##### string插入和删除操作

```c++
string& insert(int pos, const char* s); //插入字符串
string& insert(int pos, const string& str); //插入字符串
string& insert(int pos, int n, char c);//在指定位置插入n个字符c
string& erase(int pos, int n = npos);//删除从Pos开始的n个字符 
```

##### **string和c-style字符串转换**

```c++
//string 转 char* 使用 string::c_str()  
string str = "it";
const char* cstr = str.c_str();
//char* 转 string 
char* s = "it";
string str(s);
```

>​		在c++中存在一个从const char*到string的隐式类型转换，却不存在从一个string对象到C_string的自动类型转换。对于string类型的字符串，可以通过c_str()函数返回string对象对应的C_string.通常，程序员在整个程序中应坚持使用string类对象，直到必须将内容转化为char*时才将其转换为C_strin

##### string to int

**使用atoi()函数**

>==需要将 string 转换为 const char* 才能使用==   ==c_str()转换到第一个非数字字符为止==

```c++
//函数原型  int atoi(const char *nptr);
string str="1234";
const char* cstr = str.c_str();
int istr=atoi(cstr);
```

#### vector

#### deque

#### stack

#### queue

#### list

### 关联容器

#### set/multiset

#### map/multiset



