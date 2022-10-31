import sys

n = int(sys.stdin.readline().strip())

plug_count = 1
for i in range(0, n):
    plug = int(sys.stdin.readline().strip())
    plug_count += plug - 1

print(plug_count)
