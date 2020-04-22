# Algorithm Study #11

## Problem title: **Much Spicier**

## Problem description

매운 것을 좋아하는 Leo는 모든 음식의 스코빌 지수를 K 이상으로 만들고 싶습니다. 모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 Leo는 스코빌 지수가 가장 낮은 두 개의 음식을 아래와 같이 특별한 방법으로 섞어 새로운 음식을 만듭니다.

> 섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)

Leo는 모든 음식의 스코빌 지수가 K 이상이 될 때까지 반복하여 섞습니다.
Leo가 가진 음식의 스코빌 지수를 담은 배열 scoville과 원하는 스코빌 지수 K가 주어질 때, 모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 섞어야 하는 최소 횟수를 return 하도록 solution 함수를 작성해주세요.

**Limitation**  
- scoville의 길이는 2 이상 1,000,000 이하입니다.
- K는 0 이상 1,000,000,000 이하입니다.
- scoville의 원소는 각각 0 이상 1,000,000 이하입니다.
- 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우에는 -1을 return 합니다.

***

## Problem solving process

일단 처음에는 ```std::make_heap```을 이용해서 문제를 풀려했는데, 효율성 테스트에서 자꾸 실패로 떠서 ```priority_queue```를 이용해서 풀었습니다. 앞에서 풀었던 Printer 문제에서도 사용했었던 ```std```에 포함되어있는 타입입니다.

오름차순으로 정렬할 수 있는 ```priority_queue```인 ```heap```을 정의합니다.

```cpp
priority_queue<int, vector<int>, greater<int>> heap;

for (int e : scoville) heap.push(e);
```

```heap```을 순회하면서 매개변수 ```k```보다 스코빌 지수가 높은 메뉴를 만들기 위해 섞어야 하는 최소 횟수를 계산합니다.

더이상 조합을 생성 할 수 없거나, 이미 스코빌 지수가 ```k``` 이상인 메뉴를 만들었을 때까지 순회합니다.

``` cpp
while (heap.top() < k && heap.size() > 1) {
    answer++;
    newMenuScoville = heap.top();
    heap.pop();
    newMenuScoville += heap.top() * 2;
    heap.pop();
    heap.push(newMenuScoville);
}
```

순회를 마치고 나서 메뉴가 만들어졌는지 한번 더 확인하고 최소 횟수를 반환합니다.

``` cpp
return heap.top() < k ? -1 : answer;
```

***

완성된 코드입니다.

``` cpp
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int k) {
    int answer = 0;
    int newMenuScoville;
    priority_queue<int, vector<int>, greater<int>> heap;

    for (int e : scoville) heap.push(e);

    while (heap.top() < k && heap.size() > 1) {
        answer++;
        newMenuScoville = heap.top();
        heap.pop();
        newMenuScoville += heap.top() * 2;
        heap.pop();
        heap.push(newMenuScoville);
    }
    
    if (heap.top() < k) return -1;

    return answer;
}
```