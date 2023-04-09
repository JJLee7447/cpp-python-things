#使用给定的整数n，编写一个程序生成一个包含(i, i*i)的字典，该字典包含1到n之间的整数(两者都包含)。然后程序应该打印字典。
num=int(input('请输入一个整数：'))
dic=dict()  #使用dict类型

for i in range(1,num+1):
    dic[i]=i*i

print(dic)