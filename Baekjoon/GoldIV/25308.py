import itertools, math

def ccw(px1, py1, px2, py2, px3, py3):
    return (px1*py2 + px2*py3 + px3*py1) - (px2*py1 + px3*py2 + px1*py3)

pi_divided_4 = math.pi / 4

cos_arr = [math.cos(0), math.cos(pi_divided_4), math.cos(pi_divided_4*2), math.cos(pi_divided_4*3), math.cos(pi_divided_4*4), math.cos(pi_divided_4*5), math.cos(pi_divided_4*6), math.cos(pi_divided_4*7)]
sin_arr = [math.sin(0), math.sin(pi_divided_4), math.sin(pi_divided_4*2), math.sin(pi_divided_4*3), math.sin(pi_divided_4*4), math.sin(pi_divided_4*5), math.sin(pi_divided_4*6), math.sin(pi_divided_4*7)]

a = [int(x) for x in input().split()]

p = itertools.permutations(a, 8)

count = 0
for e in p:
    is_convex = True
    for i in range(8):
        x1 = e[i] * cos_arr[i]
        y1 = e[i] * sin_arr[i]
        x2 = e[(i+1) % 8] * cos_arr[(i+1) % 8]
        y2 = e[(i+1) % 8] * sin_arr[(i+1) % 8]
        x3 = e[(i+2) % 8] * cos_arr[(i+2) % 8]
        y3 = e[(i+2) % 8] * sin_arr[(i+2) % 8]

        ccw_result = ccw(x1, y1, x2, y2, x3, y3)

        if ccw_result < 0:
            is_convex = False
            break

    if is_convex:
        count += 1

print(count)
