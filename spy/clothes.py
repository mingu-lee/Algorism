clothes = [["yellow_hat", "headgear"], ["blue_sunglasses", "eyewear"], ["green_turban", "headgear"]]
#clothes = [["crow_mask", "face"], ["blue_sunglasses", "face"], ["smoky_makeup", "face"]]
w=0
s=0
a=[]
for i in range(len(clothes)):
    a = clothes[i][1]
    for j in range(len(clothes)):
        if clothes[i][1] == clothes[j][1]:
            if(i>j):
                w -= 1
    print(a)
for i in range(len(clothes)):
    for j in range(len(clothes)):
        if (clothes[i] != clothes[j] or clothes[i] == clothes[j]):
            if(i>=j):
                w += 1

print(w)