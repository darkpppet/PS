import sys

t = int(input())

for i in range(0, t):
    n = int(sys.stdin.readline().replace('\n', ''))
    print(n*n)
