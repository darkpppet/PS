def recursion(s, l, r, count=0):
    if (l >= r):
        return (1, count+1)
    elif (s[l] != s[r]):
        return (0, count+1)
    else:
        return recursion(s, l+1, r-1, count+1)

def is_palindrome(s):
    return recursion(s, 0, len(s)-1)


t = int(input())

for i in range(0, t):
    line = input()
    returned_value, call_count = is_palindrome(line)
    print(f'{returned_value} {call_count}')
