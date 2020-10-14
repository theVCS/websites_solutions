def max_sum(a, b, a_pos, b_pos, k, n):
    if n == 0:
        return 0
    elif a[a_pos - 1] < b[b_pos - 1] and k:
        return b[b_pos - 1] + max_sum(a, b, a_pos, b_pos - 1, k - 1, n - 1)
    else:
        return a[a_pos - 1] + max_sum(a, b, a_pos - 1, b_pos, k, n - 1)


t = int(input())
result = list()

for test_case in range(t):
    n = input()
    n = n.split()
    k = int(n[1])
    n = int(n[0])

    # getting a
    a = input()
    a = a.split()
    a = list(map(int, a))

    # getting b
    b = input()
    b = b.split()
    b = list(map(int, b))

    a.sort()
    b.sort()

    result.append(max_sum(a, b, n, n, k, n))

for i in result:
    print(i)