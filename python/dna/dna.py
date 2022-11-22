import sys
import csv

AGATC =  0
tmp_AGATC =  0
AATG = 0
tmp_AATG = 0
TATC = 0
tmp_TATC = 0
TTTTTTCT = 0
tmp_TTTTTTCT = 0
TCTAG = 0
tmp_TCTAG = 0
GATA = 0
tmp_GATA = 0
GAAA = 0
tmp_GAAA = 0
TCTG = 0
tmp_TCTG = 0

if len(sys.argv) == 3:
    if sys.argv[1] == 'databases/large.csv' or sys.argv[1] == 'databases/small.csv':
        infile_sequence = sys.argv[2]
        with open(infile_sequence, 'r') as sequence_file:
            sequence = sequence_file.read()
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

            infile_database = sys.argv[1]
            with open(infile_database, 'r') as csv_file:
                csv_reader = csv.reader(csv_file)
                count = 0
                for row in (csv_reader):
                    if count == 0:
                        count += 1
                    elif count != 0:
                        compatibility_count = 0
                        if sys.argv[1] == 'databases/small.csv':
                            if AGATC == int(row[1]):
                                compatibility_count += 1
                            if AATG == int(row[2]):
                                compatibility_count += 1
                            if TATC == int(row[3]):
                                compatibility_count += 1
                            if compatibility_count == 3:
                                print(f"{row[0]} is the murderer.")
                        elif sys.argv[1] == 'databases/large.csv':
                            if AGATC == int(row[1]):
                                compatibility_count += 1
                            if TTTTTTCT == int(row[2]):
                                compatibility_count += 1
                            if AATG == int(row[3]):
                                compatibility_count += 1
                            if TCTAG == int(row[4]):
                                compatibility_count += 1
                            if GATA == int(row[5]):
                                compatibility_count += 1
                            if TATC == int(row[6]):
                                compatibility_count += 1
                            if GAAA == int(row[7]):
                                compatibility_count += 1
                            if TCTG == int(row[8]):
                                compatibility_count += 1
                            if compatibility_count == 8:
                                print(f"{row[0]} is the murderer.")


print(f"AGATC: {AGATC}")
print(f"TTTTTTCT: {TTTTTTCT}")
print(f"AATG: {AATG}")
print(f"TCTAG: {TCTAG}")
print(f"GATA: {GATA}")
print(f"TATC: {TATC}")
print(f"GAAA: {GAAA}")
print(f"TCTG: {TCTG}")
