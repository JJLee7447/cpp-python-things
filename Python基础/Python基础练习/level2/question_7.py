#编写一个程序，以2位数字，X,Y作为输入，生成一个二维数组。数组的第i行和第j列中的元素值应该是i*j。

ls=[x for x in input('请输入x,y:').split(',')]
rownum=int(ls[0])  #行
colnum=int(ls[1])  #列
multilist = [[0 for col in range(colnum)] for row in range(rownum)]
for row in range(rownum):
    for col in range(colnum):
        multilist[row][col]=row*col

print(multilist)