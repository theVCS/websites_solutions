def count(a, b, n):
    if a > n or b > n:
        return 0
    elif a > b:
        return 1 + count(a, b + a, n)
    else:
        return 1 + count(a + b, b, n)


t = int(input())
values = list()
result = list()

for test_case in range(t):
    values = input()
    values = values.split()
    values = list(map(int, values))
    result.append(count(values[0], values[1], values[2]))


for i in result:
    print(i)