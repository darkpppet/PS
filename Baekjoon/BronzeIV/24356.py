t1, m1, t2, m2 = [int(x) for x in input().split()]

total_m = (t2-t1)*60 + (m2-m1)
total_m += 24*60 if total_m < 0 else 0
total_laps = total_m // 30

print(f'{total_m} {total_laps}')
