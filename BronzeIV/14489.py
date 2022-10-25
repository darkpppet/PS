a, b = [int(x) for x in input().split()]
c = int(input())

total_money = a + b
two_chicken_cost = c * 2

if (total_money >= two_chicken_cost):
    print(total_money - two_chicken_cost)
else:
    print(total_money)
