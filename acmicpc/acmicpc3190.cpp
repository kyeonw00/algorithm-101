// #include <iostream>
// #include <vector>
// #include <string>
// #include <deque>

// using namespace std;

// const int MAX = 100;

// typedef struct
// {
//     int y, x;
// } Dir;

// Dir moveDir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// int N, K, L;
// bool visited[MAX][MAX];
// bool apple[MAX][MAX];

// int main(void)
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> N;
//     cin >> K;

//     for (int k = 0; k < K; k++)
//     {
//         int y, x;
//         cin >> y >> x;
//         apple[y - 1][x - 1] = true;
//     }

//     cin >> L;
//     deque<pair<int, char>> turn;
//     for (int l = 0; l < L; l++)
//     {
//         int X;
//         char C;
//         cin >> X >> C;
//         turn.push_back({X, C});
//     }

//     int sec = 0;
//     int idx = 0; //초기 오른쪽
//     deque<pair<int, int>> snake;
//     snake.push_back({0, 0}); //초기 위치
//     visited[0][0] = true;

//     while (1)
//     {
//         sec++;
//         pair<int, int> before = snake.back();
//         pair<int, int> cur = {before.first + moveDir[idx].y, before.second + moveDir[idx].x};

//         //뱀의 머리가 몸에 부딪히거나, 범위를 벗어날 경우
//         if (visited[cur.first][cur.second] || !(0 <= cur.first && cur.first < N && 0 <= cur.second && cur.second < N))
//         {
//             cout << sec << "\n";
//             break;
//         }

//         visited[cur.first][cur.second] = true;
//         snake.push_back(cur);

//         //사과가 있는 위치면 꼬리 그대로
//         if (apple[cur.first][cur.second])
//             apple[cur.first][cur.second] = false;
//         //사과 없으면 꼬리가 있던 칸을 지운다
//         else
//         {
//             pair<int, int> tail = snake.front();
//             visited[tail.first][tail.second] = false;
//             snake.pop_front();
//         }

//         //마지막에 방향 전환
//         if (turn.size() && turn.front().first == sec)
//         {
//             if (turn.front().second == 'L')
//                 idx = (idx + 3) % 4;
//             else
//                 idx = (idx + 1) % 4;
//             turn.pop_front();
//         }
//     }

//     return 0;
// }

#include <iostream>
#include <deque>

using namespace std;

const int BOARD_SIZE_MAX = 100;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int N, K, L;
bool BOARD[BOARD_SIZE_MAX][BOARD_SIZE_MAX] = { false };
bool BOARD_VISITED[BOARD_SIZE_MAX][BOARD_SIZE_MAX] = { false };
deque<pair<int, char>> COMMANDS;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> K;
    for (int k = 0, x = 0, y = 0; k < K; k++)
    {
        cin >> x >> y;
        BOARD[x - 1][y - 1] = true;
    }

    cin >> L;
    char c;
    for (int l = 0, t = 0; l < L; l++)
    {
        cin >> t >> c;
        COMMANDS.push_back(make_pair(t, c));
    }

    int moveDir = 0;
    int seconds = 0;
    deque<pair<int, int>> snake;
    BOARD_VISITED[0][0] = true;
    snake.push_back(make_pair(0, 0));

    while (true)
    {
        seconds++;
        int destX = snake.back().first + dx[moveDir];
        int destY = snake.back().second + dy[moveDir];

        if (destX >= N || destX < 0 || destY >= N || destY < 0)
        {
            break;
        }

        if (BOARD_VISITED[destX][destY] == true)
        {
            break;
        }

        snake.push_back(make_pair(destX, destY));
        BOARD_VISITED[destX][destY] = true;

        if (BOARD[destX][destY] == true)
        {
            BOARD[destX][destY] = false;
        }
        else
        {
            BOARD_VISITED[snake.front().first][snake.front().second] = false;
            snake.pop_front();
        }

        if ((COMMANDS.size() > 0 && COMMANDS.front().first == seconds))
        {
            if (COMMANDS.front().second == 'L')
            {
                if (moveDir == 0) moveDir = 3;
                else if (moveDir == 1) moveDir = 0;
                else if (moveDir == 2) moveDir = 1;
                else if (moveDir == 3) moveDir = 2;
            }
            else
            {
                if (moveDir == 0) moveDir = 1;
                else if (moveDir == 1) moveDir = 2;
                else if (moveDir == 2) moveDir = 3;
                else if (moveDir == 3) moveDir = 0;
            }
            COMMANDS.pop_front();
        }
    }

    cout << seconds << endl;

    return 0;
}