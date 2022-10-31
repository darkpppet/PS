a_count, b_count = [int(x) for x in input().split()]

set_a = set([int(x) for x in input().split()])
set_b = set([int(x) for x in input().split()])

print(len(set_a^set_b))
