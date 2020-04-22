# Algorithm Study #1

## Problem title: **A marathon runner who didn't finished**

## Problem description
수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.

마라톤에 참여한 선수들의 이름이 담긴 배열 ```participant```와 완주한 선수들의 이름이 담긴 배열 ```completion```이 주어질 때, 완주하지 못한 선수의 이름을 반환하도록 ```solution``` 함수를 작성해주세요.

### Limitation
- 마라톤 경기에 참여한 선수의 수는 1명 이상 100,000명 이하입니다.
- ```completion```의 길이는 ```participant```의 길이보다 1작습니다.
- 참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.
- 참가자 중에는 동명이인이 있을 수 있습니다.

## Problem solving process
총 두가지의 방법으로 정리 할 수 있을 것 같습니다.
- 각각의 배열을 sorting 하여 두 배열의 element들이 1대1 매칭이 되는지 확인하는 방법
- Hash map을 생성하여, completion의 element와 participant의 element를 비교하는 방법

직관적으로 해결하기에는 전자의 sorting을 이용한 방법이 간단하다고 생각되지만, 해당 문제의 카테고리가 Hash로 분류되어있어 Hash로 해결 해보았습니다.

``` cpp
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution (vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> comparison;

    for (auto element : completion) {
        if (comparison.end() == comparison.find(element))
            comparison.insert(make_pair(element, 1));
        else
            comparison[element]++;
    }

    for (auto element : participant) {
        if (comparison.end() == comparison.find(element)) {
            answer = element;
            break;
        }
        else {
            comparison[element]--;
            if (comparison[element] <= -1) {
                answer = element;
                break;
            }
        }
    }

    return answer;
}
```

먼저, ```completion```과 ```participant``` 두 배열의 요소들을 비교하기 위한 Hash map을 하나 만들었습니다.
``` cpp
unordered_map<string, int> comparison;
```

다음으로는 ```comparison```에 완주한 선수들을 등록합니다.
``` cpp
for (auto element : completion) {
    if (comparison.end() == comparison.find(element))
        comparison.insert(make_pair(element, 1));
    else
        comparison[element]++;
}
```

마지막으로, 참가한 선수와 ```comparison```을 비교합니다. 비교하여, 선수의 수가 0보다 작거나, 등록되어 있지 않은 경우 루프문을 종료시키고, 해당 선수가 결승선을 통과하지 못했다고 반환시킵니다.
``` cpp
for (auto element : participant) {
    if (comparison.end() == comparison.find(element)) {
        answer = element;
        break;
    }
    else {
        comparison[element]--;
         if (comparison[element] <= -1) {
            answer = element;
            break;
        }
    }
}
```

제한 조건에 ```completion```의 길이는 ```participant```보다 1이 작다고 명시되었으므로, 이 이상의 예외 처리가 필요하지는 않을 것 같습니다.