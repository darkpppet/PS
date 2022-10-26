k = int(input())

for i in range(1, k+1):
    n, s, d = [int(x) for x in input().split()]

    total_ducats = 0
    for j in range(0, n):
        di, vi = [int(x) for x in input().split()]

        date_cost = di / s
        if (date_cost <= d):
            total_ducats += vi

    print(f'Data Set {i}:')
    print(total_ducats)
    print()
