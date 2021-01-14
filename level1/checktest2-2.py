def solution(N, stages):
    answer = {}
    l = len(stages)
    for i in range(1, N+1):
        if l != 0:
            count = stages.count(i)
            answer[i] = count / l
            l -= count
        else:
            answer[i] = 0
    return sorted(answer, key=lambda x: answer[x], reverse=True)

N = 4
stages = [4,4,4,4,4]
print(solution(N, stages))