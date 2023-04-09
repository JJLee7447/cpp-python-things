### set test
```c++
#include<iostream>
#include<set>
#include<map>
#include<algorithm>

int main()
{
    std::set<std::string> st;
    st = {"this", "is", "std", "test"}; //赋值操作 set& operator=(const set &st);//重载等号操作符
    std::cout << "遍历st" << std::endl;
    for(auto it:st)
    {
        std::cout << it << std::endl;
    }
    std::set<std::string> copyset(st);  //拷贝构造 set(const set &st);//拷贝构造函数
    copyset.insert("insert");   //插入
    copyset.erase("is");        // 删除
    /**
     * erase(pos)  删除pos 迭代器所指元素 返回下一个元素的迭代器
     * erase(beg ,end) 删除beg 到 end 之间的元素 返回 下一个元素的迭代器
     * clear()  清空
     */
    swap(st, copyset); //交换两个容器
    
    //查找键key是否存在
    {
        std::cout << "find 'is' in set" << std::endl;
        auto it=find(st.begin(), st.end(), "is");  //使用 algorithm 头文件的 find 返回找到元素的迭代器 没找到返回第二个参数
        if(it==st.end())
        {
            std::cout << "not found" << std::endl;
        }
        else{
            std::cout << "find it" << std::endl;
        }

        std::set<std::string>::iterator iter = st.find("is");
        /**
         * 使用set 的find 查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
         * std::set<std::string>::iterator iter  等价于 atuo iter
         */



    }
    //查找key的个数 count
    {
        auto count = st.count("is");//返回类型为 size_type  
    }
    /**
     * lower_bound(keyElem) 返回key>=keyElem 元素的迭代器
     * upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
     * equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
    */
    

}
```

### pair(队组)
对组(pair)将一对值组合成一个值，这一对值可以具有不同的数据类型，两个值可以分别用pair的两个公有属性first和second访问。
类模板：`template <class T1, class T2> struct pair`. 
在 utility 头文件中
创建对组:
```c++
//第一种方法创建一个对组
pair<string, int> pair1(string("name"), 20);
cout << pair1.first << endl; //访问pair第一个值
cout << pair1.second << endl;//访问pair第二个值
//第二种
pair<string, int> pair2 = make_pair("name", 30);
cout << pair2.first << endl;
cout << pair2.second << endl;
//pair=赋值
pair<string, int> pair3 = pair2;
cout << pair3.first << endl;
cout << pair3.second << endl;
```

### map  test
```c++
#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<utility>
int main()
{
    //列表初始化
    std::map<std::string, int> mp= 
    { 
        {"this",001},
        {"is",002},
        {"map",003},
        {"test",004},
    };
    //拷贝构造
    std::cout << "遍历" << std::endl;
    for(auto it:mp)
    {
        std::cout << it.first << " " << it.second << std::endl;
    }
    std::map<std::string, int> copymp(mp);
    /**
     * 插入元素
     * map.insert(...); //往容器插入元素，返回pair<iterator,bool>
     * // 第一种 通过pair的方式插入对象
     * mapStu.insert(pair<std::strign, int>("jjjj",66666));
     * // 第二种 通过pair的方式插入对象
     * mapStu.inset(make_pair("aaaa",0004));
     * // 第三种 通过value_type的方式插入对象
     * mapStu.insert(map<std::string, int>::value_type("ssss",006));
     * // 第四种 通过数组的方式插入值
     * mapStu["insert"] = 005;
     */
    mp.insert(std::pair<std::string, int>("jjjj", 66666));
    mp.insert(std::make_pair("aaaa",0004));
    //mp.insert(map<std::string, int>::value_type("ssss",006));
    mp["insert"] = 005;
    
    std::cout << "插入后遍历" << std::endl;
    for(auto it:mp)
    {
        std::cout << it.first << " " << it.second << std::endl;
    }
    /*
     * clear();//删除所有元素
     * erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
     * erase(beg,end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
     * erase(keyElem);//删除容器中key为keyElem的对组。
     */
    std::cout << "删除第一个元素" << std::endl;
    auto next=mp.erase(mp.begin());
    std::cout << "下一个元素是" << std::endl;
    std::cout << next->first << " " << next->second << std::endl;
    std::cout << "查找 map" << std::endl;
    auto it = mp.find("map");
    if(it==mp.end())
    {
        std::cout << "not found" << std::endl;
    }
    else {
        std::cout << " find it" << std::endl;
    }
    /*
     *find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回map.end();
     *count(keyElem);//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
     *lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
     *upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
     *equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
    */
}
```