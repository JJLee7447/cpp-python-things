'''
问题：
网站要求用户输入用户名和密码进行注册。编写一个程序来检查用户输入的密码的有效性。
以下是检查密码的标准：
1. [a-z] 之间至少有 1 个字母
2. [0-9] 之间至少 1 个数字
1. [A-Z] 之间至少 1 个字母
3. 至少 1 个字符来自 [$#@]
4. 交易密码最小长度：6
5. 交易密码最大长度：12
您的程序应接受一系列逗号分隔的密码，并根据上述条件对其进行检查。将打印符合条件的密码，每个密码用逗号分隔。
例
如果以下密码作为程序的输入：
ABd1234@1,a F1#,2w3E*,2We3345
然后，程序的输出应该是：
ABd1234@1

提示：
如果向问题提供输入数据，则应假定它是控制台输入。

'''
def func1(s:str):
    count=0
    for x in s:
        if x>='a' and x<='z':
            count+=1
        else:
            pass
    return count
def func2(s:str):
    count=0
    for x in s:
        if x>='A' and x<='Z':
            count+=1
        else:
            pass
    return count
def func3(s:str):
    count=0
    for x in s:
        if x>='0' and x<='9':
            count+=1
        else:
            pass
    return count
def func4(s:str):
    count=0
    for x in s:
        if x=='#' or x=='@' or x=='$':
            count+=1
        else:
            pass
    return count
keys=list()
reslut=str()
keys=[x for x in input("请输入一系列逗号分隔的密码：").split(",")]

for k in keys:
    if len(k)>=6 and len(k)<=12:
        if func1(k) and func2(k) and func3(k) and func4(k):
                reslut=k
        else:
            pass
print(reslut)



