import sys

r, c, t = [int(x) for x in sys.stdin.readline().rstrip().split()]

room = []
air_cleaner = []

for i in range(r):
    row = [int(x) for x in sys.stdin.readline().rstrip().split()]
    for j in range(c):
        if row[j] == -1:
            air_cleaner.append(i)

    room.append(row)

air_cleaner_top = air_cleaner[0]
air_cleaner_bottom = air_cleaner[1]

for _ in range(t):
    before_room = [[c for c in r] for r in room]
    for i in range(r):
        for j in range(c):
            if before_room[i][j] > 0:
                diffusion_dust = before_room[i][j] // 5

                if i-1 >= 0 and before_room[i-1][j] != -1:
                    room[i-1][j] += diffusion_dust
                    room[i][j] -= diffusion_dust

                if i+1 < r and before_room[i+1][j] != -1:
                    room[i+1][j] += diffusion_dust
                    room[i][j] -= diffusion_dust

                if j-1 >= 0 and before_room[i][j-1] != -1:
                    room[i][j-1] += diffusion_dust
                    room[i][j] -= diffusion_dust

                if j+1 < c and before_room[i][j+1] != -1:
                    room[i][j+1] += diffusion_dust
                    room[i][j] -= diffusion_dust

    for i in reversed(range(air_cleaner_top-1)):
        room[i+1][0] = room[i][0]

    for i in range(1, c):
        room[0][i-1] = room[0][i]

    for i in range(1, air_cleaner_top+1):
        room[i-1][c-1] = room[i][c-1]

    for i in reversed(range(1, c-1)):
        room[air_cleaner_top][i+1] = room[air_cleaner_top][i]

    room[air_cleaner_top][1] = 0

    for i in range(air_cleaner_bottom+2, r):
        room[i-1][0] = room[i][0]

    for i in range(1, c):
        room[r-1][i-1] = room[r-1][i]

    for i in reversed(range(air_cleaner_bottom, r-1)):
        room[i+1][c-1] = room[i][c-1]

    for i in reversed(range(1, c-1)):
        room[air_cleaner_bottom][i+1] = room[air_cleaner_bottom][i]

    room[air_cleaner_bottom][1] = 0

print(sum([x for y in room for x in y]) + 2)
