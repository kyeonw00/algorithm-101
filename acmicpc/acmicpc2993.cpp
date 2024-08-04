#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<char>> cave;
typedef pair<int, int> coord;

bool VISITED[101][101];
int DIRX[4] = { 0, 0, 1, -1 };
int DIRY[4] = { 1, -1, 0, 0 };

void throwStickAtHeight(cave& map, const int height, const int dir)
{
    if (dir == 1)
    {
        // throw to right
        for (int c = 0; c < map[height].size(); ++c)
        {
            if (map[height][c] == 'x')
            {
                map[height][c] = '.';
                break;
            }
        }
    }
    else
    {
        // throw to left
        for (int c = map[height].size() - 1; c >= 0; --c)
        {
            if (map[height][c] == 'x')
            {
                map[height][c] = '.';
                break;
            }
        }
    }
}

void searchNeiboringMineral(int baseR, int baseC, const cave &map)
{
    queue<coord> searchQueue;
    searchQueue.push(make_pair(baseR, baseC));

    VISITED[baseR][baseC] = true;

    while (!searchQueue.empty())
    {
        int r = searchQueue.front().first, c = searchQueue.front().second;
        searchQueue.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dX = r + DIRX[i], dY = c + DIRY[i];

            if (dX < 0 || dX >= map.size() || dY < 0 || dY >= map[0].size())
            {
                continue;
            }

            if (map[dX][dY] == 'x' && !VISITED[dX][dY])
            {
                searchQueue.push(make_pair(dX, dY));
                VISITED[dX][dY] = true;
            }
        }
    }
}

bool findFloatingCluster(const cave& map, vector<coord>& floatingClusters)
{
    memset(VISITED, false, sizeof(VISITED));

    // remove grounded minerals from search target
    for (int c = 0; c < map[0].size(); ++c)
    {
        if (map[0][c] == 'x' && !VISITED[0][c])
        {
            searchNeiboringMineral(0, c, map);
        }
    }

    // search floating clusters
    for (int r = 0; r < map.size(); ++r)
    {
        for (int c = 0; c < map[r].size(); ++c)
        {
            if (map[r][c] == 'x' && !VISITED[r][c])
            {
                floatingClusters.push_back(make_pair(r, c));
            }
        }
    }

    return floatingClusters.size() > 0;
}

void updateFloatingClusterCoords(cave& map, const vector<coord>& floatingClusters)
{
    // find minimum distance which floating cluster can be dropped
    int minDist = 100;
    for (int i = 0; i < floatingClusters.size(); ++i)
    {
        int fallDistance = 0;
        for (int r = floatingClusters[i].first - 1; r >= 0; --r)
        {
            if (map[r][floatingClusters[i].second] == '.')
            {
                ++fallDistance;
            }
            
            if (map[r][floatingClusters[i].second] == 'x' &&
                VISITED[r][floatingClusters[i].second])
            {
                break;
            }
        }

        if (fallDistance < minDist)
        {
            minDist = fallDistance;
        }
    }

    // drop given clusters and apply changes to map
    for (int r = 0; r < map.size(); ++r)
    {
        for (int c = 0; c < map[r].size(); ++c)
        {
            if (map[r][c] == 'x' && !VISITED[r][c])
            {
                map[r - minDist][c] = map[r][c];
                map[r][c] = '.';
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    cin >> R >> C;

    cave map(R, vector<char>(C));
    for (int i = R - 1; i >= 0; --i)
    {
        string row;
        cin >> row;
        for (int j = 0; j < C; ++j)
        {
            map[i][j] = row[j];
        }
    }

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int height;
        cin >> height;

        // subtract 1 from height, bcecuase map is 0-indexed but height is i-indexed
        throwStickAtHeight(map, height - 1, i % 2 == 1 ? 1 : -1);

        vector<coord> floatingClusters;
        if (findFloatingCluster(map, floatingClusters))
        {
            updateFloatingClusterCoords(map, floatingClusters);
        }
    }

    for (int r = R - 1; r >= 0; --r)
    {
        for (int c = 0; c < C; ++c)
        {
            cout << map[r][c];
        }

        cout << '\n';
    }
}