alpabet_count = [0] * 26

word = input()

for c in word:
    alpabet_count[ord(c) - 97] += 1

print(' '.join([str(x) for x in alpabet_count]))
