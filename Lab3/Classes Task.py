class First:
    def getString(s):
        s.string=input()
    def printString(s):
        print((s.string).upper())
s=First()
s.getString()
s.printString()
class Square:
    def __init__(self,length,area):
        self.length=length
        self.area=length*length
class Shape(Square):
    def __init__(self,length,area):
        Square.__init__(self,length,area)
        self.area=0
class Rectangle(Shape):
    def __init__(self,length,area,width):
        Shape.__init__(self,length,area)
        self.width=width
        self.area=length*width
    def areaCompute(r):
        return r.length*r.width
r=Rectangle
r.width=5
r.length=7
print(r.areaCompute(r))
class Point:
    def __init__(self,first,second):
        self.first=first
        self.second=second
    def show(s):
        print(s.first,s.second)
   # def dist(s1,s2):
p=Point([15,25],[19,-3])
p.show()