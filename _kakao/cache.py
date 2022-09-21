def solution(cacheSize, cities):
    #최근까지 사용안한건 교체 *5
    #같은 도시이름이 들어갈 경우 큐형식 *1
    #i.lower()사용
    #index오류가 나온다면 del 대신 pop을 사용
    que = []
    answer = 0

    if cacheSize == 0:
        answer = len(cities) * 5
        return answer

    for i in cities:
        si = i.lower()
        if si in que:
            que.remove(si)
            answer += 1
        else:
            if cacheSize <= len(que):
                que.pop(0)
            answer += 5
        que.append(si)
    return answer

c = 5
s = ["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"]

print(solution(c,s))