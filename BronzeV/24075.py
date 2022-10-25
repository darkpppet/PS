from math import *

a, b = [int(x) for x in input().split()]

plus = a + b
minus = a - b

print(max(plus, minus))
print(min(plus, minus))
