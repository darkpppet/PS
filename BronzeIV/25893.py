n = int(input())

for i in range(0, n):
    a, b, c = [int(x) for x in input().split()]

    stat_over_10_count = sum(1 for y in [a, b, c] if y >= 10)

    print(f'{a} {b} {c}')
    match stat_over_10_count:
        case 0:
            print('zilch')
        case 1:
            print('double')
        case 2:
            print('double-double')
        case 3:
            print('triple-double')
    print()
