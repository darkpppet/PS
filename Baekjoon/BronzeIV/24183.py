c4, a3, a4 = [float(x) for x in input().split()]

c4_cost = c4 * 0.229*0.324 * 2
a3_cost = a3 * 0.297*0.420 * 2
a4_cost = a4 * 0.210*0.297

total_cost = c4_cost + a3_cost + a4_cost

print(total_cost)
