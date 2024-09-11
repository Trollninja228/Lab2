import re
l=input("Print the phone number:")
li=list(l)
if re.match(r"(\+7|8)-[0-9]{3}-[0-9]{3}-[0-9]{2}-[0-9]{2}",l):
    print("Kazakhstan")
else:
    print("isn't Kazakhstan")
