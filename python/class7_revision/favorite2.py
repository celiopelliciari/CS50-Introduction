import csv

with open("Favorite TV Shows - Form Responses 1.csv", "r") as file:
   # DictReader is other way to interpreted a csv file
   # With this we do not need to call next function
   # And DictReader create a dict way to interpreted a csv file
   reader = csv.DictReader(file)

   for row in reader:
      # So when we want to print a line we can choose the name of value (name of columm)
      print(row["title"])