def squares_list(n):
    s=1
    while s**2<n or s**2==n:
        yield s**2
        s+=1
c=list(squares_list(100))
print(c)
n=int(input())
def even(n):
    print("Even numbers:")
    i=1
    while i<n:
        if i%2==0:
            yield i
        i+=1
c=list(even(n))
c=", ".join(map(str,c))
print (c)
def th_fo(n):
    print("divisible by 3 and 4:")
    i=1
    while i<n:
        if i%3==0 or i%4==0:
            print(i)
        i+=1
n=31
th_fo(n)
def squares(a,b):
    print("Squares:")
    i=a
    for a in range(b):
        if i**2>b:
            break
        yield i**2
        i+=1
        a+=1
c=list(squares(2,100))
print(c)
def to_zero(n):
    print("Deacreasing to zero:")
    i=n
    while i>0:
        yield i
        i-=1
c=list(to_zero(100))
print(c)
