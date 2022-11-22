import csv

with open("Favorite TV Shows - Form Responses 1.csv", "r") as file:
   # .reader is a function of csv libary to interpretate the csv file
   reader = csv.reader(file)
   # next is a function to jump the first line of csv file
   next(reader)
   for row in reader:
      print(row[1])