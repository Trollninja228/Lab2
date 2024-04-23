import psycopg2
import csv

conn=psycopg2.connect(
    host='localhost', 
    dbname='PhoneBook', 
    user='postgres', 
    password='5667262005'
    )
cur=conn.cursor()
cur.execute("""create table main_data(
            id VARCHAR(255) PRIMARY KEY,
            name VARCHAR(255),
            phone_number VARCHAR(20)
);
""")
conn.commit()