import re
# * 0 or more occorences
#+ 1 or more occurences
#? - 0 or 1 occerence
#. - any character
#{2}-exactly 2 occurences
#{1,3} - from 1 to 3 occurences (including)
#{1,} - at least 1 occurence
#{,3} - no more than 3 occurences
string="AbccccccabcAb"
print(re.findall("Ab",string))
print(re.findall("bc*",string))
print(re.findall("bc{2}",string))
print(re.findall("bc?",string))
print(re.findall("bc{1,3}",string))
print(re.findall("bc{1,}",string))
#special sequences
#\d - any decimal digit
#\D - any character besides decimal digits
#\w - any alphanumeric character
#\W - any non-alphanumeric character
#\s - any whitespace character (a space. a newline, etc)
#\S - ant non-whitespace character
#\b - match at the begining or at the end of the word (e.g \bain or ain\b)
#\b - match not at the begining or at the end of the word
string="Abc123ccccc12345     Abbc_Ab\n_abcAb\nAb"
#print(re.findall("r\d",string)) or print(re.findall("\\d",string))
#r - raw string
print(r"\nHello!\tGow are you","\nHello!\tGow are you")
print(re.findall("\d",string))
print(re.findall("\D",string))
print(re.findall("\w",string))
print(re.findall("\W",string))
print(re.findall("\s",string))
print(re.findall("\S",string))
print(re.findall(r"\bAb",string))
print(re.findall(r"Ab\b",string))
print(re.findall(r"\bAb\b",string))
print(re.findall(r"Ab\B",string))
print(re.findall(r"\BAb",string))
print(re.findall(r"\BAb\B",string))

# findall, match, fullmatch, search, finditer, compile
#findall - find all matches in the string. returns the list of match object
#match - finds the mathces only in the begining of the string, return match object
#match - finds the mathces in the all of the string, return match object
print(re.match("Abc",string))
print(re.match("123",string))

print(re.search("Abc",string))
print(re.search("123",string))

print(re.fullmatch("Abc",string))
print(re.fullmatch("Abc123ccccc12345     Abbc_Ab\n_abcAb\nAb",string))

print("m:")
m=re.match("Abc",string)
print(m,m.group(0),m.span(),m.start(),m.end(),sep="\n")
print(m.string)

m=re.finditer("Abc*",string)
print("finditer:")
for x in m:
    print(x)
    print(x.group())
    print(x.span())
    print(x.start())
    print(x.end())
#compile- accepts a regex pattern and return a regex object
patt=re.compile("Abc")
print(patt)
print(patt.findall(string))

#escaping characters
#\ - used to escape characters
print("---------")
string="Abc123ccccc12345+*     +Abb+*c_Ab\n_ab*+cAb\nAb-"
e=re.finditer(r"\+\*",string)
for x in e:
    print(x)
m=re.finditer(r"[Abc]",string)
for x in m:
    print(x)
m=re.finditer(r"[a-z]",string)
for x in m:
    print(x)
m=re.finditer(r"[a-zA-z0-9-]",string)
for x in m:
    print(x)
print(re.findall(r"b..",string))
#I'm so tired