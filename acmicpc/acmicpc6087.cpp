#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Coord
{
    int x, y;
};

struct SearchInfo
{
    Coord coord;
    int mirrorCount;
    int dirIndex;
};

const int MAX = 1000000000;
const int ARRMAX = 100;
const char WALL = '*';
const char COM = 'C';

int DirX[4] = {0, 1, 0, -1};
int DirY[4] = {1, 0, -1, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int W, H;
    cin >> W >> H;

    char Map[ARRMAX][ARRMAX];
    int mirrorCount[ARRMAX][ARRMAX][4];
    bool visited[ARRMAX][ARRMAX][4];

    vector<Coord> coms;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            cin >> Map[y][x];

            if (Map[y][x] == COM) {
                coms.push_back({x, y});
            }

            for (int i = 0; i < 4; ++i) {
                mirrorCount[y][x][i] = MAX;
            }
        }
    }

    queue<SearchInfo> searchQueue;
    searchQueue.push({coms[0], 0, -1});
    for (int i = 0; i < 4; ++i)
    {
        visited[coms[0].y][coms[0].x][i] = true;
    }

    while (!searchQueue.empty())
    {
        SearchInfo cur = searchQueue.front();
        searchQueue.pop();

        for (int i = 0; i < 4; ++i)
        {
            Coord nextCoord = {cur.coord.x + DirX[i], cur.coord.y + DirY[i]};

            if ((nextCoord.x < 0 || nextCoord.x >= W || nextCoord.y < 0 || nextCoord.y >= H) ||
                Map[nextCoord.y][nextCoord.x] == WALL)
            {
                continue;
            }

            if (cur.dirIndex == -1 &&
                mirrorCount[nextCoord.y][nextCoord.x][i] > cur.mirrorCount)
            {
                visited[nextCoord.y][nextCoord.x][i] = true;
                mirrorCount[nextCoord.y][nextCoord.x][i] = cur.mirrorCount;
                searchQueue.push({nextCoord, cur.mirrorCount, i});
            }
            else if (cur.dirIndex != -1 && mirrorCount[nextCoord.y][nextCoord.x][i] > cur.mirrorCount + 1)
            {
                visited[nextCoord.y][nextCoord.x][i] = true;
                mirrorCount[nextCoord.y][nextCoord.x][i] = cur.mirrorCount + 1;
                searchQueue.push({nextCoord, cur.mirrorCount + 1, i});
            }
            else if (cur.dirIndex != -1 && mirrorCount[nextCoord.y][nextCoord.x][i] > cur.mirrorCount)
            {
                visited[nextCoord.y][nextCoord.x][i] = true;
                mirrorCount[nextCoord.y][nextCoord.x][i] = cur.mirrorCount;
                searchQueue.push({nextCoord, cur.mirrorCount, i});
            }
        }
    }

    int answer = MAX;
    for (int i = 0; i < 4; ++i) {
        if (!visited[coms[1].y][coms[1].x][i]) {
            continue;
        }

        answer = min(answer, mirrorCount[coms[1].y][coms[1].x][i]);
    }

    cout << answer;
}