def merge_sort(list, left, right, k, save_count=[0]):
    if (left < right):
        middle = (left+right) // 2
        merge_sort(list, left, middle, k, save_count)
        merge_sort(list, middle+1, right, k, save_count)
        merge(list, left, middle, right, k, save_count)

def merge(list, left, middle, right, k, save_count):
    i = left
    j = middle + 1
    t = 0

    tmp = [0] * (right - left + 1)

    while (i <= middle and j <= right):
        if (list[i] <= list[j]):
            tmp[t] = list[i]
            t += 1
            i += 1
        else:
            tmp[t] = list[j]
            t += 1
            j += 1
    
    while (i <= middle):
        tmp[t] = list[i]
        t += 1
        i += 1

    while (j <= right):
        tmp[t] = list[j]
        t += 1
        j += 1

    i = left
    t = 0

    while (i <= right):
        save_count[0] += 1
        if (save_count[0] == k):
            print(tmp[t])
            exit()
        list[i] = tmp[t]
        i += 1
        t += 1

n, k  = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]

merge_sort(a, 0, len(a) - 1, k)

print(-1)
