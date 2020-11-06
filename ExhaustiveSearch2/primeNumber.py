from itertools import permutations
def solution(numbers):
    answer = 0
    s=[];r=[];e=[]
    numbers = str(''.join(numbers))
    for i in range(1,len(numbers)+1):
        s.append(list(map(''.join,permutations(numbers,i))))

    s = sum(s, [])
    s = list(map(int,s))
    s = list(set(s))
    answer = len(s)
    for i in list(set(s)):
        if i < 2:
            answer-=1
        for j in range(2, int(i**0.5)+1):
            if i%j==0:
                answer-=1
                break
    
    return answer
numbers = {"17"}
print(solution(numbers))