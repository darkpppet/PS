n = int(input())

if n == 1:
    print('*')
    exit(0)

print(' '*(n-1) + '*')

for i in range(n-2):
    print(f"{' '*(n-2-i)}*{' '*(i*2 + 1)}*")

print('*'*(n*2 - 1))
