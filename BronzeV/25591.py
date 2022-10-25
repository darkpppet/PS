num1, num2 = [int(x) for x in input().split()]

a = 100 - num1
b = 100 - num2
c = 100 - (a+b)
d = a * b
q = d // 100
r = d % 100

print(f'{a} {b} {c} {d} {q} {r}')
print(f'{c+q} {r}')
