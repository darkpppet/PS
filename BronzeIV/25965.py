n = int(input())

for _ in range(n):
    m = int(input())

    mission_list = []
    for _ in range(m):
        mission_list.append([int(x) for x in input().split()])

    k, d, a = [int(x) for x in input().split()]

    total_money = 0
    for mission in mission_list:
        mission_money = 0
        mission_money += k*mission[0]
        mission_money -= d*mission[1]
        mission_money += a*mission[2]

        if mission_money >= 0:
            total_money += mission_money

    print(total_money)
