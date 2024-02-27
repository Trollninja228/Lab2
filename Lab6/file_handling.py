#reading drom files
#creating files
#writing to files
import os
print(os.listdir())

#check if there directory or file
pathes=os.listdir()
for path in pathes:
    print("file:",os.path.isfile(path))
    print("DIR",os.path.isdir(path))

#creating files
dir="EXAMPLE"
print(os.listdir(dir))
'''for i in range(1,31):
    file=open(f"{dir}{i}.txt","x") 
    file.close()''' #DANGER

#reading
file=open("example.txt") #стандартно фаил открывется в режиме чтения
print(file.read())
file.close()


#writing

file=open("ex2.txt","w")
file.write("Very simple Test")
file.close()
file=open("ex2.txt")
print(file.read())
file.close()


#deleting
"""file=open("delete.txt","x")
os.remove("delete.txt")
file.close()"""


#deleting folder
os.mkdir("smt") #create dir
os.rmdir("smt")

#append to the file and creating it if the file doesn't exist
file=open("ex3.txt","a")
file.write("\nOr no?")

#check if the file exist
path="ex2.txt"
print(os.path.exists(path))

#checking access to the file
path="ex3.txt"
print(os.access(path,os.F_OK))#existence
print(os.access(path,os.R_OK))#readibility
print(os.access(path,os.W_OK))#writability
print(os.access(path,os.X_OK))#executability
