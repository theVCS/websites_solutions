t = int(input())
candies = list()
oranges = list()
result = list()

for test_case in range(t):
    n = int(input())
    candies.clear()
    oranges.clear()
    no_of_steps = 0

    candies = input()
    candies = candies.split()
    candies = list(map(int, candies))

    oranges = input()
    oranges = oranges.split()
    oranges = list(map(int, oranges))

    # greedy algorithm
    min_candies = min(candies)
    min_oranges = min(oranges)

    for gift in range(n):
        if candies[gift] > min_candies and oranges[gift] > min_oranges:
            if candies[gift] - min_candies < oranges[gift] - min_oranges:
                no_of_steps += oranges[gift] - min_oranges
            else:
                no_of_steps += candies[gift] - min_candies

        elif candies[gift] > min_candies:
            no_of_steps += candies[gift] - min_candies

        else:
            no_of_steps += oranges[gift] - min_oranges

    result.append(no_of_steps)

for res in result:
    print(res)
