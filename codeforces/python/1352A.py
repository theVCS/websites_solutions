def make_list(number):
    while number:
        lst.append(number % 10)
        number = number//10


def is_no_zero(a):
    if a != 0:
        return True
    else:
        return False


def printer(lst):
    k = 0
    for i in lst:
        if i:
            print((10 ** k) * i, end="\t")
        k += 1


t = int(input())
ques = list()

for test_case in range(t):
    ques.append(int(input()))

for test_case in ques:
    lst = list()
    filtered_lst = list()
    make_list(test_case)
    filtered_lst = list(filter(is_no_zero, lst))
    print(len(filtered_lst))
    printer(lst)
    print("\n")

