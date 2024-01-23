n = int(input())

print(' '*(n-1) + '*')

for i in range(n-1):
    print(f"{' '*(n-2-i)}*{' '*(i*2 + 1)}*")
