import psycopg2

conn=psycopg2.connect(
    host="localhost",
    dbname="suppliers",
    user="postgres",
    password="1234"
    )
cur=conn.cursor()
print("Data:")
cur.execute("SELECT version()")

db_ver=cur.fetchall()
print(db_ver)
