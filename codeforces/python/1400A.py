t = int(input())
result = list()

for test_case in range(t):
    n = int(input())
    string = input()
    result.append(n * string[n - 1])

for i in result:
    print(i)
