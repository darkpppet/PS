while True:
    x = float(input())
    y = x * 0.167

    if (x < 0):
        break

    print(f'Objects weighing {x:.2f} on Earth will weigh {y:.2f} on the moon.')
