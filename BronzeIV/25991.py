n = int(input())
c_list = [float(x) for x in input().split()]

volume_sum = sum(c*c*c for c in c_list)

print(volume_sum ** (1/3))
