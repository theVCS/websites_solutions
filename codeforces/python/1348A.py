t = int(input())
result = list()

for test_case in range(t):
    sum = 2
    value = int(input())

    for power in range(1, value//2):
        sum += 2 * (2**power)

    result.append(sum)


for i in result:
    print(i)