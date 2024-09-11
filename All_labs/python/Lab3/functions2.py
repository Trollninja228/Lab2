# Dictionary of movies

movies = [
{
"name": "Usual Suspects", 
"imdb": 7.0,
"category": "Thriller"
},
{
"name": "Hitman",
"imdb": 6.3,
"category": "Action"
},
{
"name": "Dark Knight",
"imdb": 9.0,
"category": "Adventure"
},
{
"name": "The Help",
"imdb": 8.0,
"category": "Drama"
},
{
"name": "The Choice",
"imdb": 6.2,
"category": "Romance"
},
{
"name": "Colonia",
"imdb": 7.4,
"category": "Romance"
},
{
"name": "Love",
"imdb": 6.0,
"category": "Romance"
},
{
"name": "Bride Wars",
"imdb": 5.4,
"category": "Romance"
},
{
"name": "AlphaJet",
"imdb": 3.2,
"category": "War"
},
{
"name": "Ringing Crime",
"imdb": 4.0,
"category": "Crime"
},
{
"name": "Joking muck",
"imdb": 7.2,
"category": "Comedy"
},
{
"name": "What is the name",
"imdb": 9.2,
"category": "Suspense"
},
{
"name": "Detective",
"imdb": 7.0,
"category": "Suspense"
},
{
"name": "Exam",
"imdb": 4.2,
"category": "Thriller"
},
{
"name": "We Two",
"imdb": 7.2,
"category": "Romance"
}
]
def rates(m,mov):
  i=0
  while i<len(mov):
    if mov[i]["name"]==m:
      if mov[i]["imdb"]>5.5:
        return True
      else:
        return False
    i+=1
m=input()
if rates(m,movies):
  print("Good movie")
else:
  print("Not good movie")
def sublist(mov):
  i=0
  while i<len(mov):
    if mov[i]["imdb"]>5.5:
      print(mov[i])
    i+=1
sublist(movies)
def f_cat(m,mov):
  print("One category:")
  q=""
  i=0
  while i<len(mov):
    if mov[i]["name"]==m:
      q=mov[i]["category"]
    i+=1
  i=0
  while i<len(mov):
    if mov[i]["category"]==q:
      print(mov[i])
    i+=1
f_cat(m,movies)
def l_average(f,mov):
  sum=0.0
  i=0
  j=0
  while j<len(f):
    i=0
    while i<len(mov):
      if mov[i]["name"]==f[j]:
        sum+=mov[i]["imdb"]
      i+=1
    j+=1
  print("Average of list:",sum/j)   
f=["Detective","We Two","Exam"]
l_average(f,movies)
def cat_average(f,mov):
  sum=0.0
  i=0
  j=0
  while i<len(mov):
    if mov[i]["category"]==f:
      j+=1
      sum+=mov[i]["imdb"]
    i+=1
  print("Average of category:",sum/j)
cat=input()
cat_average(cat,movies)