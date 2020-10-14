t = int(input())
result = list()

for test_case in range(t):
    lst = list()
    lst = input()
    lst = lst.split()
    lst = list(map(int, lst))
    result.append(lst[0] + lst[1])

for i in result:
    print(i)