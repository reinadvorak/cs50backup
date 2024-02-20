from cs50 import get_int

x = get_int("x: ")
y = get_int("y: ")

if x > y:
    print(f"{x} is bigger than {y}")
elif x < y:
    print(f"x is smaller than y")
else:
    print(f"x is equal to y")