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

t = int(sys.stdin.readline().rstrip())
result = []

for _ in range(t):
    xmin, ymin, xmax, ymax = [int(x) for x in sys.stdin.readline().rstrip().split()]
    x1, y1, x2, y2 = [int(x) for x in sys.stdin.readline().rstrip().split()]

    count = [0 for _ in range(4)]
    point = [None for _ in range(4)]
    count[0], point[0] = solve(x1, y1, x2, y2, xmin, ymin, xmin, ymax)
    count[1], point[1] = solve(x1, y1, x2, y2, xmin, ymin, xmax, ymin)
    count[2], point[2] = solve(x1, y1, x2, y2, xmin, ymax, xmax, ymax)
    count[3], point[3] = solve(x1, y1, x2, y2, xmax, ymin, xmax, ymax)

    point_count = sum(count)
    match point_count:
        case math.inf:
            result.append('4')
        case 0:
            result.append('0')
        case _:
            temp_points = []
            for i in range(4):
                if count[i] == 1:
                    temp_points.append(point[i])

            for i in range(len(temp_points)):
                for j in range(i+1, len(temp_points)):
                    if temp_points[i] == temp_points[j]:
                        point_count -= 1

            result.append(str(point_count))

sys.stdout.write('\n'.join(result))
