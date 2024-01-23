z = int(input())

for i in range(0, z):
    w, k = [int(x) for x in input().split()]

    num1 = (w * (k//2)) + ((k%2) * (w//2))
    num2 = ((w//2) * k) + ((w%2) * (k//2))

    print(max(num1, num2))
