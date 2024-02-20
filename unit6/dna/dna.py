import csv
import sys


def main():
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    csv_file = []
    with open(sys.argv[1], newline="") as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            csv_file.append(row)

    f = open(sys.argv[2], "r")
    dna = f.read()

    strs = []
    for key in row:
        if key != "name":
            row[key] = int(row[key])
            strs.append(key)
    repeat = []
    maximum = []
    count = 0
    for i in range(len(strs)):
        for j in range(len(dna)):
            if dna[j : j + len(strs[i])] == strs[i]:
                count = count + 1
                while (
                    dna[j : j + len(strs[i])]
                    == dna[j + len(strs[i]) : j + (2 * len(strs[i]))]
                ):
                    count = count + 1
                    j = j + len(strs[i])
            repeat.append(count)
            count = 0
        maximum.append(max(repeat))
        list.clear(repeat)
    # print(maximum)

    match = "no match"
    i = 0
    for element in csv_file:
        numbers_list = []

        for key in csv_file[0].keys():
            if key != "name":
                element[key] = int(element[key])
                numbers_list.append(csv_file[i][key])
        i = i + 1
        # print(numbers_list)
        if maximum == numbers_list:
            match = element["name"]
    print(match)


main()
