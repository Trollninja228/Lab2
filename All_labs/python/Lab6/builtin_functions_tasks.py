nums=[1,2,3,4,5,6,7,8,9,10]
res=1
def factorial(n):
    global res
    res*=n
    return res
first=list(map(factorial,nums))
print(first)
#second
string="AAAbbbAbCcd" #5 upper and 6 lower
sum=0
def u_filter(n):
    if n==n.upper():
        return n
    else:
        return ""
def l_filter(n):
    if n==n.lower():
        return n
    else:
        return ""
print("Number of upper cases:",len(list(filter(u_filter,string))))
print("Number of lower cases:",len(list(filter(l_filter,string))))
#third

word="word"
pol='aboba'
def pol_check(p):
    if p==''.join(reversed(p)):
        return True
    else:
        return False
print(pol_check(word))
print(pol_check(pol))

#fourth

import time
number=int(input('Sample Input:'))
ti=int(input("Time in milliseconds:"))/1000
time.sleep(ti)
print(number**(1/2))

#fives
b={True,True,False}
c={True,True,True}
print(all(b))
print(all(c))