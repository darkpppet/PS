from math import *

n = int(input())
a, b = [int(x) for x in input().split()]

max_chicken_by_drink = (a//2) + b

print(min(n, max_chicken_by_drink))
