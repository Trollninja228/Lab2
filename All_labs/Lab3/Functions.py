def func(name):
  print("Bye",name,"from a function")
name="Somebody"
func(name)
func("Nothing")
def func1(*name):
  print("Say something",name[1],"or",name[0])
func1("Joe","Priest","Lian")
def f2(n1,n2,n3):
  print(n1,n2,n3)
f2(n2="are",n3="you?",n1="Who")
def f3(**any):
  print(any["name"],any["speech"],any["years"],"years")
f3(name="Void,", speech="I live there", years=3118231653)
def country(country = "Germany"):
  print("Do tou like " + country+"?")
country("USA")
country()
fruits = ["apple", "banana", "cherry"]
def cout(any):
  for x in any:
    print(x)
cout(fruits)
def quadro(x):
  return  x*3
print(quadro(5))
def not_my_function(a, b, /, *, c, d):
  print(a + b + c + d)
not_my_function(5, 6, c = 7, d = 8)
def WHAT(q): 
  if q==0:
    r=0
  if q>0:
    r=q-WHAT(q-9)
    print(r)
  return 0
WHAT(81)