t = int(input())

for i in range(0, t):
    a, b, c = [int(x) for x in input().split()]

    count = 0

    for j in range(1, a+1):
        for k in range(1, b+1):
            for l in range(1, c+1):
                if (j % k == k % l and k % l == l % j):
                    count += 1
    
    print(count)
