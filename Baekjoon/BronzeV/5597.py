students = [False] * 30

for i in range(0, 28):
    index = int(input())
    students[index - 1] = True

for i in range(0, 30):
    if (students[i] == False):
        print(i + 1)
