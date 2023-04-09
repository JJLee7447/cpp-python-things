'''
问题：
编写一个程序，根据控制台输入的事务日志计算银行帐户的净金额。
事务日志格式如下所示：
D 100
W 200

D表示存款，而W表示提款。
假设向程序提供以下输入：
D 300
D 300
W 200
D 100
然后，输出应为：
500

提示：
如果向问题提供输入数据，则应假定它是控制台输入。
'''
Amount=0
while True:
    s=input()
    if not s:
        break
    val=s.split(" ")
    operation=val[0]  #D or W
    money=int(val[1])
    if operation=='D':
        Amount+=money
    elif operation=='W':
        Amount-=money
    else:
        pass
print(Amount)
