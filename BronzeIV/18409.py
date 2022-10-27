n = int(input())
s = input()

vowel_count = 0
for c in s:
    if c == 'a' or c == 'e' or c == 'i' or c == 'o' or c =='u':
        vowel_count += 1

print(vowel_count)
