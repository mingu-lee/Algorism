
def queen(board):
    answer = 0
    n = len(board)
    if n == N:
        return True
    for i in range(N):
        for j in range(n):
            if i == board[j]: break
            if n - j == i - board[j]: break
            if board[j] - i == n - j: break
        else:
            answer += queen(board + [i])
    return answer
board = []
N = 8
print(queen(board))