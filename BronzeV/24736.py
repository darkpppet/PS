def sum_score(box_scores):
    result = 0
    result += box_scores[0] * 6
    result += box_scores[1] * 3
    result += box_scores[2] * 2
    result += box_scores[3] * 1
    result += box_scores[4] * 2
    return result

visiting_team_box_scores = [int(x) for x in input().split()]
home_team_box_scores = [int(x) for x in input().split()]

visiting_team_score_sum = sum_score(visiting_team_box_scores)
home_team_score_sum = sum_score(home_team_box_scores)

print(f'{visiting_team_score_sum} {home_team_score_sum}')
