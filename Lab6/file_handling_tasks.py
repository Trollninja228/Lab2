import os

#first
#1.1
DIR=os.listdir()
for x in DIR:
    if os.path.isdir(x):
        print(x)

#1.2
print(os.listdir())

#1.3
pa = os.listdir("C:/Users/Пчел/Desktop/Labs/Lab6")
for x in pa:
    if os.path.isfile(os.path.join("C:/Users/Пчел/Desktop/Labs/Lab6", x)): #если передём через терминал в папку в ту же диресторию, то join не нужен
        print(x)

#2
q=os.path.join("C:/Users/Пчел/Desktop/Labs/Lab6", "example.txt")
print(os.access(q,os.R_OK))#readibility
print(os.access(q,os.W_OK))#writability
print(os.access(q,os.F_OK))#existence
print(os.access(q,os.X_OK))#executability

#3
if os.path.exists("C:/Users/Пчел/Desktop/Labs/Lab6"):
    print(os.listdir())

#4

file=open("C:/Users/Пчел/Desktop/Labs/Lab6/num_lines.txt","r")
dict=list(file.read())
if not len(dict)==0:
    c=1
for x in dict:
    if x=='\n':
        c+=1
print("Num of lines:",c)
file.close()

#5

file=open("C:/Users/Пчел/Desktop/Labs/Lab6/write_to_me.txt","a")
li=["\nSimple test, or not?","or yes?"]
file.write(''.join(li))
file.close()

#6
p="C:/Users/Пчел/Desktop/Labs/Lab6/Task#6"
for x in range(65,91):
    file=open(f"{p}/{chr(x)}.txt","a")
    file.close()

#7

file1=open("C:/Users/Пчел/Desktop/Labs/Lab6/file#1.txt","r")
file2=open("C:/Users/Пчел/Desktop/Labs/Lab6/file#2.txt","w")
file2.write(file1.read())
file1.close()
file2.close()

#8

