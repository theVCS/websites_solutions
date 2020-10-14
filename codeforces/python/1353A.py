def max_calculator(no_of_value, sum):
    if no_of_value == 1:
        return 0
    elif no_of_value == 2:
        return sum
    else:
        return 2 * sum


t = int(input())
lst = list()

for test_case in range(t):
    lst.append(input())

for values in lst:
    values = values.split()
    values = list(map(int, values))
    print(max_calculator(values[0], values[1]))