n = int(input())

for i in range(0, n-1):
    print(' '*i + '*'*((n-i)*2 - 1))

for i in reversed(range(0, n)):
    print(' '*i + '*'*((n-i)*2 - 1))
