import math

def main():
    x, y = [int(i) for i in input().split()]
    print(x + y - math.gcd(x, y))

if __name__ == '__main__':
    main()
