def convert(char):
    if (char.isupper()):
        return char.lower()
    else:
        return char.upper()

line = input()

print(''.join([convert(x) for x in line]))
