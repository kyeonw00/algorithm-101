# Algorithm Study #2

## Problem title: **Phone Book Problem**

## Problem description
전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.
전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.

전화번호부에 적힌 전화번호를 담은 배열 phone_book 이 solution 함수의 매개변수로 주어질 때, 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 return 하도록 solution 함수를 작성해주세요.

**Limitation**  
phone_book의 길이는 1 이상 1,000,000 이하입니다.
각 전화번호의 길이는 1 이상 20 이하입니다.

***

## Problem solving process
이 문제도 정렬 또는 헤시 셋으로 해결 할 수 있을 것 같아 두가지 방법 모두 시도 해보았습니다.

> 물론 문제의 카테고리가 헤시로 되어있었으니, 아무래도 헤시로 푸는게 정답이 아닐까 생각됩니다.

***
**정렬을 이용하여 해결하는 방법**

``` cpp
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    return answer;
}
```

먼저, ```sort```를 이용하여 매개변수 ```phone_book```을 정렬시켜 주었습니다.

``` cpp
sort(phone_book.begin(), phone_book.end());
```


이 때, 숫자 정렬이 아닌 사전 순 정렬로 처리 되기 때문에, 현재 비교할 element의 다음 인덱스의 element들만 비교해주면 됩니다.

그리고 배열 ```phone_book```을 순회하며 현재 위치의 배열 요소가 바로 다음 배열 요소의 접두어인지 확인합니다.

``` cpp
for (int i = 0; i < phone_book.size() - 1; i++) {
    if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size())) {
        answer = false;
        break;
    }
}
```

최종 코드는 다음과 같습니다.

``` cpp
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size())) {
            answer = false;
            break;
        }
    }

    return answer;
}
```
***
**해시 맵을 이용하여 해결하는 방법**

기본 코드는 앞의 정렬을 이용한 풀이 방법의 코드와 같습니다.
``` cpp
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    return answer;
}
```

비교를 위한 헤시 맵을 하나 만들어 줍니다.
``` cpp
unordred_map<string, int> comparisonMap;
```

비교를 위하여 ```phone_book```의 배열 요소들로 ```comparisonMap```을 초기화 시켜줍니다.
``` cpp
for (auto element : phone_book) {
    comparisonMap.insert(make_pair(element, 1));
}
```

```phone_book```의 요소들을 순회하면서 비교를 합니다. 현재 위치의 전화 번호를 앞에서 부터 잘라서 또 하나의 번호를 만들어서 해당 번호가 앞의 ```comparisonMap```에 포함되어 있는지 확인 할겁니다.

예를 들어, 현재 위치의 전화 번호가 ```4539```라면, {```4```, ```45```, ```453```, ```4539```} 이런식으로 비교를 했습니다.

``` cpp
for (auto element : phone_book) {
    string currentPhoneNumber = "";

    for (int i = 0; i < element.size(); i++) {
        currentPhoneNumber += element[i];

        if (comparisonMap[currentPhoneNumber] && currentPhoneNumber != element) {
            answer = false;
            break;
        }
    }
}
```
물론 현재 새로 만들어진 전화번호가 원본의 전화번호와 같지 않아야 하기 때문에 해당 부분에 대해서도 예외처리를 해주었습니다.

아래는 완성된 코드입니다.

``` cpp
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> comparisonMap;
    
    for (auto element : phone_book)
        comparisonMap.insert(make_pair(element, 1));

    for (auto element : phone_book) {
        string currentPhoneNumber = "";

        for (int i = 0; i < element.size(); i++) {
            currentPhoneNumber += element[i];

            if (comparisonMap[currentPhoneNumber] && currentPhoneNumber != element) {
                answer = false;
                break;
            }
        }
    }

    return answer;
}
```