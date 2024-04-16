import psycopg2

conn = None

try:
    conn = psycopg2.connect(
        host="localhost",
        dbname="suppliers",
        user="postgres",
        password="1234",
        client_encoding="latin1"  # Указываем явную кодировку
    )
    print("Successfully connected to the database.")

    cur = conn.cursor()
    print("Data:")
    cur.execute("SELECT version()")

    db_ver = cur.fetchall()
    print(db_ver)

except psycopg2.Error as e:
    print("Error connecting to the database:", e)
finally:
    if conn:
        conn.close()
