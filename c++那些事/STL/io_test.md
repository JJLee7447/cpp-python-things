
**fstream**
```c++
    std::ofstream os("JJ.txt", std::ios::app);
    os << "JJ test" << std::endl;
    os << 23455 << std::endl;

    std::ifstream is("JJ.txt");
    std::string str;
    getline(is, str);
    std::cout << str << std::endl;
    ```

```
**sstream**
```c++
//可以用来计算单词个数
   std::string str = "hello JJ this is c++ world";
    std::stringstream ss(str);
    int count = 0;
    std::string word;
    while(ss>>word)
    {
        count++;
    }
    std::cout << count << std::endl;

```