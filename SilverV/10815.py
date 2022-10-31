n = int(input())
cards = set([int(x) for x in input().split()])

m = int(input())
nums = [int(x) for x in input().split()]

for num in nums:
    if num in cards:
        print(1)
    else:
        print(0)
