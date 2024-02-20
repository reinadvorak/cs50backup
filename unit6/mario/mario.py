from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height >= 1 and height <= 8:
        break

x = 0
for x in range(height):
    y = 0
    z = height - 1
    while z > x:
        print(" ", end="")
        z = z - 1
    while y <= x:
        print("#", end="")
        y = y + 1
    x = x + 1
    print("\n", end="")
