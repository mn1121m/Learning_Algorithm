# Solve Tromino Puzzle with the Divide & Conquer Strategy

# print
def print_board(board):
    for i in range(n):
        for j in range(n):
            if j == n-1:
                print(board[i][j], end = "")
            else:
                print(board[i][j], end = " ")
        print()


# 어느 사분면에 속하는지 (1 ~ 4 사분면) return 해주는 함수
def whereis(n, srow, scol, row, col):
    m = n // 2
    if row - srow < m:
        return 1 if col - scol < m else 2
    else:
        return 3 if col - scol < m else 4


# 어디에 있는지에 따라 각 사분면에 있지 않았을 경우 board값을 n을 채우는 함수
def fill(n, board, srow, scol, where):
    global count
    count += 1
    if where != 1: board[srow][scol] = count
    if where != 2: board[srow][scol+1] = count
    if where != 3: board[srow+1][scol] = count
    if where != 4: board[srow+1][scol+1] = count


# 구멍의 위치를 결정하는 함수
# 현재 part에서 구멍이 있는 위치(where)와 같다면 return 해준다
# 다르면 나머지 사분면에 구멍을 채우면 된다.
def hole(part, where, n, srow, scol, row, col):
    m = n // 2
    if (part != where):
        row, col = srow + m - 1, scol + m - 1
        if part == 2 or part == 4: col += 1
        if part == 3 or part == 4: row += 1
    return row, col


# tromino함수 - divide & conquer
def tromino(n, board, srow, scol, row, col):
    where = whereis(n, srow, scol, row, col)    # 어느 사분면에 구멍이 있는지를 where로 결정한다
    if n == 2:
        fill(n, board, srow, scol, where)
    else:
        m = n // 2
        fill(n, board, srow + m - 1, scol + m - 1, where)
        hrow, hcol = hole(1, where, n, srow, scol, row, col)
        tromino(m, board, srow, scol, hrow, hcol)
        hrow, hcol = hole(2, where, n, srow, scol, row, col)
        tromino(m, board, srow, scol+m, hrow, hcol)
        hrow, hcol = hole(3, where, n, srow, scol, row, col)
        tromino(m, board, srow+m, scol, hrow, hcol)
        hrow, hcol = hole(4, where, n, srow, scol, row, col)
        tromino(m, board, srow+m, scol+m, hrow, hcol)


n, row, col = map(int, input().split())
board = [[0 for _ in range(n)] for _ in range(n)]
srow, scol = 0, 0
count = 0
tromino(n, board, srow, scol, row, col)
print_board(board);
