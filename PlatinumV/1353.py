import math

s, p = [int(x) for x in input().split()]

if s == p:
    print(1)
    exit(0)

if s*s - 4*p >= 0:
    print(2)
    exit(0)

max_n = s / math.e

max_n_small = math.floor(max_n)
max_n_small = max_n_small if max_n_small > 0 else 1
max_n_big = math.ceil(max_n)
if ((s/max_n_small) < p**(1/max_n_small)) and ((s/max_n_big) < p**(1/max_n_big)):
    print(-1)
    exit(0)

for i in range(3, max_n_big+1):
    if (s/i)**i >= p:
        print(i)
        exit(0)
