while True:
    line = input()

    if (line == '# 0 0'):
        break

    data = line.split()

    name = data[0]
    age = int(data[1])
    weight = int(data[2])

    if (age > 17 or weight >= 80):
        print(f'{name} Senior')
    else:
        print(f'{name} Junior')
