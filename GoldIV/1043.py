n, m = [int(x) for x in input().split()]
knower_count, *knower_list = [int(x) for x in input().split()]

people_know_graph = [[0 for _ in range(n+1)] for _ in range(n+1)]
party_list = []

for i in range(m):
    party_people_count, *party_people_list = [int(x) for x in input().split()]
    party_list.append(party_people_list)

    for j in range(party_people_count-1):
        for k in range(j+1, party_people_count):
            party_people_1 = party_people_list[j]
            party_people_2 = party_people_list[k]
            people_know_graph[party_people_1][party_people_2] = 1
            people_know_graph[party_people_2][party_people_1] = 1

final_knower = set([x for x in knower_list])

def dfs(index, history):
    for l in range(1, n + 1):
        if (not l in history) and (people_know_graph[index][l] == 1):
            final_knower.add(l)
            history.add(l)
            dfs(l, history)

for people in knower_list:
    dfs(people, set())

lie_party_count = 0
for party in party_list:
    is_knower_in_party = False
    for people in party:
        if people in final_knower:
            is_knower_in_party = True
            break

    if not is_knower_in_party:
        lie_party_count += 1

print(lie_party_count)
