def oneday():
    f = open("c:/Users/lmg37/Desktop/algorism/day1/puzzle.txt", 'r')
    lines = f.readlines()
    s = []
    answer = []
    for line in lines:
        s.append(int(line.rstrip('\n')))

    for i in range(0,len(s)):
        for j in range(1,len(s)):
            if s[i] + s[j] == 2020:
                answer.append(s[i]*s[j])
    return answer

print(oneday())