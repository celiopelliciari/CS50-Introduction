import csv
from sys import argv, exit



if len(argv) != 3:
    print("Incorrect number of arguments!")
    exit(1)

with open("sequences/" + argv[2] + ".txt", "r") as file:
    sampleFile = file.readlines()
    sample = sampleFile[0]

sequences = []
suspects = {}
with open("databases/" + argv[1] + ".csv", "r") as file:
    sampleFile = csv.reader(file)
    for column in next(sampleFile):
        sequences.append(column)
    sequences.pop(0)

    for row in sampleFile:
        name = ""
        susSequences = []
        for i, column in enumerate(row):
            if i == 0:
                name = column
            else:
                susSequences.append(column)
        suspects[name] = susSequences

sequenceCounts = [0 for i in range(len(sequences))]
i = j = 0
for sequence in sequences:
    tempCount = 0
    count = 0
    while True:
        if i < len(sample) - len(sequence) + 1:

            currentSequence = ""
            for k in range(len(sequence)):
                currentSequence += sample[i+k]

            if currentSequence == sequence:
                tempCount += 1
                if tempCount > count:
                    count = tempCount
                i += len(sequence)
            else:
                tempCount = 0
                i += 1
        else:
            break
    sequenceCounts[j] = count
    j += 1
    i = 0
print("Sequence is: ", end="")
print(sequenceCounts)

for suspect in suspects:
    suspicion = 0
    for i in range(len(suspects[suspect])):
        if suspects[suspect][i] == str(sequenceCounts[i]):
            suspicion += 1
    if suspicion == len(sequences):
        print(f"{suspect.upper()} IS THE MURDERER!")
        exit(0)
print("No match! The murderer got away!")