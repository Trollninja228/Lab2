import json
car={"make": "Lexus", 
     "model":"LFA",
     "color":"gray"}
car_json=json.dumps(car)#convert to json string
#or we can try
car1='{"make": "Lexus", "model":"LFA","color":"gray"}'
print(car_json)
print(car1)
file =open("CARS.json")
car2_json=file.read()
car2=json.loads(car2_json)
print(car2)
car2["year"]=2011
car2["num_of_crashes"]=0
file1=open("car_edite.json","w")
car2_json=json.dumps(car2)
file1.write(car2_json)
print(car2)