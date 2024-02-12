def tri_recursion(k):
  if(k > 0):
    result = k + tri_recursion(k - 1)
    print(result)
  else:
    result = 0
  return result

print("\n\nRecursion Example Results")
tri_recursion(6)
s="test"
print(s.upper())
y=[1,12,13,17,19]
del y[0]
print(len(y))
print(y[-1])
str="Testt"
print(len(str))
str=str.replace("t","")
print(str)
print(len(str))
S = "abcd"
Index=1 #index of string to remove
ListS = list(S)
ListS.pop(Index)
S = "".join(ListS)
print (S)
def game():
   name=input("Hello! What is your name?")
game()