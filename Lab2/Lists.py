'''
List is a collection which is ordered and changeable. Allows duplicate members.
Tuple is a collection which is ordered and unchangeable. Allows duplicate members.
Set is a collection which is unordered, unchangeable*, and unindexed. No duplicate members.
Dictionary is a collection which is ordered** and changeable. No duplicate members.
'''
li=["acroba",'bravo','comrado',15321,11.5,12j]
print(li)
print(len(li))
print(li[1])
print(li[-1])
print(li[-3:-1])
if 12j in li:
    print("It have complex")
li[3]=120
li[0:3]=['slay','the','dragon']
li.insert(0,"You need")
li.append("- Code for locked safe")
print(li)
li1=['[DATA', 'DELETED]','Please safe my fami...']
li.extend(li1)
print(li)
li.remove(12j)
li.pop(5)
del li[8]
print(li)
