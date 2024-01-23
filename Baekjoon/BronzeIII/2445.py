n = int(input())

for i in range(0, n-1):
    print('*'*(i+1) + ' '*((n-i-1)*2) + '*'*(i+1))

for i in range(0, n):
    print('*'*(n-i) + ' '*(i*2) + '*'*(n-i))
