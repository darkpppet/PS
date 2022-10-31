t = int(input())

for _ in range(t):
    m, n, x, y = [int(x) for x in input().split()]

    is_found = False
    for i in range(n + 1):
        k = m*i + x
        if k % n == y % n:
            print(k)
            is_found = True
            break

    if not is_found:
        print(-1)
