def ccw(px1, py1, px2, py2, px3, py3):
    return (px1*py2 + px2*py3 + px3*py1) - (px2*py1 + px3*py2 + px1*py3)

x1, y1, x2, y2, x3, y3, x4, y4 = [int(x) for x in input().split()]

ccw1 = ccw(x1, y1, x2, y2, x3, y3)
ccw2 = ccw(x1, y1, x2, y2, x4, y4)
ccw3 = ccw(x3, y3, x4, y4, x1, y1)
ccw4 = ccw(x3, y3, x4, y4, x2, y2)

if ccw1 == 0 and ccw2 == 0 and ccw3 == 0 and ccw4 == 0:
    print(0)
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
            print(0)
        else:
            print(1)
    else:
        print(0)
