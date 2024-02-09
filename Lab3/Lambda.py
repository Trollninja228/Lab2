x= lambda t,q : t**q
a=int(input())
c=int(input())
print(x(a,c))
def n_myfunc(n):
  return lambda a : a * n
tripler=n_myfunc(3)
y=int(input())
multiper=n_myfunc(y)
print(tripler(a))
print(multiper(a))