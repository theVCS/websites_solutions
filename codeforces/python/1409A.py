import math

t = int(input())
answer = list()

for test_case in range(t):
    a = input()
    a = a.split()
    b = int(a[1])
    a = int(a[0])
    answer.append(math.ceil(abs(a - b)/10))

for i in answer:
    print(i)