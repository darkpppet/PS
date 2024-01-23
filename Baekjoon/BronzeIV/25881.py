cost1, cost2 = [int(x) for x in input().split()]
n = int(input())

for i in range(0, n):
    energy_consumption = int(input())

    print(energy_consumption, end=' ')

    if energy_consumption <= 1000:
        print(energy_consumption * cost1)
    else:
        print((energy_consumption-1000)*cost2 + 1000*cost1)
