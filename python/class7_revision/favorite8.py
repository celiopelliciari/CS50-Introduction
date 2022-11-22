import csv
from cs50 import SQL

# This is a way to create a blank file
open("shows.db", "w").close()
# SQL is importing 'shows.db' on the db variable
db = SQL("sqlite:///shows.db")

# Create a table with first column caled id and containing a integer value,
# second column caled title and containing a text value and
# a direction to sql know that 'id' is our primar key
db.execute("CREATE TABLE shows (id INTEGER, title TEXT, PRIMARY KEY(id))")
# In this one repeate the last process, but show_id is vinculate with
# 'foreign key' function and is vinculate with id, the first column of first table
db.execute("CREATE TABLE genres (show_id INTEGER, genre TEXT, FOREIGN KEY(show_id) REFERENCES shows(id))")

with open("Favorite TV Shows (Responses) - Form Responses 1.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        # read the csv file and assign each value of 'title' column to 'title' variable
        # .strip is used to take of blank spaces
        title = row["title"].strip().upper()

        # 'id' is the name of first column of our first table
        # 'db.execute' is putting the title inside our sql file
        # 'VALUES(?)' mean the value is comming after comma
        id = db.execute("INSERT INTO shows (title) VALUES(?)", title)

        # Here we're putting each genres, even when have more than one in the same column
        # into our genre table
        for genre in row["genres"].split(", "):
            # Assign first value of this table with id (or first value of first table)
            # and "genre" value with the genre variable
            db.execute("INSERT INTO genres (show_id, genre) VALUES(?, ?)", id, genre)