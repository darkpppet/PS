paper = [[0 for _ in range(100)] for _ in range(100)]

n = int(input())

for t in range(n):
    x, y = [int(x) for x in input().split()]

    for i in range(10):
        for j in range(10):
            paper[x+i][y+j] = 1

black_area = [y for x in paper for y in x].count(1)

print(black_area)
