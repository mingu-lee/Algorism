def solution(arr):
    arrMin = min(arr)
    arr.remove(arrMin)
    if not arr:
        arr.insert(0,-1)
    return arr

arr = [10,9,6,5,4,21]
print(solution(arr))