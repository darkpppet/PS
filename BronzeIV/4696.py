while True:
    n = float(input())

    match n:
        case 0:
            break
        
        case 1:
            print('5.00')
        
        case other:
            print (f'{(n**5 - 1) / (n-1):.2f}')
