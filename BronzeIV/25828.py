g, p, t = [int(x) for x in input().split()]

group_need_kit = g + p*t
individual_need_kit = g*p

if individual_need_kit < group_need_kit:
    print(1)
elif individual_need_kit > group_need_kit:
    print(2)
else:
    print(0)
