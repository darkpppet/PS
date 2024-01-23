t = int(input())

for i in range(0, t):
    a, b = input().split()

    if a == b:
        print('OK')
    else:
        print('ERROR')
