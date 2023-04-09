'''
问题：编写一个接受句子的程序，并计算大写字母和小写字母的数量。
假设向程序提供以下输入：你好世界！然后，输出应为：大写 1 小写 9

提示：如果向问题提供输入数据，则应假定它是控制台输入。
'''

s = input()
d={"UPPER CASE":0, "LOWER CASE":0}
for c in s:
    if c.isupper():
        d["UPPER CASE"]+=1
    elif c.islower():
        d["LOWER CASE"]+=1
    else:
        pass
print("UPPER CASE", d["UPPER CASE"])
print("LOWER CASE", d["LOWER CASE"])