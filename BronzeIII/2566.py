max_num = 0
index = (1, 1)

for i in range(9):
    row = [int(x) for x in input().split()]

    for j in range(9):
        if row[j] > max_num:
            max_num = row[j]
            index = (i+1, j+1)

print(max_num)
print(f'{index[0]} {index[1]}')
