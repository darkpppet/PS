n = int(input())

for i in range(0, n-1):
    print(' '*(n-i-1) + '*'*(i*2 + 1))

for i in range(0, n):
    print(' '*i + '*'*((n-i-1)*2 + 1))