def res(string):
    lst = list()
    char = string[0]
    char_collection = char

    for i in range(1, len(string)):
        if char == string[i]:
            char_collection += string[i]
        else:
            if "0" not in char_collection:
                lst.append(char_collection)
            char = string[i]
            char_collection = string[i]

    if "0" not in char_collection:
        lst.append(char_collection)

    lst.sort(key=lambda x: len(x))
    sum = 0

    for i in range(len(lst) - 1, -1, -2):
        sum += len(lst[i])

    print(sum)


t = int(input())
str_list = list()

for i in range(t):
    str_list.append(input())

for i in str_list:
    res(i)

