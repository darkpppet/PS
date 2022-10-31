import sys

for t in range(0, 3):
    n = int(sys.stdin.readline().strip())
    integer_sum = 0
    for i in range(0, n):
        integer_sum += int(sys.stdin.readline().strip())

    if integer_sum > 0:
        print('+')
    elif integer_sum < 0:
        print('-')
    else:
        print('0')
