def solution(arr):
    arr.sort(reverse=True)
    arr.remove(arr[-1])
    if not arr:
        arr.insert(0,-1)
    return arr

arr = [10,9,6,5,4,21]
print(solution(arr))