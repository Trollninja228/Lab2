def gramm_to_ounc(g):
  return 28.3495231*g
print(gramm_to_ounc(20))
def Celsia(F):
  return (5/9) * (F-32)
print(Celsia(98))
def solve(numheads, numlegs):
  k=2*numheads
  r=(numlegs-k)/2
  ch=numheads-r
  return ch,r
print(solve(35,94))
def filter_prime(s):
        i=0
        while i<len(s):
            j=2
            while j<(s[i]):
                if s[i]%j==0:
                    del s[i]
                    i-=1
                    break
                j+=1
            i+=1
        return s
list=[123,13,17,3,5,9,21,31,51,41]
print(filter_prime(list))
def permutation(l):
  while