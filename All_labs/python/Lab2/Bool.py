print(10==10)
q=10
b=3
if(q>b):
    print("Q wins")
else:
    print("B wins")
print(bool(15))
print(bool("SPRING"))
print(bool(0))
print(bool(""))
def Zero():
    return 0
print(bool(Zero()),"zero")
def Tru():
    return 1
if Tru():
    print("You are serious?!")
else:
    print("Imposable")
x=5
print(isinstance(x, int))