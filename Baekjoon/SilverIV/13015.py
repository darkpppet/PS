n = int(input())

print('*'*n + ' '*(n*2 - 3) + '*'*n)

for i in range(1, n-1):
    print(f"{' '*i}*{' '*(n-2)}*{' '*((n-i-1)*2 - 1)}*{' '*(n-2)}*")

print(f"{' '*(n-1)}*{' '*(n-2)}*{' '*(n-2)}*")

for i in reversed(range(1, n-1)):
    print(f"{' '*i}*{' '*(n-2)}*{' '*((n-i-1)*2 - 1)}*{' '*(n-2)}*")

print('*'*n + ' '*(n*2 - 3) + '*'*n)
