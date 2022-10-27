vk, jk = [int(x) for x in input().split()]
vl, jl = [int(x) for x in input().split()]
vh, dh, jh = [int(x) for x in input().split()]

result = (vh*dh*jh) * (vk*jk + vl*jl)
print(result)
