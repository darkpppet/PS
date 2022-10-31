n = int(input())

if n == 1:
    print('*')
    exit(0)

col_count = 4*(n-1) + 1
row_count = 4*(n-1) + 3

stars = [[' ' for _ in range(col_count)] for _ in range(row_count)]

for i in range(col_count):
    stars[0][i] = '*'

for i in range(row_count):
    stars[i][0] = '*'

index = (row_count - 1, 0)
star_length = col_count

while star_length >= 3:
    for i in range(star_length):
        stars[index[0]][index[1] + i] = '*'

    index = (index[0], index[1] + star_length - 1)

    for i in range(star_length):
        stars[index[0] - i][index[1]] = '*'

    index = (index[0] - star_length + 1, index[1])
    star_length -= 2

    for i in range(star_length):
        stars[index[0]][index[1] - i] = '*'

    index = (index[0], index[1] - star_length + 1)

    for i in range(star_length):
        stars[index[0] + i][index[1]] = '*'

    index = (index[0] + star_length - 1, index[1])
    star_length -= 2

for s in stars:
    print(''.join(s).rstrip())
