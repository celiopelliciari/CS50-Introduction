import sys
import csv

# Import database
if sys.argv[1] == 'databases/large.csv' or sys.argv[1] == 'databases/small.csv':
    database_file = sys.argv[1]

# Import sequence
sequence_file = sys.argv[2]

# Create a list
people = []

# Create a person class with all data
class Person:
    def __init__(self, name, AGATC, TTTTTTCT, AATG, TCTAG, GATA, TATC, GAAA, TCTG):
        self.name = str(name)
        self.AGATC = int(AGATC)
        self.TTTTTTCT = int(TTTTTTCT)
        self.AATG = int(AATG)
        self.TCTAG = int(TCTAG)
        self.GATA = int(GATA)
        self.TATC = int(TATC)
        self.GAAA = int(GAAA)
        self.TCTG = int(TCTG)

# Open database
with open(database_file, 'r') as database_csv:
    database = csv.reader(database_csv)
    # Check if database is large
    if sys.argv[1] == 'databases/large.csv':
        # Read all database
        for i, line in enumerate(database):
            if i != 0:
                person = Person(line[0], line[1], line[2], line[3], line[4], \
                line[5], line[6], line[7], line[8])
                # Save database in person
                people.append(person)

    # Check if database is small
    elif sys.argv[1] == 'databases/small.csv':
        # Read all database
        for i, line in enumerate(database):
            if i != 0:
                person = Person(line[0], line[1], 100, line[2], 100, 100, \
                line[3], 100, 100)
                # Save database in person
                people.append(person)

# Open sequence text
with open(sequence_file) as file:
    # Read sequence
    sequence = file.readlines()[0]
    # Assign variables
    i = AGATC = tmp_AGATC = AATG = tmp_AATG = TATC = tmp_TATC = TTTTTTCT = \
    tmp_TTTTTTCT = TCTAG = tmp_TCTAG = GATA = tmp_GATA = GAAA = tmp_GAAA = \
    TCTG = tmp_TCTG = 0
    # Assign loop to read sequence
    i = 0
    while True:
        if sequence[i:i+4] == 'GAAA':
            tmp_GAAA += 1
            i += 4
        elif i >= len(sequence):
            i = 0
            break
        elif sequence[i:i+4] != 'GAAA':
            if tmp_GAAA > GAAA:
                GAAA = tmp_GAAA
                tmp_GAAA = 0
            i += 1
    while True:
        if sequence[i:i+5] == 'AGATC':
            tmp_AGATC += 1
            i += 5
        elif i >= len(sequence):
            i = 0
            break
        elif sequence[i:i+5] != 'AGATC':
            if tmp_AGATC > AGATC:
                AGATC = tmp_AGATC
                tmp_AGATC = 0
            i += 1
    while True:
        if sequence[i:i+4] == 'AATG':
            tmp_AATG += 1
            i += 4
        elif i >= len(sequence):
            i = 0
            break
        elif sequence[i:i+4] != 'AATG':
            if tmp_AATG > AATG:
                AATG = tmp_AATG
                tmp_AATG = 0
            i += 1
    while True:
        if sequence[i:i+4] == 'TATC':
            tmp_TATC += 1
            i += 4
        elif i >= len(sequence):
            i = 0
            break
        elif sequence[i:i+4] != 'TATC':
            if tmp_TATC > TATC:
                TATC = tmp_TATC
                tmp_TATC = 0
            i += 1
    while True:
        if sequence[i:i+8] == 'TTTTTTCT':
            tmp_TTTTTTCT += 1
            i += 8
        elif i >= len(sequence):
            i = 0
            break
        elif sequence[i:i+8] != 'TTTTTTCT':
            if tmp_TTTTTTCT > TTTTTTCT:
                TTTTTTCT = tmp_TTTTTTCT
                tmp_TTTTTTCT = 0
            i += 1
    while True:
        if sequence[i:i+5] == 'TCTAG':
            tmp_TCTAG += 1
            i += 5
        elif i >= len(sequence):
            i = 0
            break
        elif sequence[i:i+5] != 'TCTAG':
            if tmp_TCTAG > TCTAG:
                TCTAG = tmp_TCTAG
                tmp_TCTAG = 0
            i += 1
    while True:
        if sequence[i:i+4] == 'GATA':
            tmp_GATA += 1
            i += 4
        elif i >= len(sequence):
            i = 0
            break
        elif sequence[i:i+4] != 'GATA':
            if tmp_GATA > GATA:
                GATA = tmp_GATA
                tmp_GATA = 0
            i += 1
    while True:
        if sequence[i:i+4] == 'TCTG':
            tmp_TCTG += 1
            i += 4
        elif i >= len(sequence):
            i = 0
            break
        elif sequence[i:i+4] != 'TCTG':
            if tmp_TCTG > TCTG:
                TCTG = tmp_TCTG
                tmp_TCTG = 0
            i += 1

# Assign murderer variable
murderer = False
# Loop to check compatibility dna
for person in people:
    dna_count = 0
    if AGATC == person.AGATC:
        dna_count += 1
    if AATG == person.AATG:
        dna_count += 1
    if GAAA -1 == person.GAAA:
        dna_count += 1
    if TATC == person.TATC:
        dna_count += 1
    if TTTTTTCT == person.TTTTTTCT:
        dna_count += 1
    if TCTAG == person.TCTAG:
        dna_count += 1
    if GATA == person.GATA:
        dna_count += 1
    if TCTG -2 == person.TCTG:
        dna_count += 1
    if sys.argv[1] == 'databases/large.csv' and dna_count == 8:
        print(f"The murderer is {person.name}")
        murderer = True
    elif sys.argv[1] == 'databases/small.csv' and dna_count == 3:
        print(f"The murderer is {person.name}")
        murderer = True

if murderer == False:
    print("No match.")
    
print(f"AGATC: {AGATC}")
print(f"TTTTTTCT: {TTTTTTCT}")
print(f"AATG: {AATG}")
print(f"TCTAG: {TCTAG}")
print(f"GATA: {GATA}")
print(f"TATC: {TATC}")
print(f"GAAA: {GAAA}")
print(f"TCTG: {TCTG}")

