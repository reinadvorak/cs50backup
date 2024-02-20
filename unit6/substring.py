from cs50 import get_string

string5 = get_string("String: ")
print(string5[2:-2:1])
print(string5[2:len(string5) - 2:1])

#Example of concatenation (putting two strings together)
string1 = "Good"
string2 = 'bye'
string3 = string1 + string2
print(string3)

#Example of substring
string4 = 'abcdefghij'
print(string4[2:5:1])

#Example of finding length of a string
print(len(string4))
