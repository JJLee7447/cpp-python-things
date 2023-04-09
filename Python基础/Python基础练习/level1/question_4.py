#编写一个程序，该程序接受控制台以逗号分隔的数字序列，并生成包含每个数字的列表和元组。假设向程序提供以下输入:
# 34,67,55,33,12,98

values=input('请输入一组数字,用逗号分隔开')
values=values.split(',')
t=tuple()
t=tuple(values)

print(values)
print(t)