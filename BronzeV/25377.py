from math import *

n = int(input())

min_time = inf

for i in range(0, n):
    a, b = [int(x) for x in input().split()]

    if (a <= b):
        min_time = min(min_time, b)
        
print(min_time if min_time != inf else -1)
