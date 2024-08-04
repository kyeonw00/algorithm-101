#include <iostream>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

using namespace std;

const int DirX[4] = { 0, 1, 0,-1 };
const int DirY[4] = {-1, 0, 1, 0 };

bool isCoordOutOfRange(const int mapWidth, const int mapHeight, const int x, const int y)
{
    return x < 0 || x >= mapWidth || y < 0 || y >= mapHeight;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int r, c, d;
    cin >> r >> c >> d;

    int Map[50][50];
    for (int n = 0; n < N; ++n)
    {
        for (int m = 0; m < M; ++m)
        {
            cin >> Map[n][m];
        }
    }

    int cleanedCellCount = 0;
    do {
        if (Map[r][c] == 0)
        {
            cleanedCellCount++;
            Map[r][c] = -1;
        }

        bool doesDirtyExists = false;
        for (int dirIndex = 0; dirIndex < 4; ++dirIndex)
        {
            doesDirtyExists |= Map[r + DirY[dirIndex]][c + DirX[dirIndex]] == 0;
        }

        int targetX = c;
        int targetY = r;
        if (!doesDirtyExists)
        {
            targetX -= DirX[d];
            targetY -= DirY[d];

            if (isCoordOutOfRange(M, N, targetX, targetY))
            {
                continue;
            }

            if (Map[targetY][targetX] == 1)
            {
                break;
            }
        }
        else
        {
            --d;
            if (d < NORTH) { d = WEST; }
            
            targetX += DirX[d];
            targetY += DirY[d];

            if (isCoordOutOfRange(M, N, targetX, targetY) ||
                Map[targetY][targetX] != 0)
            {
                continue;
            }
        }

        c = targetX;
        r = targetY;
    } while (true);
    cout << cleanedCellCount << endl;
}