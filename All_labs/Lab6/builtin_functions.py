#map()
#chr()
#sum()
#filter()
#reversed()

#map
nums=[1,2,3,4,5]
double=list(map(lambda x : x*2, nums))
print(double)
n_str=', '.join(map(str,nums))
print(n_str)
#join and reversed
word= "reverse"
print(''.join(reversed(word)))
#filter()
nums=range(1,50)
n_filtered=filter(lambda x:x%2!=0,nums)
print(list(n_filtered))
import math
alphabet_ascii=list(range(65,91))
print(chr(65))
#chr()
alphabet_ascii=list(map(chr,alphabet_ascii))
print(alphabet_ascii)
#max,min
print(max(nums),min(nums))
#time module
#time.sleep()
import time

ms=1/1000

time.sleep(ms)
print("time:",ms)

#all()
#any()
print(all(nums))
nums=[2,4,6,8,11]
is_even=lambda x : x%2==0
print(all(map(is_even,nums)))
print(any(map(is_even,nums)))
