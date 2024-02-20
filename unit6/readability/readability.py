from cs50 import get_string

text = get_string("Text: ")

letters = 0
length = len(text)
for i in range(length):
    if text[i].islower():
        letters = letters + 1
    if text[i].isupper():
        letters = letters + 1

sentences = 0
for i in range(length):
    if text[i] == "." or text[i] == "!" or text[i] == "?":
        sentences = sentences + 1

words = 1
for i in range(length):
    if text[i] == " ":
        words = words + 1

L = 0
L = float(letters) / float(words) * 100

S = 0
S = float(sentences) / float(words) * 100

index = 0
index = 0.0588 * L - 0.296 * S - 15.8

grade = round(index)
if grade >= 1 and grade <= 16:
    print(f"Grade {grade}")
if grade < 1:
    print(f"Before Grade 1")
if grade > 16:
    print(f"Grade 16+")
