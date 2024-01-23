t = int(input())

for i in range(0, t):
    move_log = input()

    walk_count = 0
    for c in move_log:
        match c:
            case 'U':
                walk_count += 1
            case 'D':
                break

    print(walk_count)
