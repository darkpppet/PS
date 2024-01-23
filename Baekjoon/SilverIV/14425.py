n, m = [int(x) for x in input().split()]

dictionary = set()
for i in range(n):
    dictionary.add(input())

word_count = 0
for i in range(m):
    if input() in dictionary:
        word_count += 1

print(word_count)
