# Algorithm Study #26

## 정수 삼각형

맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라. 아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.

삼각형의 크기는 1 이상 500 이하이다. 삼각형을 이루고 있는 각 수는 모두 정수이며, 범위는 0 이상 9999 이하이다.

#### 입력

첫째 줄에 삼각형의 크기 n(1 ≤ n ≤ 500)이 주어지고, 둘째 줄부터 n+1번째 줄까지 정수 삼각형이 주어진다.

#### 출력

첫째 줄에 합이 최대가 되는 경로에 있는 수의 합을 출력한다.

### 문제 풀이

크기가 ```n```인 삼각형에서 쭉 내려가면서 합을 구해나가면서 가장 큰 수를 구했습니다.
가장자리를 제외하고는 바로 위의 층의 왼/오른쪽 요소값을 현재 위치의 요소값과 더해서 더 큰 값을 구하도록 했습니다.

``` cpp
#include <iostream>

using namespace std;

int dp[500][500];

int Bigger(int a, int b) { return a > b ? a : b; }

int main() {
    int n, answer = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int r = 0; r <= i; r++) {
            cin >> dp[i][r];
        }
    }

    for (int i = 0; i < n ; i++) {
        for (int r = 0; r <= i; r++) {
            if (r == 0)
                dp[i][r] = dp[i - 1][0] + dp[i][r];
            else if (r == i)
                dp[i][r] = dp[i - 1][r - 1] + dp[i][r];
            else
                dp[i][r] = Bigger(dp[i - 1][r - 1] + dp[i][r], dp[i-1][r] + dp[i][r]);

            answer = Bigger(max, dp[i][r]);
        }
    }

    cout << answer;
    
    return 0;
}
```