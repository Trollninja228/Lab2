class any:
    integer=5
something=any()
print(something.integer)
class Title:
    def __init__(self0,title):
        self0.title=title
    def cout(some):
        print("The list of",some.title,":")
t=Title("cars")
t.cout()
class car:
    def __init__(self,name,year,color):
        self.name=name
        self.year=year
        self.color=color
    def __str__(self):
        return f"{self.name} {self.year} {self.color}"
c1=car("Lada",1998,"yellow")
print(c1.name,c1.year,c1.color)
c1.name="Bugati"
print(c1)
class Prime:
    def __init__(self,list):
        self.list=list
    def filter(s):
        i=0
        while i<len(s.list):
            j=2
            while j<((s.list)[i]):
                if (s.list)[i]%j==0:
                    del (s.list)[i]
                    i-=1
                    break
                j+=1
            i+=1
    def show(s):
        print(s.list)
    def need(s):
        print(type(s.list[0]))
prm=Prime([13,17,5,6,19,3,4,1652123])
prm.need()
prm.filter()
prm.show()