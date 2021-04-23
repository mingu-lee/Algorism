
def twoday():
    f = open("c:/Users/lmg37/Desktop/algorism/day2/puzzle.txt", 'r')
    lines = f.readlines()
    lines = [line.strip() for line in lines]
    answer = 0

    for i in lines:
        a = i.split(' ')
        a_1 = a[0].split('-')
        con_num = int(a_1[0])
        notcon_num = int(a_1[1])
        a_2 = a[1].split(':')[0]
        a_3 = a[2]

        if a_2 == a_3[con_num-1] and a_2 != a_3[notcon_num-1] :
                answer += 1

    return answer

print(twoday())