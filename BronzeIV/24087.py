import math

s = int(input())
a = int(input())
b = int(input())

need_b = math.ceil((s-a) / b)
total_cost = 250 + 100*(need_b if need_b > 0 else 0)

print(total_cost)
