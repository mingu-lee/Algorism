def solution(prices):
    answer = []
    stack =0
    for i in range(len(prices)):
        for j in range(i+1,len(prices)):
            if prices[i] <= prices[j] :
                stack = stack + 1
            elif prices[i] > prices[j]:
                stack = stack + 1
                break
        answer.append(stack)
        stack =0    
    return answer

prices = [1,2,3,2,3]
print(solution(prices))