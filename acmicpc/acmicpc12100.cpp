#include <iostream>
#include <vector>

using namespace std;

int N;
long long Answer = 0;

int max(int a, int b) { return a > b ? a : b; }

vector<vector<long long>> swipe(vector<vector<long long>> board, const int swipeDirX, const int swipeDirY)
{
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    if (swipeDirX == -1)
    {
        for (int y = 0; y < N; ++y)
        {
            for (int x = 1; x < N; ++x)
            {
                if (board[y][x] == 0)
                {
                    continue;
                }

                for (int i = x - 1; i >= 0; --i)
                {
                    if (board[y][i] == board[y][i + 1] && !visited[y][i])
                    {
                        board[y][i] *= 2;
                        board[y][i + 1] = 0;
                        visited[y][i] = true;
                        break;
                    }
                    else if (board[y][i] == 0)
                    {
                        board[y][i] = board[y][i + 1];
                        board[y][i + 1] = 0;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    else if (swipeDirX == 1)
    {
        for (int y = 0; y < N; ++y)
        {
            for (int x = N - 2; x >= 0; --x)
            {
                if (board[y][x] == 0)
                {
                    continue;
                }

                for (int i = x + 1; i < N; ++i)
                {
                    if (board[y][i] == board[y][i - 1] && !visited[y][i])
                    {
                        board[y][i] *= 2;
                        board[y][i - 1] = 0;
                        visited[y][i] = true;
                        break;
                    }
                    else if (board[y][i] == 0)
                    {
                        board[y][i] = board[y][i - 1];
                        board[y][i - 1] = 0;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    else if (swipeDirY == -1)
    {
        for (int x = 0; x < N; ++x)
        {
            for (int y = N - 2; y >= 0; --y)
            {
                if (board[y][x] == 0)
                {
                    continue;
                }

                for (int i = y + 1; i < N; ++i)
                {
                    if (board[i][x] == board[i - 1][x] && !visited[i][x])
                    {
                        board[i][x] *= 2;
                        board[i - 1][x] = 0;
                        visited[i][x] = true;
                        break;
                    }
                    else if (board[i][x] == 0)
                    {
                        board[i][x] = board[i - 1][x];
                        board[i - 1][x] = 0;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    else if (swipeDirY == 1)
    {
        for (int x = 0; x < N; ++x)
        {
            for (int y = 1; y < N; ++y)
            {
                if (board[y][x] == 0)
                {
                    continue;
                }

                for (int i = y - 1; i >= 0; --i)
                {
                    if (board[i][x] == board[i + 1][x] && !visited[i][x])
                    {
                        board[i][x] *= 2;
                        board[i + 1][x] = 0;
                        visited[i][x] = true;
                        break;
                    }
                    else if (board[i][x] == 0)
                    {
                        board[i][x] = board[i + 1][x];
                        board[i + 1][x] = 0;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }

    return board;
}

int find_max_block(vector<vector<long long>> board)
{
    int biggestBlock = 0;
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            biggestBlock = max(biggestBlock, board[y][x]);
        }
    }

    return biggestBlock;
}

void simulate(int stepCount, vector<vector<long long>> board)
{
    Answer = max(Answer, find_max_block(board));

    if (stepCount >= 5)
    {
        return;
    }

    simulate(stepCount + 1, swipe(board, -1,  0));
    simulate(stepCount + 1, swipe(board,  1,  0));
    simulate(stepCount + 1, swipe(board,  0,  1));
    simulate(stepCount + 1, swipe(board,  0, -1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector<vector<long long>> board(N, vector<long long>(N));
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            cin >> board[y][x];
        }
    }

    simulate(0, board);
    cout << Answer << '\n';
    
    return 0;
}