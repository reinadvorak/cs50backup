from cs50 import get_float

while True:
    dollars = get_float("Changed owed: ")
    if dollars > 0:
        break

change = round(dollars * 100)
coins = 0

while change >= 25:
    coins = coins + 1
    change = change - 25
while change >= 10:
    coins = coins + 1
    change = change - 10
while change >= 5:
    coins = coins + 1
    change = change - 5
while change >= 1:
    coins = coins + 1
    change = change - 1

print(coins)
