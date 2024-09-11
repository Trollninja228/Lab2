"""def Celsia(F):
  return (5/9) * (F-32)"""
far=lambda c: ((9/5)*c)+32
print(far(36.6))
l=[100,36.6,12,38]
def print_Farenheit(l):
    i=0
    while i<len(l):
        l[i]=far(l[i])
        print(l[i])
        i+=1
print_Farenheit(l)