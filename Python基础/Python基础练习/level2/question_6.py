from math import sqrt

C=50
H=30
ls=str()
ls=input("请输入整数并以逗号分隔：")

vec=list()
vec=ls.split(",")

for i in range(0,len(vec)):
    vec[i]=int(vec[i])

value=list()
for i in vec:
    val=sqrt(2*C*i/H)
    value.append(str(int(val)))
print(','.join(value))

'''
#!/usr/bin/env python
import math
c=50
h=30
value = []
print('请输入一组数字：')
items=[x for x in input().split(',')]
for d in items:
    value.append(str(int(round(math.sqrt(2*c*float(d)/h)))))
 
print (','.join(value))
'''