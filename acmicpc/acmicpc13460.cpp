#include <iostream>
#include <queue>

using namespace std;

struct movement_history
{
    int redX, redY;
    int blueX, blueY;
    int moveCount;
};

int MOVE_DIR_X[4] { 1, -1, 0, 0 };
int MOVE_DIR_Y[4] { 0, 0, 1, -1 };

char board[11][11];
bool board_visited[11][11][11][11];

void move_ball(int& posX, int& posY, int& moveCount, const int xMoveDir, const int yMoveDir)
{
    while (board[posY + yMoveDir][posX + xMoveDir] != '#' && board[posY][posX] != 'O')
    {
        posX += xMoveDir;
        posY += yMoveDir;
        ++moveCount;
    }
}

void find_solution(const int redX, const int redY, const int blueX, const int blueY)
{
    queue<movement_history> movementHistory;
    movementHistory.push({ redX, redY, blueX, blueY, 0 });
    board_visited[redX][redY][blueX][blueY] = true;

    while (!movementHistory.empty())
    {
        int currentRedX = movementHistory.front().redX;
        int currentRedY = movementHistory.front().redY;
        int currentBlueX = movementHistory.front().blueX;
        int currentBlueY = movementHistory.front().blueY;
        int moveCount = movementHistory.front().moveCount;

        movementHistory.pop();
        
        if (moveCount >= 10)
        {
            break;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nextMoveCount = moveCount + 1;

            int nextRedX = currentRedX;
            int nextRedY = currentRedY;
            int redMoveCount = 0;

            move_ball(nextRedX, nextRedY, redMoveCount, MOVE_DIR_X[i], MOVE_DIR_Y[i]);

            int nextBlueX = currentBlueX;
            int nextBlueY = currentBlueY;
            int blueMoveCount = 0;

            move_ball(nextBlueX, nextBlueY, blueMoveCount, MOVE_DIR_X[i], MOVE_DIR_Y[i]);

            if (board[nextBlueY][nextBlueX] == 'O')
            {
                continue;
            }

            if (board[nextRedY][nextRedX] == 'O')
            {
                cout << nextMoveCount;
                return;
            }

            if (nextRedX == nextBlueX && nextRedY == nextBlueY)
            {
                if (redMoveCount > blueMoveCount)
                {
                    nextRedX -= MOVE_DIR_X[i];
                    nextRedY -= MOVE_DIR_Y[i];
                }
                else
                {
                    nextBlueX -= MOVE_DIR_X[i];
                    nextBlueY -= MOVE_DIR_Y[i];
                }
            }

            if (board_visited[nextRedX][nextRedY][nextBlueX][nextBlueY])
            {
                continue;
            }

            board_visited[nextRedX][nextRedY][nextBlueX][nextBlueY] = true;
            movementHistory.push({ nextRedX, nextRedY, nextBlueX, nextBlueY, nextMoveCount });
        }
    }

    cout << -1;
}

int main()
{
    int N; // size of y axis
    int M; // size of x axis

    cin >> N >> M;

    int redX, redY;
    int blueX, blueY;
    for (int n = 0; n < N; ++n)
    {
        cin >> board[n];

        for (int m = 0; m < M; ++m)
        {
            if (board[n][m] == 'R')
            {
                redX = m;
                redY = n;
            }
            else if (board[n][m] == 'B')
            {
                blueX = m;
                blueY = n;
            }
        }
    }

    find_solution(redX, redY, blueX, blueY);
}