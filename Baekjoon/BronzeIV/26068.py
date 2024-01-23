n = int(input())

using_count = 0
for _ in range(n):
    d_day = int(input().replace('D-', ''))
    if d_day <= 90:
        using_count += 1

print(using_count)
