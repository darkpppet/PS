defense, ignore = [int(x) for x in input().split()]

if (defense * (100-ignore) / 100 >= 100):
    print(0)
else:
    print(1)
    