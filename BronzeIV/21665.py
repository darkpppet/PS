n, m = [int(x) for x in input().split()]

pixel_rows = []
for i in range(0, n):
    row = input()
    pixel_rows.append(row)

input()
error_count = 0
for row in pixel_rows:
    new_row = input()

    for i in range(0, m):
        if row[i] == new_row[i]:
            error_count += 1

print(error_count)
