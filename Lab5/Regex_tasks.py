import re
s="sasFgabb.b, fdsadfda, b_adf_sAq_"
print(re.findall(r"ab*",s))
print(re.findall(r"ab{2,3}",s))
print(re.findall(r"[a-z]_[a-z]",s))
print(re.findall(r"[A-Z][a-z]",s))
print(re.findall(r".ab",s))
print(re.sub(r"\W","|",s))
snake="hello_i'm_lord_volamdemort"
camel=""
sn=snake.split("_")
for x in sn:
    camel+=x.capitalize()
print(camel)
c=re.findall("[A-Z]'*[a-z]*",camel)
print(c)
some=""
for x in c:
    some+=x+" "
print(some)
sth=""
for x in c:
    al=list(x)
    q=al[0].lower()
    al.pop(0)
    sth+=q
    for y in al:
        sth+=y
    sth+="_"
sth=list(sth)
sth.pop(len(sth)-1)
string=""
for x in sth:
    string+=str(x)
print(string)