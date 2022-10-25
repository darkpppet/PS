a, b = [int(x) for x in input().split()]

m = (b-a) / 400
p = 1 / (1 + 10**m)

print(p)