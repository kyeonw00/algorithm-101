#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

const int BOARD_MAX_SIZE = 100;
const int APPLE_MAX_SIZE = 100;

int MOVE_DIR_X[4] = { 0, 1, 0, -1 };
int MOVE_DIR_Y[4] = { 1, 0, -1, 0 };

int N, K, L;
bool DP_VISITED[BOARD_MAX_SIZE][BOARD_MAX_SIZE];
bool BOARD_APPLE_POS[BOARD_MAX_SIZE][BOARD_MAX_SIZE];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int x;
    int y;
    int second = 0;
    int index = 0;
    char c;
    deque<pair<int, char>> moveDir;
    deque<pair<int, int>> snake_move_history;

    cin >> N;
    cin >> K;

    for (int k = 0; k < K; k++)
    {
        cin >> y >> x;
        BOARD_APPLE_POS[y - 1][x - 1] = true;
    }

    cin >> L;
    for (int l = 0; l < L; l++)
    {
        cin >> x >> c;
        moveDir.push_back({x, c});
    }

    snake_move_history.push_back({0, 0});
    DP_VISITED[0][0] = true;

    while (true)
    {
        second++;
        pair<int, int> prevMove = snake_move_history.back();
        pair<int, int> currentMove = { prevMove.first + MOVE_DIR_Y[index], prevMove.second + MOVE_DIR_X[index]};

        if (DP_VISITED[currentMove.first][currentMove.second] || !(0 <= currentMove.first && N > currentMove.first && 0 <= currentMove.second && N > currentMove.second))
        {
            cout << second << endl;
            break;
        }

        DP_VISITED[currentMove.first][currentMove.second] = true;
        snake_move_history.push_back(currentMove);

        if (BOARD_APPLE_POS[currentMove.first][currentMove.second] == true)
        {
            BOARD_APPLE_POS[currentMove.first][currentMove.second] = false;
        }
        else
        {
            DP_VISITED[snake_move_history.front().first][snake_move_history.front().second] = false;
            snake_move_history.pop_front();
        }

        if (moveDir.size() != 0 && moveDir.front().first == second)
        {
            if (moveDir.front().second == 'L')
            {
                index = (index + 3) % 4;
            }
            else
            {
                index = (index + 1) % 4;
            }

            moveDir.pop_front();
        }
    }

    return 0;
}