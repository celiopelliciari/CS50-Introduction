twenty_five = 0
ten = 0
five = 0
one = 0

cashback = float(input("How much is cashback: "))

while cashback > 0.25:
    cashback -= 0.25
    twenty_five += 1

while cashback > 0.10:
    cashback -= 0.10
    ten += 1

while cashback > 0.05:
    cashback -= 0.05
    five += 1

while cashback > 0.01:
    cashback -= 0.01
    one += 1

print(f"Twenty_five: {twenty_five} \n Ten: {ten} \n Five: {five} \n One: {one}")