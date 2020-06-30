# Algorithm Study #23

## 2 * n 타일링

2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.

![image](Images/algorithmStudy_23_image_0.png)

#### 입력

첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

#### 출력

첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

### 문제 풀이

```n = 1```부터 쭉 나열해보면 패턴이 피보나치와 같습니다.
즉 ```f(n) = f(n - 1) + f(n - 2)```가 답입니다.

``` cpp
#include <iostream>

using namespace std;

int main() 
{
    int n;
    int dp[1000];

    dp[0] = 1;
    dp[1] = 2;
    cin >> n;

    for (int i = 2; i < n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

    cout << dp[n - 1];
    return 0;
}
```