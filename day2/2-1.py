
def twoday():
    f = open("c:/Users/lmg37/Desktop/algorism/day2/puzzle.txt", 'r')
    lines = f.readlines()
    lines = [line.strip() for line in lines]
    answer = 0
    for i in lines:
        count = 0
        a = i.split(' ')
        a_1 = a[0].split('-')
        min = int(a_1[0])
        max = int(a_1[1])
        a_2 = a[1].split(':')[0]
        a_3 = a[2]

        for j in a_3:
            if a_2 == j:
                count += 1
                
        if min <= count <= max:
            answer += 1

    return answer

print(twoday())