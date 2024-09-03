import math

x1, y1, r1, x2, y2, r2 = [float(x) for x in input().split()]

l = math.sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))

if l >= r1+r2:
    print('0.000')
elif l <= abs(r2-r1):
    r = min(r1, r2)
    print(round(math.pi * r * r, 3))
else:
    l1 = (l*l + r1*r1 - r2*r2) / (2*l)
    l2 = l - l1
    h = math.sqrt(r1*r1 - l1*l1)

    sin_theta1 = h/r1
    cos_theta1 = l1/r1
    theta1 = math.acos(cos_theta1)
    sin_theta2 = h/r2
    cos_theta2 = l2/r2
    theta2 = math.acos(cos_theta2)

    print(round(r1*r1*(theta1 - sin_theta1*cos_theta1) + r2*r2*(theta2 - sin_theta2*cos_theta2), 3))
