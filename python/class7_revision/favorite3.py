import csv

# Create a blank variable
titles = set()

with open("Favorite TV Shows - Form Responses 1.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
    # With add function in this loop we can select every movie title and check
    # if this name is an unique name and than put this name in titles varible
    # Using a strip function we take off all spaces in left and right
    # Using a upper function we put all letters in caps way
    # So in this way we are creating a padronization of our data
        titles.add(row["title"].strip().upper())

for title in titles:
    print(title)
