#include <iostream>
#include <iomanip>  // 숫자 두 자리로 포맷 해주기 위해
using namespace std;

// 연습 문제 : 달팽이
// 달팽이처럼 소용돌이치는 듯이 정렬된 숫자 배열 출력해보기

const int MAX = 100;
int board[MAX][MAX] = {};
int N;

enum DIR {
    RIGHT = 0,
    DOWN = 1,
    LEFT = 2,
    UP = 3
};

void PrintBoard() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cout << setfill('0') << setw(2) << board[y][x] << " ";
        }
        cout << endl;
    }
}

void SetBoard() {
    int dir = RIGHT;
    int num = 1;
    int y = 0;
    int x = 0;

    int dy[4] = { 0, 1, 0, -1 };
    int dx[4] = { 1, 0, -1, 0 };

    while (true) {
        board[y][x] = num;

        if (num == N * N) break;

        int ny = y + dy[dir];
        int nx = x + dx[dir];
        /*
        switch (dir)
        {
        case RIGHT:
            ny = y;
            nx = x + 1;
            break;
        case DOWN:
            ny = y + 1;
            nx = x;
            break;
        case LEFT:
            ny = y;
            nx = x - 1;
            break;
        case UP:
            ny = y - 1;
            nx = x;
            break;
        }
        */

        // 이동할 수 있는지 체크
        // 이동하지 못하면 방향 전환
        if (ny < 0 || ny >= N || nx < 0 || nx >= N || board[ny][nx] != 0) {
            dir = (dir + 1) % 4;
            /*
            switch (dir) 
            {
            case RIGHT:
                dir = DOWN;
                break;
            case DOWN:
                dir = LEFT;
                break;
            case LEFT:
                dir = UP;
                break;
            case UP:
                dir = RIGHT;
                break;
            }
            */
            continue;
        }

        y = ny;
        x = nx;
        num++;
    }
 
}

int main()
{
    cin >> N;

    SetBoard();

    PrintBoard();

    return 0;
}