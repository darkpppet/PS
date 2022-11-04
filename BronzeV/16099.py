t = int(input())

for _ in range(t):
    lt, wt, le, we = [int(x) for x in input().split()]

    if lt*wt > le*we:
        print('TelecomParisTech')
    elif lt*wt < le*we:
        print('Eurecom')
    else:
        print('Tie')
