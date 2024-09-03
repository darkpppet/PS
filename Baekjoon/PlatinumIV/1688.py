import sys, math

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
                return 0, (-1, -1)
        else:
            return 0, (-1, -1)
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
            return 0, (-1, -1)

n = int(sys.stdin.readline().rstrip())

lines = []
for _ in range(n):
    lines.append([int(x) for x in sys.stdin.readline().rstrip().split()])

protectees = []
before = []
count = []
result = []
for _ in range(3):
    px, py = [int(x) for x in sys.stdin.readline().rstrip().split()]
    protectees.append((px, py))

    x1 = lines[-1][0]
    y1 = lines[-1][1]
    x2 = lines[0][0]
    y2 = lines[0][1]

    ccw_result = ccw(x1, y1, x2, y2, px, py)
    if ccw_result == 0 and min(x1, x2) <= px <= max(x1, x2) and min(y1, y2) <= py <= max(y1, y2):
        result.append(1)
    else:
        result.append(0)

    temp_count, temp_point = solve(x1, y1, x2, y2, px, py, -1, -1)
    count.append(temp_count)
    before.append(temp_point)

for i in range(len(lines) - 1):
    j = i+1
    x1 = lines[i][0]
    y1 = lines[i][1]
    x2 = lines[j][0]
    y2 = lines[j][1]

    for p in range(3):
        px = protectees[p][0]
        py = protectees[p][1]

        ccw_result = ccw(x1, y1, x2, y2, px, py)
        if ccw_result == 0 and min(x1, x2) <= px <= max(x1, x2) and min(y1, y2) <= py <= max(y1, y2):
            result[p] = 1

        temp_count, temp_point = solve(x1, y1, x2, y2, px, py, -1, -1)

        if temp_count == 1 and before[p] != temp_point:
            count[p] += 1

        before[p] = temp_point

for p in range(3):
    result[p] |= 0 if count[p]%2 == 0 else 1

sys.stdout.write('\n'.join([str(x) for x in result]))

