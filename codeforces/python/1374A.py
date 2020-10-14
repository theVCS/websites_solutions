t = int(input())
result = list()
integers = list()

for test_case in range(t):
    integers.clear()
    integers = input()
    integers = integers.split()
    integers = list(map(int, integers))
    dummy = (integers[2] - integers[1])//integers[0]
    result.append(dummy*integers[0] + integers[1])


for i in result:
    print(i)
