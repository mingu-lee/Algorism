import numpy as np
n = int(input("1~10 number-> "))
a = [[0]*n for i in range(n)]

for i in range(n):
    for j in range(n):
        a[i][j] = int(input())

print(np.matrix(a))
sum=0
for i in range(n):
    for j in range(n):
        if(a[i][j]==1):
            sum = sum + a[i][j]

print(sum)