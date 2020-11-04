def solution(answers):
    sum1 = 0; sum2 = 0; sum3 = 0
    s1 = [1,2,3,4,5]
    s2 = [2,1,2,3,2,4,2,5]
    s3 = [3,3,1,1,2,2,4,4,5,5]

    for i in range(len(answers)):
        if answers[i] == s1[i%5] :
            sum1 = sum1 + 1
        if answers[i] == s2[i%8] :
            sum2 = sum2 + 1
        if answers[i] == s3[i%10] :
            sum3 = sum3 + 1
            
    answer = []
    if sum1 > sum2 and sum1 > sum3 :
        answer.append(1)
    elif sum2 > sum1 and sum2 > sum3 :
        answer.append(2)
    elif sum3 > sum1 and sum3 > sum2 :
        answer.append(3)
    elif sum1 == sum2 and sum1 > sum3 :
        answer.append(1)
        answer.append(2)
    elif sum1 == sum3 and sum1 > sum2 :
        answer.append(1)
        answer.append(3)
    elif sum2 == sum3 and sum2 > sum1 :
        answer.append(2)
        answer.append(3)
    else :
        answer.append(1)
        answer.append(2)
        answer.append(3)
    return answer

answers = [1,3,2,4,2]
print(solution(answers))