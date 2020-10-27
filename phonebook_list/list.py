p = ["119", "97674223", "1195524421"]
w ={}
p.sort()

for i in range(0,len(p)-1):
    w[i] = p[i+1].find(p[0])
    if w[i]==0:
        break

if(w[i]==0):
    print(False)
else:
    print(True)