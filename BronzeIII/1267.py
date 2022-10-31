n = int(input())
times = [int(x) for x in input().split()]

y_cost = sum([(x//30 + 1) * 10 for x in times])
m_cost = sum([(x//60 + 1) * 15 for x in times])

if y_cost < m_cost:
    print(f'Y {y_cost}')
elif m_cost < y_cost:
    print(f'M {m_cost}')
else:
    print(f'Y M {y_cost}')
