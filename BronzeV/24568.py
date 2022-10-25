r = int(input())
s = int(input())

cupcakes_count = r*8 + s*3
cupcakes_left = cupcakes_count - 28

print(cupcakes_left if cupcakes_left > 0 else 0)
