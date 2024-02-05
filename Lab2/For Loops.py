for x in "Coca-Cola":
  print(x)
digits = [1,2,3,4,5,6,7,8,9]
for x in digits:
  if x == 7:
    continue
  if x == 8:
    break
  print(x)
for x in range(1, 20):
    print(x)
for x in range(12):
  if x == 5: 
    break
  print(x)
else:
  print("finished")
car=["Ford","Mercedes","Ferrari"]
year=[2000,2002,2010,2012,2015]

for x in car:
  for y in year:
    print(x, y)
#emptu loop:
for x in [0, 1, 2]:
  pass