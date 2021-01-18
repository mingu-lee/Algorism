def solution(n):
    answer = []
    while n / 10 != 0:
        answer.append(n % 10)
        n = n // 10

    return answer

n= 12345
print(solution(n))