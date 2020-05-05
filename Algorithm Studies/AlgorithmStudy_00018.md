# Algorithm Study #19

## Problem title: **Number of 124**

## Problem description

124 나라가 있습니다. 124 나라에서는 10진법이 아닌 다음과 같은 자신들만의 규칙으로 수를 표현합니다.

1. 124 나라에는 자연수만 존재합니다.
2. 124 나라에는 모든 수를 표현할 때 1, 2, 4만 사용합니다.

자연수 n이 매개변수로 주어질 때, n을 124 나라에서 사용하는 숫자로 바꾼 값을 return 하도록 solution 함수를 완성해 주세요.

**Limitation**
- n은 500,000,000이하의 자연수 입니다.

***

## Problem solving process

3진법이라 생각하고 풀었습니다. 주어진 수 ```n```을 3으로 나누고 난 나머지를 반환할 문자열 ```answer```에 추가했습니다.

완성된 코드입니다.
``` cpp
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int remain;

    while (n > 0) {
        remain = n % 3;
        n = n / 3;

        if (remain == 0) {
            n--;
            remain = 4;
        }

        answer.insert(0, to_string(remain));
    }

    return answer;
}
```