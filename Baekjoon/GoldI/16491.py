import math, itertools

def ccw(px1, py1, px2, py2, px3, py3):
    return (px1*py2 + px2*py3 + px3*py1) - (px2*py1 + px3*py2 + px1*py3)

def solve(x1, y1, x2, y2, x3, y3, x4, y4):
    ccw1 = ccw(x1, y1, x2, y2, x3, y3)
    ccw2 = ccw(x1, y1, x2, y2, x4, y4)
    ccw3 = ccw(x3, y3, x4, y4, x1, y1)
    ccw4 = ccw(x3, y3, x4, y4, x2, y2)

    if ccw1 == 0 and ccw2 == 0 and ccw3 == 0 and ccw4 == 0:
        if (min(x1, x2) <= max(x3, x4) and min(x3, x4) <= max(x1, x2) and
                min(y1, y2) <= max(y3, y4) and min(y3, y4) <= max(y1, y2)):

            return 1
        else:
            return 0
    else:
        if ccw1 * ccw2 <= 0 and ccw3 * ccw4 <= 0:
            return 1
        else:
            return 0

n = int(input())

robot = []
for _ in range(n):
    robot.append([int(x) for x in input().split()])

shelter = []
for _ in range(n):
    shelter.append([int(x) for x in input().split()])

perms = itertools.permutations(range(n), n)

for perm in perms:
    combs = itertools.combinations(range(n), 2)

    is_found = True
    for comb in combs:
        i = comb[0]
        j = comb[1]
        x1 = robot[i][0]
        y1 = robot[i][1]
        x2 = shelter[perm[i]][0]
        y2 = shelter[perm[i]][1]
        x3 = robot[j][0]
        y3 = robot[j][1]
        x4 = shelter[perm[j]][0]
        y4 = shelter[perm[j]][1]

        if solve(x1, y1, x2, y2, x3, y3, x4, y4) == 1:
            is_found = False
            break

    if is_found:
        for p in perm:
            print(p+1)
        exit(0)
