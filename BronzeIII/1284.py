while True:
    n = input()

    if n == '0':
        break

    total_length = len(n) + 1
    for c in n:
        match c:
            case '1':
                total_length += 2
            case '0':
                total_length += 4
            case other:
                total_length += 3

    print(total_length)
