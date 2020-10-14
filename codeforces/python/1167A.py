t = int(input())
result = []

for test_case in range(t):
    n = int(input())
    string = input()

    if n < 11:
        result.append("NO")
    else:
        if "8" in string[:n - 10]:
            result.append("YES")
        else:
            result.append("NO")

for i in result:
    print(i)
