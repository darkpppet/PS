from math import *

n = int(input())

max_point = -inf

for i in range(0, n):
    a, d, g = [int(x) for x in input().split()]

    point = a * (d+g)
    point *= 2 if a == d + g else 1

    max_point = max(max_point, point)

print(max_point)
