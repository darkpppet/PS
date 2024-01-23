n = int(input())

if n == 1:
    print('*')
    exit(0)

box_length = 4*(n-1) + 1

stars = [[' ' for _ in range(box_length)] for _ in range(box_length)]

now_length = box_length
index = 0

while now_length >= 1:
    for i in range(now_length):
        stars[index][index + i] = '*'
        stars[index + i][index] = '*'
        stars[index + now_length - 1][index + i] = '*'
        stars[index + i][index + now_length - 1] = '*'

    now_length -= 4
    index += 2

for s in stars:
    print(''.join(s))
