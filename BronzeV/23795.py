total_money = 0

while True:
    money = int(input())

    if (money == -1):
        break

    total_money += money

print(total_money)
