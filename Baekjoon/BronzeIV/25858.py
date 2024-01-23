n, d = [int(x) for x in input().split()]

problem_count_list = []
for i in range(0, n):
    problem_count = int(input())
    problem_count_list.append(problem_count)

total_problem_count = sum(problem_count_list)

for problem_count in problem_count_list:
    print((d//total_problem_count) * problem_count)
