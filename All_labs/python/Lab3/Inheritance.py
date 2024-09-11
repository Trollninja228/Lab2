class Person:
  def __init__(self, fname, lname):
    self.firstname = fname
    self.lastname = lname

  def printname(self):
    print(self.firstname, self.lastname)
class Employer(Person):
  def __init__(self, fname, lname,work):
    Person.__init__(self, fname, lname)
    self.work=work
x=Employer("Mailo","Tetch","Researcher")
x.printname()
print(x.work)