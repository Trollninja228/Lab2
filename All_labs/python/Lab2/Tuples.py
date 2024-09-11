#tuples нельзя менять, элементы могут повторяться
tup=("Lul",)
tup1=("Lul")
print(type(tup))
print(type(tup1)) #string
tup2=(1,2,3,4,5,"It going to hunt")
print(tup2[-1])
print(tup2[2:])
if  4 in tup2:
    print("4 is there")
y=list(tup)
y[0]="Something"
y.append("New?")
tup=tuple(y)
print(tup)
tup1=tuple(tup1)
tup1+=tup
print(tup1)
(one,two,*three)=tup2
print(one)
print(two)
print(three)
for x in tup:
    print(x)
i=0
while i <len(tup1):
    print(tup1[i])
    i+=1
tup*=2
print(tup)
print(tup.count("New?"))
print(tup.index("New?"))