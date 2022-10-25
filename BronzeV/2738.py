a, b = [int(x) for x in input().split()]

result = []

for i in range(0, a):
    line = [int(x) for x in input().split()]
    result.append(line)

for i in range(0, a):
    line = [int(x) for x in input().split()]
    result[i] = [x + y for x, y in zip(result[i], line)]

for i in range(0, a):
    print(' '.join([str(x) for x in result[i]]))
