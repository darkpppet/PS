x = int(input())
n = int(input())

result = 0
for i in range(0, n):
    cost, count = [int(x) for x in input().split()]
    result += cost*count

if (x == result):
    print('Yes')
else:
    print('No')
    