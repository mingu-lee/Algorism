def solution(citations):
    s = sorted(citations, reverse=True)
    for i in range(len(s)):
        if s[i] <= i:
            return i
    return len(s)
citations = [20,19,18,3]
print(solution(citations))
