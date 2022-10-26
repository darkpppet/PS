a, b, c = [int(x) for x in input().split()]

if a == b and b == c:
    print('*')
else:
    if a == b:
        print('C')
    elif b == c:
        print('A')
    else:
        print('B')
