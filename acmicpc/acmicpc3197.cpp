#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_LAKE_SIZE = 1500;
const char ICE = 'X';
const char WATER = '.';
const char SWAN = 'L';

const int DirX[4] = {0, 1, 0, -1};
const int DirY[4] = {1, 0, -1, 0};

int R, C;
vector<pair<int, int>> Swan;
char Lake[MAX_LAKE_SIZE][MAX_LAKE_SIZE];
int meltDateTable[MAX_LAKE_SIZE][MAX_LAKE_SIZE] = {-1};
bool visited[MAX_LAKE_SIZE][MAX_LAKE_SIZE] = {false};
queue<pair<int, int>> searchQueue;
int maxDateToMelt = 0;

// R : Height(y), C : Width(x)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
        {
            cin >> Lake[r][c];

            if (Lake[r][c] == SWAN)
                Swan.push_back({r, c});
        }
    }

    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
        {
            if (Lake[r][c] == ICE)
            {
                continue;
            }

            meltDateTable[r][c] = 0;
            searchQueue.push({r, c});
        }
    }

    while (!searchQueue.empty())
    {
        auto currentCoord = searchQueue.front();
        searchQueue.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nextY = currentCoord.first + DirY[i];
            int nextX = currentCoord.second + DirX[i];

            if ((nextX < 0 || nextX >= C || nextY < 0 || nextY >= R) ||
                meltDateTable[nextY][nextX] >= 0)
            {
                continue;
            }

            meltDateTable[nextY][nextX] = meltDateTable[currentCoord.first][currentCoord.second] + 1;
            searchQueue.push({nextY, nextX});

            maxDateToMelt = max(maxDateToMelt, meltDateTable[nextY][nextX]);
        }
    }

    int begin = 0, end = maxDateToMelt;
    while (begin <= end)
    {
        memset(visited, false, sizeof(visited));

        int mid = (begin + end) / 2;

        searchQueue.push(Swan[0]);
        visited[Swan[0].first][Swan[0].second] = true;

        bool canSwansMeet = false;
        while (!searchQueue.empty())
        {
            auto currentCoord = searchQueue.front();

            if (currentCoord.first == Swan[1].first && currentCoord.second == Swan[1].second)
            {
                canSwansMeet = true;
                break;
            }

            searchQueue.pop();

            for (int i = 0; i < 4; ++i)
            {
                int nextY = currentCoord.first + DirY[i];
                int nextX = currentCoord.second + DirX[i];

                if ((nextX < 0 || nextX >= C || nextY < 0 || nextY >= R) ||
                    visited[nextY][nextX] ||
                    meltDateTable[nextY][nextX] > mid)
                {
                    continue;
                }

                visited[nextY][nextX] = true;
                searchQueue.push({nextY, nextX});
            }
        }

        if (canSwansMeet) end = mid - 1;
        else begin = mid + 1;
    }

    cout << begin << '\n';
}