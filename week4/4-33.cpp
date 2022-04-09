#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > board;
int order = 1;


int whereis(int n, int srow, int scol, int row, int col){
    // srow, scol = Start location
    // row, col = Hole Location
    int m = n/2;
    if(row - srow < m){
        if(col - scol < m) return 1;
        else return 2;
    }
    else{
        if(col - scol < m) return 3;
        else return 4;
    }
}

void fill(int n, board& board, int srow, int scol, int where){
    if(where != 1)
        board[srow][scol] = order;
    if(where != 2)
        board[srow][scol+1] = order;
    if(where != 3)
        board[srow+1][scol] = order;
    if(where != 4)
        board[srow+1][scol+1] = order;
    order++;
}

void hole(int arr[], int part, int where, int n, int srow, int scol, int row, int col){
    int m = n/2;
    // 현재 사분면이 구멍 있는 사분면이 아니면, 그전에 번호 채웠던 곳을 구멍으로 치기
    // 현재 사분면이 구멍 있는 사분면이 맞으면, 구멍위치 그대로
    if(part != where){
        row = srow + m - 1;
        col = scol + m - 1;
        if(part == 2 || part == 4)
            col += 1;
        if(part == 3 || part == 4)
            row += 1;
    }
    arr[0] = row;
    arr[1] = col;
}

void tromino(int n, board& board, int srow, int scol, int row, int col){
    int arr[2]; // arr[0] = hrow, arr[1] = hcol;
    int where = whereis(n, srow, scol, row, col);
    if(n == 2)
        fill(n, board, srow, scol, where);
    else{
        int m = n/2;  // 사분면 쪼개기
        fill(n, board, srow + m - 1, scol + m - 1, where); // 제일 큰 사분면을 지나게 3개 채우기
        hole(arr, 1, where, n, srow, scol, row, col);
        tromino(m, board, srow, scol, arr[0], arr[1]);
        hole(arr, 2, where, n, srow, scol, row, col);
        tromino(m, board, srow, scol+m, arr[0], arr[1]);
        hole(arr, 3, where, n, srow, scol, row, col);
        tromino(m, board, srow+m, scol, arr[0], arr[1]);
        hole(arr, 4, where, n, srow, scol, row, col);
        tromino(m, board, srow+m, scol+m, arr[0], arr[1]);
    }
}

int main()
{
    int n, row, col;
    board B;
    
    cin >> n;
    cin >> row;
    cin >> col;
    B.assign(n, vector<int>(n, 0));
    tromino(n, B, 0, 0, row, col);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << B[i][j];
            if(j != n - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
