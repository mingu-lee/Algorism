def solution(phone_number):
    answer = []
    a = '****'
    for i in range(len(phone_number)-4):
        answer.append(phone_number[i])
    answer = "".join(answer)
    return answer + a
phone_number = "0243214444"
print(solution(phone_number))
