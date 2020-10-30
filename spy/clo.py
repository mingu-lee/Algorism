temp = {}
clothes = [["yellow_hat", "headgear"], ["blue_sunglasses", "eyewear"], ["green_turban", "headgear"]] 
for _, cat in clothes: 
    temp[cat] = temp.get(cat, 0) + 1
    print(temp)
    answer = 1 
    for each in temp.values(): 
        answer *= each + 1
    print(each)
print(answer - 1)