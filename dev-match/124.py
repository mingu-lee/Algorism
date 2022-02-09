# -*- coding: utf-8 -*-
'''
문제 설명
124 나라가 있습니다. 124 나라에서는 10진법이 아닌 다음과 같은 자신들만의 규칙으로 수를 표현합니다.

124 나라에는 자연수만 존재합니다.
124 나라에는 모든 수를 표현할 때 1, 2, 4만 사용합니다.
예를 들어서 124 나라에서 사용하는 숫자는 다음과 같이 변환됩니다.

10진법	124 나라	10진법	124 나라
    1       1	        6	    14
    2	    2	        7	    21
    3	    4	        8	    22
    4	    11	        9	    24
    5	    12	        10	    41
자연수 n이 매개변수로 주어질 때, n을 124 나라에서 사용하는 숫자로 바꾼 값을 return 하도록 solution 함수를 완성해 주세요.

제한사항
n은 500,000,000이하의 자연수 입니다.
입출력 예
n	result
1	1
2	2
3	4
4	11
5   12
6   14
7   21 22 24 41 42 44(12) 111 112 114
15  114
16  121
17  122
18  124
19  141
20  142
21  144 211 212 214 221 222 224 241 242 244 411
39  444
40  1111   
513에 결과값 "124224"
'''

def solution(n):
    ret = ''
    answer = ''
    if n < 3:
        ret= '{}'.format(n)
    else:
        no=n
    while (no >= 3):
        re = no%3 
        print(re)
        no = no//3 
        print(no)
        if re > 0:
            answer='{}'.format(re)
            ret += answer
            if no < 3:
                answer='{}'.format(no)
                ret += answer
        elif re == 0:
            re=4
            no=no-1
            if no > 2:
                answer='{}'.format(re)
                ret += answer
            else:
                if no==0:
                    answer='{}'.format(re)
                else:
                    answer='{}{}'.format(re,no)
                ret += answer

    return ret[::-1]

if __name__ == "__main__":
    print(solution(33))
