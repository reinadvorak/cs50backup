from cs50 import get_string

word = get_string("Input: ")
length = len(word)
for i in range(length):
    if word[i].islower():
        print(word[i].upper(), end="")
    else:
        print(word[i], end='')
print()

# or: print(word.upper())
