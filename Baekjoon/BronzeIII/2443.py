n = int(input())

for i in range(0, n):
    print(' '*i + '*'*((n-i-1)*2 + 1))
