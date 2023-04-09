#include<iostream>

using std::cout;
class TextBlock
{
private:
    char *ptext;
public:
    TextBlock(char *str):ptext(str){}
     char& operator [] (std::size_t position) const
    {return ptext[position];}

};
int main()
{
    char a[] = "hello";
    auto b {"hello"};
    const TextBlock tb(a);
    char *p = &tb[0];
    *p = 'k';
    std::cout << a;
    
}