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

# Otherwise we can use the function in for line
for title in sorted(titles, key=lambda title: titles[title], reverse=True):
    print(title, titles[title])