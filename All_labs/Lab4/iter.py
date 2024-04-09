nums=[0,1,2,3,4,5]
n_iter=iter(nums)
'''for x in n_iter:
    print(x)'''
'''print(next(n_iter))
print(next(n_iter))
print(next(n_iter))
print(next(n_iter))
print(next(n_iter))
print(next(n_iter))'''
class Nums:
    def __init__(self,start,stop):
        self.start=start
        self.stop=stop
    def __iter__(self):
        self.start=1
        return self
    def __next__(self):
        x= self.start
        if x>self.stop:
            raise StopIteration
        self.start+=1
        return x
nums=Nums(1,20)
nums_it=iter(nums)
print(next(nums_it))
print(next(nums_it))
print(next(nums_it))
print(next(nums_it))
print(next(nums_it))
print(next(nums_it))
print(next(nums_it))
print(next(nums_it))
#we need to limit this
for x in nums:
    print(x)
