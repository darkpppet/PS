m = int(input())

cups = ['1', '2', '3']

for i in range(0, m):
    x, y = input().split()

    index1 = cups.index(x)
    index2 = cups.index(y)

    cups[index1], cups[index2] = cups[index2], cups[index1]

print(cups[0])
