n, k = [int(x) for x in input().split()]
x = [int(x) for x in input().split()]

x.sort(reverse=True)
print(x[k-1])
