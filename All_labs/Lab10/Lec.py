import psycopg2

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

#INSERT
cur.execute("""INSERT INTO students_data(name,id,study_year,phone_number) VALUES
            ('Ruslan','24B202424',1,'+77007007070'),
            ('Mariya','24B202425',1,'+77077077070');
""")
conn.commit()

#UPDATE
cur.execute("""UPDATE students_data
            SET study_year=2
            WHERE name='Ruslan';
""")
conn.commit()

#DELETE object from table
cur.execute("""DELETE FROM students_data
            WHERE name='Mariya';
""")
conn.commit()
