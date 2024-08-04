#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int MAX_PEOPLE = 20;

void dfs(
    int S[MAX_PEOPLE][MAX_PEOPLE],
    bool isVisited[MAX_PEOPLE],
    const int n,
    int numTeammates,
    int searchPos,
    int& answer)
{
    if (numTeammates == n / 2) {
        int teamA = 0, teamB = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isVisited[i] && isVisited[j]) teamA += S[i][j];
                else if (!isVisited[i] && !isVisited[j]) teamB += S[i][j];
            }
        }

        int diff = abs(teamA - teamB);
        if (answer > diff) answer = diff;
        return;
    }

    for (int i = searchPos; i < n; i++) {
        if (!isVisited[i]) {
            isVisited[i] = true;
            dfs(S, isVisited, n, numTeammates + 1, i + 1, answer);
            isVisited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int S[MAX_PEOPLE][MAX_PEOPLE];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }

    bool isVisited[MAX_PEOPLE];
    memset(isVisited, false, sizeof(isVisited));

    int answer = 100000000;
    dfs(S, isVisited, N, 0, 0, answer);
    cout << answer << '\n';
}