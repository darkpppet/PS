while True:
    a, *rest = [int(x) for x in input().split()]

    if a == 0:
        break

    branch_count = 1
    for i in range(0, len(rest)//2):
        splitting_factor = rest[i*2]
        cut_count = rest[i*2 + 1]

        branch_count *= splitting_factor
        branch_count -= cut_count

    print(branch_count)
