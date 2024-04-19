import psycopg2
import csv

conn=psycopg2.connect(
    host='localhost', 
    dbname='students', 
    user='postgres', 
    password='5667262005'
    )
cur=conn.cursor()
#DELETE table
cur.execute("DROP TABLE students_data")
conn.commit()

#CREATE
cur.execute("""create table students_data(
            name VARCHAR(255),
            id VARCHAR(255) PRIMARY KEY,
            study_year INT,
            phone_number VARCHAR(20)
);
""")
conn.commit()

filename="C:/Users/Пчел/Desktop/Labs/All_labs/Lab10/students_csv.csv"
with open(filename,"r") as csvfile:
    csvreader=csv.reader(csvfile,delimiter=",")
    for row in csvreader:
        name,id,study_year,phone_number=row
        study_year=int(study_year)
        cur.execute("""INSERT INTO students_data(name, id, study_year, phone_number) 
                       VALUES ('{name}', '{id}', {study_year}, '{phone_number}')""")
conn.commit()