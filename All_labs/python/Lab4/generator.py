a=range(5)
nums=list(a)
print (nums)
def myRange(stop):
    start=0
    while start <stop:
        yield start
        start+=1
b=list(myRange(5))
print (b)
def squaresRange(stop):
    start=0
    while start <stop:
        yield start**2
        start+=1
c=list(squaresRange(5))
print (c)
for num in nums:
    print(num,end=',')
print('')
nums_str=', '.join(map(str,nums))
print(nums_str)
