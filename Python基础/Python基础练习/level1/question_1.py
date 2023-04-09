'''
编写一个程序,它将找到所有这些数字,可被7整除,但不是5的倍数,2000年至3200年(包括在内)。得到的数字应按逗号分隔的顺序打印在一行上。
'''
ls=[]
for i in range(2000,3201):
    if i%7==0 and i%5!=0:
            ls.append(str(i))

print(','.join(ls))

# join 用于合并序列的元素
'''
>>> seq=[1,2,3,4,5]
>>> sep='+'
>>> sep.join(seq)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: sequence item 0: expected str instance, int found
>>> seq=['1','2','3','4','5']
>>> sep.join(seq)
'1+2+3+4+5'
>>>
'''