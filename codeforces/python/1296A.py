t = int(input())
result = list()

for test_case in range(t):
    n = int(input())

    lst = input()
    lst = lst.split()
    lst = list(map(int, lst))

    even = 0
    odd = 0

    for i in lst:
        if i % 2 == 0:
            even += 1
        else:
            odd += 1

    if odd == 0 or (even == 0 and odd % 2 == 0):
        result.append("NO")
    else:
        result.append("YES")

for i in result:
    print(i)