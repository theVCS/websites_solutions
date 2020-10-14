t = int(input())
ques = list()

for test_case in range(t):
    ques.append(int(input()))

for num in ques:
    if (num // 2) % 2:
        print("NO")
    else:
        print("YES")
        sum_even = 0
        sum_odd = 0
        for i in range(2, num + 1, 2):
            print(i, end="\t")
            sum_even += i
        for i in range(1, num - 1, 2):
            print(i, end="\t")
            sum_odd += i
        print(sum_even - sum_odd)
