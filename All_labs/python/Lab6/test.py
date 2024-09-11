print(chr(65),chr(90))
import os
print(type(os.listdir()))
p="C:/Users/Пчел/Desktop/Labs/Lab6/Task#6"
for x in range(65,91):
      file=open(f"{p}/{chr(x)}.txt","a")
      file.close()