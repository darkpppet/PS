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

            x_min = max(min(x1, x2), min(x3, x4))
            x_max = min(max(x1, x2), max(x3, x4))
            y_min = max(min(y1, y2), min(y3, y4))
            y_max = min(max(y1, y2), max(y3, y4))

            if x_min == x_max and y_min == y_max:
                return 1, (x_min, y_min)
            else:
                return math.inf, (math.inf, math.inf)
        else:
            return 0, (math.inf, math.inf)
    else:
        if ccw1 * ccw2 <= 0 and ccw3 * ccw4 <= 0:
            if x1 == x2:
                x = x1
                y = (y4-y3) * (x1-x3) / (x4-x3) + y3
            elif x3 == x4:
                x = x3
                y = (y2-y1) * (x3-x1) / (x2-x1) + y1
            else:
                x = ((x2-x1) * (x4-x3) * (y3-y1) + x1 * (x4-x3) * (y2-y1) - x3 * (x2-x1) * (y4-y3)) / ((x4-x3) * (y2-y1) - (x2-x1) * (y4-y3))
                y = (y2-y1) * (x-x1) / (x2-x1) + y1

            return 1, (x, y)
        else:
            return 0, (math.inf, math.inf)

n = int(input())

lines = []
for _ in range(n):
    x1, y1, x2, y2 = [int(x) for x in input().split()]
    count = [0 for _ in range(4)]
    point = [None for _ in range(4)]
    count[0], point[0] = solve(x1, y1, x2, y2, -10, -10, -10, 10)
    count[1], point[1] = solve(x1, y1, x2, y2, -10, -10, 10, -10)
    count[2], point[2] = solve(x1, y1, x2, y2, -10, 10, 10, 10)
    count[3], point[3] = solve(x1, y1, x2, y2, 10, -10, 10, 10)

    count_sum = sum(count)
    if 0 < count_sum < math.inf:
        combs = itertools.combinations(range(4), 2)
        for comb in combs:
            i = comb[0]
            j = comb[1]
            if count[i] == 1 and count[j] == 1 and point[i] == point[j]:
                count_sum -= 1

        if count_sum > 1:
            lines.append((x1, y1, x2, y2))

combs = itertools.combinations(range(len(lines)), 2)
result = len(lines) + 1
for comb in combs:
    i = comb[0]
    j = comb[1]
    x1 = lines[i][0]
    y1 = lines[i][1]
    x2 = lines[i][2]
    y2 = lines[i][3]
    x3 = lines[j][0]
    y3 = lines[j][1]
    x4 = lines[j][2]
    y4 = lines[j][3]

    count, point = solve(x1, y1, x2, y2, x3, y3, x4, y4)

    if count == 1 and -10 < point[0] < 10 and -10 < point[1] < 10:
        result += 1

print(result)
