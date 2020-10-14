t = int(input())
integers = list()
result = list()
one_solution = list()

for test_case in range(t):

    integers = input()
    integers = integers.split()
    integers = list(map(int, integers))

    if (integers[1] - integers[0])//integers[0]:
        one_solution = [integers[0], integers[1] - (integers[1] % integers[0])]
    else:
        one_solution = [-1, -1]

    result.append(one_solution)

for i, j in result:
    print(i, j)
