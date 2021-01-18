def solution(arr):
    mini = min(arr)
    for i in arr:
        if i == mini:
            arr.remove(i)
            if arr == []:
                arr.append(-1)
    return arr

arr = [10]
print(solution(arr))