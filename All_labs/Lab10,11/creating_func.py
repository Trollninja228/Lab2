import psycopg2
from config import load_config
def create_function():
    commands=(""" CREATE OR REPLACE FUNCTION get_parts_by_vendor(id INTEGER)
                  RETURNS TABLE(part_id INTEGER, part_name VARCHAR) AS
                  $$
                  BEGIN
                  RETURN QUERY

                  SELECT parts.part_id, parts.part_name
                  FROM parts
                  INNER JOIN vendor_parts on vendor_parts.part_id = parts.part_id
                  WHERE vendor_id = id;

                  END; $$

                  LANGUAGE plpgsql;
              """,)
    try:
        config=load_config()
        with psycopg2.connect(**config) as conn:
            with conn.cursor() as cur:
                for command in commands:
                    print(commands)
                    print(command)
                    cur.execute(command)
    except (psycopg2.DatabaseError, Exception) as error:
        print(error)
if __name__=='__main__':
    create_function()