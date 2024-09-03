def ccw(px1, py1, px2, py2, px3, py3):
    return (px1*py2 + px2*py3 + px3*py1) - (px2*py1 + px3*py2 + px1*py3)

x1, y1, x2, y2 = [int(x) for x in input().split()]
x3, y3, x4, y4 = [int(x) for x in input().split()]

ccw1 = ccw(x1, y1, x2, y2, x3, y3)
ccw2 = ccw(x1, y1, x2, y2, x4, y4)
ccw3 = ccw(x3, y3, x4, y4, x1, y1)
ccw4 = ccw(x3, y3, x4, y4, x2, y2)

if ccw1 * ccw2 == 0 and ccw3 * ccw4 == 0:
    if (min(x1, x2) <= max(x3, x4) and min(x3, x4) <= max(x1, x2) and
            min(y1, y2) <= max(y3, y4) and min(y3, y4) <= max(y1, y2)):
        print(1)
    else:
        print(0)
else:
    if ccw1 * ccw2 <= 0 and ccw3 * ccw4 <= 0:
        print(1)
    else:
        print(0)
