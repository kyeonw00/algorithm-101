# Algorithm Study #9

## Problem title: **Iron Stick**

## Problem description

여러 개의 쇠막대기를 레이저로 절단하려고 합니다. 효율적인 작업을 위해서 쇠막대기를 아래에서 위로 겹쳐 놓고, 레이저를 위에서 수직으로 발사하여 쇠막대기들을 자릅니다. 쇠막대기와 레이저의 배치는 다음 조건을 만족합니다.

- 쇠막대기는 자신보다 긴 쇠막대기 위에만 놓일 수 있습니다.
- 쇠막대기를 다른 쇠막대기 위에 놓는 경우 완전히 포함되도록 놓되, 끝점은 겹치지 않도록 놓습니다.
- 각 쇠막대기를 자르는 레이저는 적어도 하나 존재합니다.
- 레이저는 어떤 쇠막대기의 양 끝점과도 겹치지 않습니다.

아래 그림은 위 조건을 만족하는 예를 보여줍니다. 수평으로 그려진 굵은 실선은 쇠막대기이고, 점은 레이저의 위치, 수직으로 그려진 점선 화살표는 레이저의 발사 방향입니다.

![sampleImage_00](/Images/algorithmStudy_8_image_0.png)

이러한 레이저와 쇠막대기의 배치는 다음과 같이 괄호를 이용하여 왼쪽부터 순서대로 표현할 수 있습니다.

> (a) 레이저는 여는 괄호와 닫는 괄호의 인접한 쌍 '()'으로 표현합니다. 또한 모든 '()'는 반드시 레이저를 표현합니다.  
> (b) 쇠막대기의 왼쪽 끝은 여는 괄호 '('로, 오른쪽 끝은 닫힌 괄호 ')'로 표현됩니다.

위 예의 괄호 표현은 그림 위에 주어져 있습니다.
쇠막대기는 레이저에 의해 몇 개의 조각으로 잘리는데, 위 예에서 가장 위에 있는 두 개의 쇠막대기는 각각 3개와 2개의 조각으로 잘리고, 이와 같은 방식으로 주어진 쇠막대기들은 총 17개의 조각으로 잘립니다.

쇠막대기와 레이저의 배치를 표현한 문자열 arrangement가 매개변수로 주어질 때, 잘린 쇠막대기 조각의 총 개수를 return 하도록 solution 함수를 작성해주세요.

**Limitation**  
- arrangement의 길이는 최대 100,000입니다.
- arrangement의 여는 괄호와 닫는 괄호는 항상 쌍을 이룹니다.

***

## Problem solving process

문제의 분류가 Stack/Queue로 분류되어 있었는데, 굳이 Stack과 Queue를 쓰지 않아도 풀 수 있을 것 같아서 일단 없이 풀어봤습니다.

일단 현재 몇개의 쇠 막대가 쌓여있는지 표시하는 변수 ```currentStackedStick```을 선언했습니다.

``` cpp
int currentStackedStick = 0;
```

일단 매개변수 ```arrangement```를 순회합니다.

``` cpp
for (int i = 0; i < arrangement.size(); i++) {
    ...
}
```

일단 (와 )가 서로 붙어있는 경우, 즉 ()일 경우에는 무조건 레이저를 표현한다는 조건이 있었으니, 문자열을 순회하는 중 (이 나오는 경우에는 바로 다음에 )가 나오는지 확인합니다.

``` cpp
if (arrangement.at(i) == '(' && arrangement.at(i + 1) == ')') {
    answer += currentStackedStick;
    i++;
}
```

만약에 ()가 아닌 경우에는 다음과 같이 처리해줍니다.
> a. (가 나올 경우에는 ```currentStackedStick```에 1을 추가합니다.
> b. )가 나올 경우에는 ```currentStackedStick```에서 1을 빼고, ```answer```에 1을 추가합니다.

``` cpp
if (arrangement.at(i) == '(') {
    currentStackedStick++;
}
else {
    answer++;
    currentStackedStick--;
}
```

***

완성된 코드입니다.

``` cpp
#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int currentStackedStick = 0;

    for (int i = 0; i < arrangement.size(); i++) {
        if (arrangement.at(i) == '(' && arrangement.at(i + 1) == ')') {
            answer += currentStackedStick;
            i++;
        }
        else {
            if (arrangement.at(i) == '(') {
                currentStackedStick++;
            }
            else {
                answer++;
                currentStackedStick--;
            }
        }
    }

    return answer;
}
```