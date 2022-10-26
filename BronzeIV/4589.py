n = int(input())

print('Gnomes:')
for i in range(0, n):
    a, b, c = [int(x) for x in input().split()]

    if ((a > b and b > c) or (a < b and b < c)):
        print('Ordered')
    else:
        print('Unordered')
