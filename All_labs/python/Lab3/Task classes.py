class str:
    def __init__(self,name):
        self.name=name
    def getString(s):
        s.name=input()
        return s
    def printString(s):
        print((s.name).upper())
some=str("")
some.getString()
some.printString()
class Shape:
    def __init__(self,length):
        self.length=length
    def area(s):
        print(0)
class Square(Shape):
    def __init__(self, length):
        super().__init__(length)
    def area(s):
        print(s.length**2)
sh=Shape("")
sh.area()
sqr=Square(10)
sqr.area()
class Rectangle(Square):
    def __init__(self, length,width):
        super().__init__(length)
        self.width=width
    def area(s):
        print(s.length*s.width)
rec=Rectangle(10,5)
rec.area()
class Point:
    def __init__(self,x1,y1,x2,y2):
        self.x1=x1
        self.y1=y1
        self.x2=x2
        self.y2=y2
    def show(s):
        print("First:",s.x1,s.y1)
        print("Second:",s.x2,s.y2)
    def move(s):
        s.x1=float(input())
        s.y1=float(input())
        s.x2=float(input())
        s.y2=float(input())
    def dist(s):
        a=(s.x1-s.x2)**2
        print(a)
        b=(s.y1-s.y2)**2
        print(b)
        c=a+b
        print(c)
        print(c**0.5)
pnt=Point(10, 5, 15, -6)
pnt.show()
pnt.move()
pnt.show()
pnt.dist()
class Account:
    def __init__(self,owner, balance):
        self.owner=owner
        self.balance=int(balance)
    def show(s):
        print(s.owner,s.balance)
    def deposit(s):
        x=int(input())
        s.balance+=x
    def withdraw(s):
        y=int(input())
        if not s.balance<y:
            print("You get:",y)
            s.balance-=y
pers=Account("Jefferson",15000)
pers.deposit()
pers.show()
pers.withdraw()
pers.show()
def filter(s):
    for x in s:
        if(x%int()):
            pass
