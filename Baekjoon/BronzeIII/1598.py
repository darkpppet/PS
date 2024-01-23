num1, num2 = [int(x) for x in input().split()]

num1_d = num1 // 4
num1_r = num1 % 4 - 1
num1_d -= 1 if num1_r < 0 else 0
num1_r += 4 if num1_r < 0 else 0

num2_d = num2 // 4
num2_r = num2 % 4 - 1
num2_d -= 1 if num2_r < 0 else 0
num2_r += 4 if num2_r < 0 else 0

distance = abs(num2_d - num1_d) + abs(num2_r - num1_r)
print(distance)
