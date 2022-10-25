n = int(input())

for i in range(0, n):
    line = input()
    length = len(line)

    if (length >= 6 and length <= 9):
        print('yes')
    else:
        print('no')
