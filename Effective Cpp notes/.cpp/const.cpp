#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;
void fun1()
{
    char greeting[] = "hello";
    char *p1 = greeting;
    const char *p2 = greeting;
    //*(p1 + 1) = '0';
    //*(p2 + 1) = '1';
    char *const p3 = greeting;
    const char *const p4 = greeting;
    //p3 = nullptr;
}

void Vector()
{
    vector<int> vec={1,2,3};
    const auto it = vec.begin();
    //*it = 10;
    //it++;

    auto iter = vec.cbegin();
    //*iter = 11;
    //it++;
}
class TextBlock
{
private:
    std::string text;

public:
    TextBlock(std::string str):text(str){}
    const char& operator [] (std::size_t position) const
    {return text[position];}
    char& operator [] (std::size_t position)
    {return text[position];}
};
void print(const TextBlock &tb)  //作为const & 传参使用是最真实的。 
{
    std::cout<<tb[0];
    tb[0] = 'w';
}

int main()
{
    TextBlock tb("hello");
    print(tb);
    
}