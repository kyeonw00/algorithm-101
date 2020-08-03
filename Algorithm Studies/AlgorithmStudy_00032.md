# Algorithm Study #31

## 가장 긴 증가하는 부분 수열

수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {**10**, **20**, 10, **30**, 20, **50**} 이고, 길이는 4이다.

#### 입력

첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 A*i*가 주어진다. (1 ≤ A*i* ≤ 1,000)

#### 출력

첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

### 문제 풀이

배열 첫번째 요소부터 i번째까지 있는 요소들을 비교했습니다.

``` cpp
#include <iostream>

int dp[1001];
int arr[1001];

int main() {
    int n, temp;
    int answer = 0;
    dp[0] = 0;

    std::cin >> n;

    for (int i = 1; i <= n; i++)
        std::cin >> arr[i];

    for (int i = 1; i <= n; i++) {
        temp = 0;
        for (int r = 0; r < i; r++) {
            if (arr[i] > arr[r] && temp < dp[r])
                temp = dp[r];
        }

        dp[i] = ++temp;
        answer = dp[i] > answer ? dp[i] : answer;
    }

    std::cout << answer;

    return 0;
}
```