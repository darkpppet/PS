n = int(input())

match n:
    case 0 | 1:
        print(1)
    
    case 2:
        print(2)

    case 3:
        print(6)

    case 4:
        print(4)

    case other:
        print(0)
