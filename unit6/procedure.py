from cs50 import get_int

def main():
    n = get_int("Number: ")
    hello(n)


def hello(n):
    for i in range(n):
        print(f"Hello!")


main()
