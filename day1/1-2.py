from itertools import combinations
def oneday():
    f = open("c:/Users/lmg37/Desktop/algorism/day1/puzzle.txt", 'r')
    lines = f.readlines()
    s = []
    answer = []
    for line in lines:
        s.append(int(line.rstrip('\n')))

    combi = list(combinations(s,3))
    for i in combi:
        iplus = i[0]+i[1]+i[2]
        if iplus == 2020:
            answer.append(i[0]*i[1]*i[2])

    return answer

print(oneday())