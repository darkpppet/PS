n = int(input())

for i in range(0, n):
    id_number, score1, score2, score3 = [int(x) for x in input().split()]

    total_score = score1 + score2 + score3

    is_pass_l1 = score1 >= 35*0.3
    is_pass_l2 = score2 >= 25*0.3
    is_pass_l3 = score3 >= 40*0.3
    is_pass_test = (total_score >= 55) and is_pass_l1 and is_pass_l2 and is_pass_l3

    print(f"{id_number} {total_score} {'PASS' if is_pass_test else 'FAIL'}")
