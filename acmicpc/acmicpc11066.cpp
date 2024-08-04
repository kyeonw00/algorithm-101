#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_FILE_COUNT = 501;
const int MAX_FILE_SIZE = 10000;
const int INTEGER_MAX = 1000000000;

int main()
{
    int T;
    cin >> T;

    int FileSizes[MAX_FILE_COUNT];
    int FileSumCache[MAX_FILE_COUNT] = { 0 };
    int MergedFileSum[MAX_FILE_COUNT][MAX_FILE_COUNT] = { 0 };

    for (int t = 0; t < T; ++t) {
        int K;
        cin >> K;

        for (int k = 1; k <= K; ++k) {
            cin >> FileSizes[k];
            FileSumCache[k] = FileSumCache[k - 1] + FileSizes[k];
        }

        for (int i = 1; i < K; ++i) {
            for (int j = 1; j <= K - i; ++j) {
                MergedFileSum[j][j + i] = INTEGER_MAX;
                for (int k = j; k < i + j; ++k) {
                    MergedFileSum[j][j + i] =
                        min(
                            MergedFileSum[j][j + i],
                            MergedFileSum[j][k] + MergedFileSum[k + 1][j + i] + FileSumCache[j + i] - FileSumCache[j - 1]);
                }
            }
        }

        cout << MergedFileSum[1][K] << endl;
    }
}