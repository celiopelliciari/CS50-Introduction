import csv

titles = {}

with open("Favorite TV Shows - Form Responses 1.csv", "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        title = row["title"].strip().upper()
        # It's literal if title is not in titles, we assign 0 value to title
        if title not in titles:
            titles[title] = 0
        titles[title] += 1

def f(title):
    return titles[title]

# Sorted function sorted by a-z title name
# If we wanted sorted by value of title value we need to use the sintaxe below
for title in sorted(titles, key=f, reverse=True):
    print(title, titles[title])