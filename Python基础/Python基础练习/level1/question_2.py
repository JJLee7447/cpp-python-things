#编写一个可以计算给定数的阶乘的程序。结果应该以逗号分隔的顺序打印在一行上。假设向程序提供以下输入:8

def fact(num):
    if num==0:
        return 1
    else:
        return num*fact(num-1)

num=int(input('请输入一个数字:'))
print(f'这个数的阶乘是:{fact(num)}')