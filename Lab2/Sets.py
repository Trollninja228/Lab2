#Set items are unchangeable, but you can remove items and add new items.
s={'aproximation','rule','disaster','rule',0,False,0,"Test"}#elements can't duplicate
print(s)#in random order
print(len(s))
print(type(s))
for x in s:
    print(x)
print("//////////")
if 0 in s:
    print(True)
s.add("Something")
s1=["It is",'the New',"Set"]
s.update(s1)
s.remove("aproximation")# or s.discard("aproximation")
x=s.pop()#удаляет и присваивает значение удалённого элемента иксу
print("Deleted elemet:",x)
print(s)
s2=["The",'old','man']
s3=s.union(s2)
s1.clear()#or del s1
print(s3)
s4=s3.intersection(s2)
s3.intersection_update(s2)
print(s3)
print(s4==s3)
s3.add("Laptop")
s4.symmetric_difference_update(s3)
print(s4)
