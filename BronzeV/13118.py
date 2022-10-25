p = [int(x) for x in input().split()]
x, y, r = [int(x) for x in input().split()]

is_found = False
for i in range(0, 4):
    if (p[i] == x):
        is_found = True
        print(i + 1)
        break

if (is_found == False):
    print(0)
