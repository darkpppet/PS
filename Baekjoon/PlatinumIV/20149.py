import sys

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
                return '1'
            else:
                return '3'
        else:
            return '0'
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

            if (x == x1 and y == y1) or (x == x2 and y == y2) or (x == x3 and y == y3) or (x == x4 and y == y4):
                return '1'
            else:
                return '2'
        else:
            return '0'

n = int(sys.stdin.readline().rstrip())

lines = []
for _ in range(n):
    line = [int(x) for x in sys.stdin.readline().rstrip().split()]
    lines.append(line)

result = [[None for _ in range(n)] for _ in range(n)]
for i in range(n):
    result[i][i] = '3'
    for j in range(i+1, n):
        temp = solve(lines[i][0], lines[i][1], lines[i][2], lines[i][3], lines[j][0], lines[j][1], lines[j][2], lines[j][3])
        result[i][j] = temp
        result[j][i] = temp

sys.stdout.write('\n'.join([''.join(x) for x in result]))
