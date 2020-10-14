from functools import reduce

t = int(input())
result = list()

for test_case in range(t):
    n = int(input())

    lst = input()
    lst = lst.split()
    lst = list(map(int, lst))

    sum = reduce(lambda x, y: x + y, lst)
    min_val = min(lst)

    if (sum >= min_val*n) and sum <= (min_val*n + (n*(n - 1)/2)):
        result.append("YES")
    else:
        result.append("NO")

for i in result:
    print(i)
