import sys
from cs50 import get_int

def main():
    count = int(sys.argv[1])
    numbers = []
    for i in range(count):
        num = get_int("Number: ")
        numbers.append(num)
    # or delete everything below and: print(f"max is {max(numbers)}")
    print(f"largest: {find_largest(numbers, count)}")

def find_largest(list, n):
    largest = list[0]
    for k in range(n):
        if largest < list[k]:
            largest = list[k]
    return largest

main()

