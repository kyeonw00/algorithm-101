# Algorithm Study #3

## Problem title: **Disguise**

## Problem description
스파이들은 매일 다른 옷을 조합하여 입어 자신을 위장합니다.

예를 들어 스파이가 가진 옷이 아래와 같고 오늘 스파이가 동그란 안경, 긴 코트, 파란색 티셔츠를 입었다면 다음날은 청바지를 추가로 입거나 동그란 안경 대신 검정 선글라스를 착용하거나 해야 합니다.

스파이가 가진 의상들이 담긴 2차원 배열 clothes가 주어질 때 서로 다른 옷의 조합의 수를 return 하도록 solution 함수를 작성해주세요.

**Limitation**  
- clothes의 각 행은 [의상의 이름, 의상의 종류]로 이루어져 있습니다.
- 스파이가 가진 의상의 수는 1개 이상 30개 이하입니다.
- 같은 이름을 가진 의상은 존재하지 않습니다.
- clothes의 모든 원소는 문자열로 이루어져 있습니다.
- 모든 문자열의 길이는 1 이상 20 이하인 자연수이고 알파벳 소문자 또는 '_' 로만 이루어져 있습니다.
- 스파이는 하루에 최소 한 개의 의상은 입습니다.

***

## Problem solving process

문제의 카테고리가 Hash로 분류 되어있어서, 옷들을 Category 별로 Map에 저장하고, 옷을 입을 수 있는 가지 수를 계산하는 방식으로 해결했습니다.

(Category A를 입는 가지수) * (Category B를 입는 가지수) * (Category C를 입는 가지수) * ...

각 Category의 옷을 입지 않는 경우와, 모든 카테고리의 옷을 입지 않는 경우까지 생각을 해야합니다. 그래서

```(Category A + 1) * (Category B + 1) * (Category C + 1) * .... - 1```의 결과값이 조건에 맞는 조건의 수 입니다.

***

완성된 코드입니다.

``` cpp
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> clothesMap;
    
    for (vector<string> element : clothes) {
        clothesMap[element[1]]++;
    }
    
    for (auto count : clothesMap) {
        answer *= (count.second + 1);
    }
    
    return answer - 1;
}
```

먼저, 옷의 카테고리 별로 옷의 수를 계산합니다. ```clothesMap```이라는 ```unordered_map``` 타입 변수에 카테고리 별로 옷의 개수를 계산합니다.

``` cpp
for (vector<string> element : clothes) {
    clothesMap[element[1]]++;
}
```

```(각 카테고리의 옷의 개수) + (해당 카테고리의 옷을 입지 않는 경우의 수)```가 해당 카테고리에 대한 경우의 수입니다. ```answer```에 모든 카테고리에 속하는 ```(옷의 개수) + 1```을 곱해줍니다.

``` cpp
for (auto count : clothesMap) {
    answer *= (count.second + 1);
}
```

마지막으로 모든 카테고리의 옷을 입지 않는 경우도 있기 때문에 마지막으로 해당 경우를 빼줍니다.

``` cpp
return answer - 1;
```