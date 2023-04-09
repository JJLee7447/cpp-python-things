'''
编写一个程序，接受逗号分隔的单词序列作为输入，按字母顺序排序后按逗号分隔的序列打印单词。
假设向程序提供以下输入:
without,hello,bag,world
则输出为:
bag,hello,without,world
'''

ls=[x for x in input('请输入一系列单词,用逗号隔开：\n').split(',')]
ls.sort()

print(','.join(ls))