from math import *

n = int(input())
p = int(input())

cost_list = [p]

if (n >= 5):
    cost_list.append(p - 500)

if (n >= 10):
    cost_list.append(p * 90 // 100)

if (n >= 15):
    cost_list.append(p - 2000)

if (n >= 20):
    cost_list.append(p * 75 // 100)

min_cost = min(cost_list)

print(min_cost if min_cost > 0 else 0)
