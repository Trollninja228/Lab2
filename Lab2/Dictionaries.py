'''Dictionaries are used to store data values in key:value pairs.
A dictionary is a collection which is ordered*, changeable and do not allow duplicates.
As of Python version 3.7, dictionaries are ordered. In Python 3.6 and earlier, dictionaries are unordered.
'''
d = {
  "brand": "Mercedes",
  "model": "A-class",
  "year": 2019,
  "year": 2022, #will switch the last year
  "colors": ['red','black','white','blue'],

}
print(d)
print(d["brand"])
print(len(d))
print(type(d))
d1=dict(name="Anonymus", age="n, where n any real number", phone="unknown Chinese model")
print(d1["phone"])
y=d.get("year")
#or
m=[d["brand"],d["model"]]
print(m,y)
k=d.keys()
v=d.values()
i=d.items()
print(k)
print(v)
print(i)
print(type(k))
print(type(v))
print(type(i))
d["usage"]="2 years"
print(d)
if "year" in d:
    print("Dictionari has year")
else:
    print("Dictionari hasn't year")
d['model']="B-class"    
d.update({"number of crashes": 0})
print(d)
d.pop("colors") #or del d[colors]
d["TEST"]="DELETE ME"
d.popitem() #delete last element
for x in d:
    print(x,":", d[x])
#d=d1 объединяет d и d1
d1=dict(d)
cars = {
  "Ford" : {
    "model" : "Mustang",
    "year" : 1986
  },
  "Lada" : {
    "model" : "Niva",
    "year" : 1990
  },
  "Nissan" : {
    "model" : "Elgrand",
    "year" : 1990
  }
}
print(cars)
cars.clear()
#or
Ford = {
    "model" : "Mustang",
    "year" : 1986
  }
Lada = {
    "model" : "Niva",
    "year" : 1990
  }
Nissan = {
    "model" : "Elgrand",
    "year" : 1990
  }
cars={
    "Ford":Ford,
    "Lada":Lada,
    "Nissan":Nissan
}
print(cars)
print(cars["Ford"]["year"])
