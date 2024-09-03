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

            return 1
        else:
            return 0
    else:
        if ccw1 * ccw2 <= 0 and ccw3 * ccw4 <= 0:
            return 1
        else:
            return 0

t = int(sys.stdin.readline().rstrip())
result = []

for _ in range(t):
    x_start, y_start, x_end, y_end, x_left, y_top, x_right, y_bottom = [int(x) for x in sys.stdin.readline().rstrip().split()]

    xmin = min(x_left, x_right)
    xmax = max(x_left, x_right)
    ymin = min(y_bottom, y_top)
    ymax = max(y_bottom, y_top)

    if (xmin <= x_start <= xmax and ymin <= y_start <= ymax) or (xmin <= x_end <= xmax and ymin <= y_end <= ymax):
        result.append('T')
        continue

    count = [0 for _ in range(4)]
    count[0] = solve(x_start, y_start, x_end, y_end, xmin, ymin, xmin, ymax)
    count[1] = solve(x_start, y_start, x_end, y_end, xmin, ymin, xmax, ymin)
    count[2] = solve(x_start, y_start, x_end, y_end, xmin, ymax, xmax, ymax)
    count[3] = solve(x_start, y_start, x_end, y_end, xmax, ymin, xmax, ymax)

    point_count = sum(count)
    if point_count > 0:
        result.append('T')
    else:
        result.append('F')

sys.stdout.write('\n'.join(result))
