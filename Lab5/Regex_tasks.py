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
