s = input()
len_s = len(s)
substring_set = set()

for i in range(len_s):
    for j in range(len_s - i + 1):
        substring = s[j:j+i]
        substring_set.add(substring)

print(len(substring_set))
