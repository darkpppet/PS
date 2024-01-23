import statistics

a, b, c = [int(x) for x in input().split()]

bee_mean = statistics.mean([a, b, c])
total_distance = 0

if b > bee_mean:
    total_distance += (b-bee_mean) + (c-bee_mean)*2
else:
    total_distance += (bee_mean-b) + (bee_mean-a)*2

print(total_distance)
