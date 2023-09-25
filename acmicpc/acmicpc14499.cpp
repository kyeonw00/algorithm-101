#include <iostream>
#define dice_up_plane_index 0
#define dice_bottom_plane_index 5
#define east 1
#define west 2
#define north 3
#define south 4

using namespace std;

int N, M, X, Y, K;
int MAP[20][20];
int DICE_MAP[6];

void process_command(int command)
{
    int temp = DICE_MAP[0];
    switch (command)
    {
        case east:
            if (X == M - 1) { return; }

            X++;
            DICE_MAP[0] = DICE_MAP[3];
            DICE_MAP[3] = DICE_MAP[5];
            DICE_MAP[5] = DICE_MAP[2];
            DICE_MAP[2] = temp;
            break;
        case west:
            if (X == 0) { return; }

            X--;
            DICE_MAP[0] = DICE_MAP[2];
            DICE_MAP[2] = DICE_MAP[5];
            DICE_MAP[5] = DICE_MAP[3];
            DICE_MAP[3] = temp;
            break;
        case north:
            if (Y == 0) { return; }

            Y--;
            DICE_MAP[0] = DICE_MAP[4];
            DICE_MAP[4] = DICE_MAP[5];
            DICE_MAP[5] = DICE_MAP[1];
            DICE_MAP[1] = temp;
            break;
        case south:
            if (Y == N - 1) { return; }

            Y++;
            DICE_MAP[0] = DICE_MAP[1];
            DICE_MAP[1] = DICE_MAP[5];
            DICE_MAP[5] = DICE_MAP[4];
            DICE_MAP[4] = temp;
            break;
    }

    if (MAP[Y][X] == 0)
    {
        MAP[Y][X] = DICE_MAP[dice_bottom_plane_index];
    }
    else
    {
        DICE_MAP[dice_bottom_plane_index] = MAP[Y][X];
        MAP[Y][X] = 0;
    }

    cout << DICE_MAP[dice_up_plane_index] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> X >> Y >> K;

    for (int n = 0; n < N; ++n)
    {
        for (int m = 0; m < M; ++m)
        {
            cin >> MAP[n][m];
        }
    }

    for (int k = 0, command = 0; k < K; ++k)
    {
        cin >> command;
        process_command(command);
    }
}