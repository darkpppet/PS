t = int(input())

for i in range(0, t):
    n = int(input())
    for j in range(0, n):
        a, b = [int(x) for x in input().split()]
        print(f'{a+b} {a*b}')
