n=20
ans = []
answer = 0
sum = 0
while(1):
    ans.append(n % 3)
    n = n // 3
    if n == 0 :
        break
ans.reverse()
for i in range(len(ans)):
    answer = 3**i * ans[i]
    sum = sum + answer
print(sum)


