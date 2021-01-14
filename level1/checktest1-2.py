def solution(n):
    answer = 0
    while(1):
        answer = answer + n%10 
        if n//10==0:
            break 
        n = n//10 
    return answer

n = 987
print(solution(n))