import math

steps = 2000
h = 1/steps
line_bound = 5
line_epsilon = 0
b_epsilon = 0.01
l_r_epsilon = 0.0000001
simpson_step = 2

def f1_1(x, y1, y2):
    return (2 * (x*y1 - y2) * (1 + y1*y1)) / ((x*x + y2*y2) * (x*x + y2*y2 + 1))

def f1_2(c):
    def f1(x, y1, y2):
        return (-2 * (y1*y1 + 1) * ((y2 - c[0] - x*y1) / ((x*x + (y2-c[0])*(y2-c[0]))**2) + ((y2 - c[1] - x*y1) / (x*x + (y2-c[1])*(y2-c[1]))**2))) \
            / (1 + 1/(x*x + (y2-c[0])*(y2-c[0])) + 1/(x*x + (y2-c[1])*(y2-c[1])))
    return f1

def radio_1(x, y1, y2):
    return math.sqrt(1 + y1*y1) * (1 + 1/(x*x + y2*y2))

def radio_2(c):
    def radio(x, y1, y2):
        return math.sqrt(1 + y1*y1) * (1 + 1/(x*x + (y2-c[0])*(y2-c[0])) + 1/(x*x + (y2-c[1])*(y2-c[1])))
    return radio

def rk4(y1, y2, f1):
    x_result = [-10]
    y_p_result = [y1]
    y_result = [y2]

    for x in [num / steps for num in range(-10*steps + 1, 10*steps)]:
        k11 = f1(x, y1, y2)
        k21 = f1(x + h / 2, y1 + k11*h / 2, y2 + k11*h / 2)
        k31 = f1(x + h / 2, y1 + k21*h / 2, y2 + k21*h / 2)
        k41 = f1(x + h, y1 + k31*h, y2 + k31*h)

        k12 = y1
        k22 = y1 + k12*h / 2
        k32 = y1 + k22*h / 2
        k42 = y1 + k32*h

        y1 = y1 + h * (k11 + 2*k21 + 2*k31 + k41) / 6
        y2 = y2 + h * (k12 + 2*k22 + 2*k32 + k42) / 6

        x_result.append(x)
        y_p_result.append(y1)
        y_result.append(y2)

    return x_result, y_p_result, y_result

def simpson(x_result, y_p_result, y_result, radio):
    sum = 0
    for i in range(0, len(x_result) - simpson_step*2, simpson_step*2):
        ra = radio(x_result[i], y_p_result[i], y_result[i])
        rh = radio(x_result[i + simpson_step], y_p_result[i + simpson_step], y_result[i + simpson_step])
        rb = radio(x_result[i + simpson_step*2], y_p_result[i + simpson_step*2], y_result[i + simpson_step*2])

        sum += ra + 4*rh + rb

    sum *= simpson_step*h / 3
    return sum

def radio_total(l, r, f1, radio):
    while (True):
        mid = (l+r) / 2
        x_result, y_p_result, y_result = rk4(mid, a, f1)

        if abs(y_result[-1]-b) < b_epsilon:
            return simpson(x_result, y_p_result, y_result, radio)

        if r-l < l_r_epsilon:
            return float('inf')

        if y_result[-1] < b:
            l = mid
        else:
            r = mid

t = int(input())

for x in range(1, t+1):
    n, a, b = [float(num) for num in input().split()]
    c = [float(num) for num in input().split()]

    if len(c) == 1:
        a -= c[0]
        b -= c[0]

        line = -a/10

        l = -line_bound + line
        r = -line_epsilon + line
        r_total_1 = radio_total(l, r, f1_1, radio_1)

        l = line + line_epsilon
        r = line + line_bound
        r_total_2 = radio_total(l, r, f1_1, radio_1)

        print(f'Case #{x}: {min(r_total_1, r_total_2)}')
    else:
        c.sort()
        line1 = (c[0]-a) / 10
        line2 = (c[1]-a) / 10

        f1 = f1_2(c)
        radio = radio_2(c)

        l = -line_bound + line1
        r = -line_epsilon + line1
        r_total_1 = radio_total(l, r, f1, radio)

        l = line1 + line_epsilon
        r = line2 - line_epsilon
        r_total_2 = radio_total(l, r, f1, radio)

        l = line2 + line_epsilon
        r = line2 + line_bound
        r_total_3 = radio_total(l, r, f1, radio)

        print(f'Case #{x}: {min(r_total_1, r_total_2, r_total_3)}')
