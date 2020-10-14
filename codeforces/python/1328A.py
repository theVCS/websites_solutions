t = int(input())
result = list()

for test_case in range(t):
    a = input()
    a = a.split()
    a = list(map(int, a))
    b = a[1]
    a = a[0]
    if a % b:
        result.append(b - a % b)
    else:
        result.append(0)

for i in result:
    print(i)
