'''
定义一个至少有两个方法的类:   getString:从控制台输入获取字符串   printString::打印大写母的字符串。
还请包含简单的测试函数来测试类方法。
提示:使用_init__方法构造一些参数
'''

class InputOutString(object):
    def __init__(self):
        self.s = ""
 
    def getString(self):
        print('请输入字符串：')
        self.s = input()
 
    def printString(self):
        print (self.s.upper())
 
strObj = InputOutString()
strObj.getString()
strObj.printString()