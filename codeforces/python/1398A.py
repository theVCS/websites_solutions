def finder(lst, sum):
    for i in range(2, len(lst)):
        if lst[i] >= sum:
            return i
    return -1


t = int(input())
result = list()

for test_case in range(t):
    n = int(input())

    lst = input()
    lst = lst.split()
    lst = list(map(int, lst))

    one_res = finder(lst, lst[0] + lst[1])

    if one_res == -1:
        result.append("-1")
    else:
        result.append("1 2 " + str(one_res + 1))

for i in result:
    print(i)
