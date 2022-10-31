n = int(input())

if n == 1:
    print('*')
    exit(0)

for i in range(n):
    print('* '*((n+1) // 2))
    print(' *'*(n // 2))
