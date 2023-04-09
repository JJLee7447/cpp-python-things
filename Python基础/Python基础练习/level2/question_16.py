'''
问题：
使用列表推导来对列表中的每个奇数进行平方。该列表由逗号分隔的数字序列输入。
假设向程序提供以下输入：
1,2,3,4,5,6,7,8,9
然后，输出应为：
1,3,5,7,9
'''
result=list()
list=[x for x in input().split(",")]
for i in list:
    if int(i)%2==1:
        result.append(str(int(i)*int(i)))

print(','.join(result))