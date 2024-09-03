def ccw(px1, py1, px2, py2, px3, py3):
    return (px1*py2 + px2*py3 + px3*py1) - (px2*py1 + px3*py2 + px1*py3)

x1, y1 = [int(x) for x in input().split()]
x2, y2 = [int(x) for x in input().split()]
x3, y3 = [int(x) for x in input().split()]

ccw_result = ccw(x1, y1, x2, y2, x3, y3)

if ccw_result == 0:
    print(0)
else:
    print(int(ccw_result / abs(ccw_result)))
    