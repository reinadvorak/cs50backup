

person1 = {
    "name" : "EMMA",
    "number": "559-111-1111",
    "age": 42
}

person2 = {}
person2["name"] = "RODRIGO"
person2["number"] = "559-222-2222"
person2["age"] = 65

contacts = []
contacts.append(person1)
contacts.append(person2)

print(contacts[0]['name'])

print(person1["age"])
from cs50 import get_string

target = get_string("Name: ")
for contact in contacts:
    if contact['name'] == target:
        print(contact['number'])

