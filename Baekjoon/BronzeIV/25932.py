n = int(input())

for _ in range(n):
    players = input().split()
    players_set = set(players)

    print(' '.join(players))
    if '17' in players_set and '18' in players_set:
        print('both')
    elif '17' in players_set:
        print('zack')
    elif '18' in players_set:
        print('mack')
    else:
        print('none')
    print()
