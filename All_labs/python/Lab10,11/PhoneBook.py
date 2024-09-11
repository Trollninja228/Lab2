import psycopg2
import csv
conn=psycopg2.connect(
    host='localhost', 
    dbname='PhoneBook', 
    user='postgres', 
    password='5667262005'
    )
cur=conn.cursor()
done=True
while done:
    action=input("If you want to update table from command line press \"u\",from csv file press\"c\". If you want do delete user press \"d\", to insert press \"i\". If you want to search user press \"s\".If you want to stop programm,write\"stop\". If you want use function print \"func\".If you want use procedure print \"proc#\" and number of procedure.>>")
    if action=="u":
        ID=input("ID:")
        check_id=True
        while check_id:
            changes=input("which parameter you want to change?>>")
            if changes=="id":
                print("You can't change id.")
            else:
                check_id=False
        values=input("on what values?>>")
        command=f"""UPDATE main_data
            SET {changes}='{values}'
            WHERE id='{ID}';
        """
        cur.execute(command)
        conn.commit()
    elif action=="i":
        # changes=input("which parameter you want to insert?>>")
        id=input("enter ID>>")
        name=input("enter name>>")
        phone_number=input("enter phone_number>>")
        command=f"""INSERT INTO main_data(id,name,phone_number) VALUES
                ('{id}','{name}','{phone_number}');"""
        cur.execute(command)
        conn.commit()
    elif action=="stop":
        done=False
    elif action=="c":
        path_to_file="C:/Users/Пчел/Desktop/Labs/All_labs/Lab10,11/"+input("enter name of file>>")
        # path_to_file="C:/Users/Пчел/Desktop/Labs/All_labs/Lab10/PhoneBook_csv.csv"
        with open(path_to_file,"r") as csvfile:
            csvreader=csv.reader(csvfile,delimiter=",")
            for row in csvreader:
                id,name,phone_number=row
                command=f"""INSERT INTO main_data(id,name,phone_number) 
                        VALUES ('{id}','{name}','{phone_number}');"""
                cur.execute(command)
                conn.commit()
    elif action=="d":
        id=input("input ID, that you want to delete>>")
        command=f"""DELETE FROM main_data
            WHERE id='{id}';
        """
        cur.execute(command)
        conn.commit()
    elif action=="s":
        id=input("input ID of person, that you want to search>>")
        command=f"""SELECT id,name,phone_number from main_data
                    WHERE id='{id}';
        """
        cur.execute(command)
        print(cur.fetchall())
        conn.commit()
    elif action=="func":
        cur.callproc('get_all_data',)
        print(cur.fetchall())
    elif action=="proc#1":
        id=input("enter ID>>")
        name=input("enter name>>")
        phone_number=input("enter phone_number>>")
        cur.execute(f"CALL insert_or_update_user('{id}','{name}','{phone_number}');")
        conn.commit()
    elif action=="proc#2":
        num=input("How many people?>>")
        num= int(num)
        data=()
        while not num == 0:
            num-=1
            id=input("enter ID>>")
            name=input("enter name>>")
            cur.execute(f"CALL insert_or_update_user('{id}','{name}','{phone_number}');")
            conn.commit()
    elif action=="proc#3":
        name_table=input("enter name_table>>")
        criteria=input("enter criteria>>")
        cur.execute(f"CALL delete_data_by_criteria('{name_table}', '{criteria}');")
        conn.commit()