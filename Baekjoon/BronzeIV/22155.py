n = int(input())

for k in range(0, n):
    i, f = [int(x) for x in input().split()]

    if (i <= 1 and f <= 2) or (i <= 2 and f <= 1):
        print('Yes')
    else:
        print('No')
