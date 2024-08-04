#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int DirX[4] = { 1,-1, 0, 0 };
const int DirY[4] = { 0, 0, 1,-1 };

void readArguments(
    int& N, int& M, int Map[8][8],
    vector<pair<int, int>>& emptyCoords, int& wallCount, vector<pair<int, int>>& virusCoords)
{
    cin >> N >> M;
    for (int n = 0; n < N; ++n)
    {
        for (int m = 0; m < M; ++m)
        {
            cin >> Map[n][m];
            switch (Map[n][m])
            {
                case 0: emptyCoords.push_back({n, m}); break;
                case 1: ++wallCount; break;
                case 2: virusCoords.push_back({n, m}); break;
            }
        }
    }
}

int findSolution(
    int Map[8][8], const int N, const int M,
    vector<pair<int, int>> emptyCoords, const int wallCount, vector<pair<int, int>> virusCoords)
{
    int cellCount = emptyCoords.size();
    int maxSafeCellCount = 0;
    int totalCellCount = N * M;
    for (int p1 = 0; p1 < cellCount; ++p1)
    {
        for (int p2 = p1 + 1; p2 < cellCount; ++p2)
        {
            for (int p3 = p2 + 1; p3 < cellCount; ++p3)
            {
                Map[emptyCoords[p1].first][emptyCoords[p1].second] = 1;
                Map[emptyCoords[p2].first][emptyCoords[p2].second] = 1;
                Map[emptyCoords[p3].first][emptyCoords[p3].second] = 1;

                queue<pair<int, int>> contaminatedCoords;
                bool searchHistory[8][8] = {
                    {
                        false,
                    },
                };
                for (pair<int, int> coord : virusCoords)
                {
                    contaminatedCoords.push(coord);
                }

                int contaminatedCellsCount = contaminatedCoords.size();
                while (!contaminatedCoords.empty())
                {
                    int coordX = contaminatedCoords.front().second;
                    int coordY = contaminatedCoords.front().first;
                    contaminatedCoords.pop();

                    for (int dirIndex = 0; dirIndex < 4; ++dirIndex)
                    {
                        int targetX = coordX + DirX[dirIndex];
                        int targetY = coordY + DirY[dirIndex];

                        if (targetX < 0 || targetX >= M || targetY < 0 || targetY >= N)
                        {
                            continue;
                        }

                        if (Map[targetY][targetX] == 0 && !searchHistory[targetY][targetX])
                        {
                            contaminatedCoords.push({targetY, targetX});
                            searchHistory[targetY][targetX] = true;
                            ++contaminatedCellsCount;
                        }
                    }
                }

                int safeCellCount = totalCellCount - contaminatedCellsCount - wallCount - 3;
                maxSafeCellCount = maxSafeCellCount < safeCellCount ? safeCellCount : maxSafeCellCount;

                Map[emptyCoords[p1].first][emptyCoords[p1].second] = 0;
                Map[emptyCoords[p2].first][emptyCoords[p2].second] = 0;
                Map[emptyCoords[p3].first][emptyCoords[p3].second] = 0;
            }
        }
    }

    return maxSafeCellCount;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, Map[8][8];
    vector<pair<int, int>> emptyCoords;
    int wallCount = 0;
    vector<pair<int, int>> virusCoords;

    readArguments(N, M, Map, emptyCoords, wallCount, virusCoords);
    int maxSafeCellCount = findSolution(Map, N, M, emptyCoords, wallCount, virusCoords);

    cout << maxSafeCellCount << '\n';
}