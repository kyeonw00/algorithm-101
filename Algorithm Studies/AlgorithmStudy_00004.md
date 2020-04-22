# Algorithm Study #5

## Problem title: **Tower**

## Problem description
수평 직선에 탑 N대를 세웠습니다. 모든 탑의 꼭대기에는 신호를 송/수신하는 장치를 설치했습니다. 발사한 신호는 신호를 보낸 탑보다 높은 탑에서만 수신합니다. 또한, 한 번 수신된 신호는 다른 탑으로 송신되지 않습니다.

예를 들어 높이가 6, 9, 5, 7, 4인 다섯 탑이 왼쪽으로 동시에 레이저 신호를 발사합니다. 그러면, 탑은 다음과 같이 신호를 주고받습니다. 높이가 4인 다섯 번째 탑에서 발사한 신호는 높이가 7인 네 번째 탑이 수신하고, 높이가 7인 네 번째 탑의 신호는 높이가 9인 두 번째 탑이, 높이가 5인 세 번째 탑의 신호도 높이가 9인 두 번째 탑이 수신합니다. 높이가 9인 두 번째 탑과 높이가 6인 첫 번째 탑이 보낸 레이저 신호는 어떤 탑에서도 수신할 수 없습니다.

맨 왼쪽부터 순서대로 탑의 높이를 담은 배열 heights가 매개변수로 주어질 때 각 탑이 쏜 신호를 어느 탑에서 받았는지 기록한 배열을 return 하도록 solution 함수를 작성해주세요.

**Limitation**  
- heights는 길이 2 이상 100 이하인 정수 배열입니다.
- 모든 탑의 높이는 1 이상 100 이하입니다.
- 신호를 수신하는 탑이 없으면 0으로 표시합니다.
***

## Problem solving process

문제의 카테고리가 Queue/Stack을 이용해서 푸는 문제라 Stack을 이용해서 풀었습니다.

오랜만에 Stack과 Queue를 사용해봐서 단계적으로 생각해봤습니다.

1. 현재 위치의 탑을 기준으로 왼쪽에 위치한 탑들의 ID를 Stack에 집어넣는다.
2. 1에서 만들어진 Stack의 요소를 현재 위치의 탑의 높이와 비교한다.
3. Stack의 요소에서 더 높은 높이의 탑이 있으면 바로 Loop를 탈출하고, 해당 탑의 Id를 ```answer```에 추가한다.

일단 모든 요소들에 대해서 송신할 대상 탑의 Id를 찾아야 해서 모든 요소들을 순회합니다.

``` cpp
for (int i = 0; i < heights.size(); i++) {
    ...
}
```

그리고 지금 위치의 탑을 기준으로 비교할 대상들을 Stack에 추가했습니다.

``` cpp
stack<int> compStack;

for (int j = 0; j <= i; j++) {
    compStack.push(j);
}
```

현재 위치의 탑 Id와 결과적으로 지정될 대상 탑의 Id를 구분하기 위해 ```resultId```라는 정수형 변수를 하나 더 추가해줬습니다.

```compStack```이 비어있는 상태까지 순회합니다. 순회 중 현재 위치의 타워보다 높은 타워가 있으면 ```resultId```에 Id를 저장합니다.

``` cpp
while (!compStack.empty()) {
    int compId = compStack.top();
    compStack.pop();
    if (heights[compId] > heights[i]) {
        resultId = compId;
        break;
    }
}
```

어차피 앞의 loop문에서 같은 높이의 탑은 걸러지기 때문에 결과로 나온 ```resultId```와 현재 위치의 탑의 Id가 같은지만 검사하고 결과값을 반환합니다.

``` cpp
if (resultId != i) {
    answer.push_back(resultId + 1);
}
else {
    answer.push_back(0);
}
```

***

완성된 코드입니다.

``` cpp
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    
    for (int i = 0; i < heights.size(); i++) {
        stack<int> compStack;
        int resultId = i;

        for (int j = 0; j <= i; j++) {
            compStack.push(j);
        }

        while (!compStack.empty()) {
            int compId = compStack.top();
            compStack.pop();

            if (heights[compId] > heights[i]) {
                resultId = compId;
                break;
            }
        }
        
        if (resultId != i) {
            answer.push_back(resultId + 1);
        }
        else {
            answer.push_back(0);
        }
    }

    return answer;
}
```

