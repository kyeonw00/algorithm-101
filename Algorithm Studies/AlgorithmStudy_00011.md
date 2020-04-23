# Algorithm Study #11

## Problem title: **Instant Noodle Factory**

## Problem description

라면 공장에서는 하루에 밀가루를 1톤씩 사용합니다. 원래 밀가루를 공급받던 공장의 고장으로 앞으로 k일 이후에야 밀가루를 공급받을 수 있기 때문에 해외 공장에서 밀가루를 수입해야 합니다.

해외 공장에서는 향후 밀가루를 공급할 수 있는 날짜와 수량을 알려주었고, 라면 공장에서는 운송비를 줄이기 위해 최소한의 횟수로 밀가루를 공급받고 싶습니다.

현재 공장에 남아있는 밀가루 수량 stock, 밀가루 공급 일정(dates)과 해당 시점에 공급 가능한 밀가루 수량(supplies), 원래 공장으로부터 공급받을 수 있는 시점 k가 주어질 때, 밀가루가 떨어지지 않고 공장을 운영하기 위해서 최소한 몇 번 해외 공장으로부터 밀가루를 공급받아야 하는지를 return 하도록 solution 함수를 완성하세요.

dates[i]에는 i번째 공급 가능일이 들어있으며, supplies[i]에는 dates[i] 날짜에 공급 가능한 밀가루 수량이 들어 있습니다.

**Limitation**  
- stock에 있는 밀가루는 오늘(0일 이후)부터 사용됩니다.
- stock과 k는 2 이상 100,000 이하입니다.
- dates의 각 원소는 1 이상 k 이하입니다.
- supplies의 각 원소는 1 이상 1,000 이하입니다.
- dates와 supplies의 길이는 1 이상 20,000 이하입니다.
- k일 째에는 밀가루가 충분히 공급되기 때문에 k-1일에 사용할 수량까지만 확보하면 됩니다.
- dates에 들어있는 날짜는 오름차순 정렬되어 있습니다.
- dates에 들어있는 날짜에 공급되는 밀가루는 작업 시작 전 새벽에 공급되는 것을 기준으로 합니다. 예를 들어 9일째에 밀가루가 바닥나더라도, 10일째에 공급받으면 10일째에는 공장을 운영할 수 있습니다.
- 밀가루가 바닥나는 경우는 주어지지 않습니다.

***

## Problem solving process

기본적으로 다음의 계산식을 고려하고 문제를 풀었습니다.

> (현재 보유중인 재고) + (해외에서 받아올 재고) < k

그리고 해외에서 받아올 재고는 원래 공장으로부터 공급받을 수 있는 시점 ```k```보다 더 많은 양이어야합니다. 해외 공장에서 밀가루를 최소한의 횟수로 받아야하니 시간내에 가장 많이 받을 수 있는 양을 찾아야합니다.

어차피 재고를 채울 수 있는 시점과 양은 오름차순으로 정리되어있으니, ```lastPushedId```라는 정수형 변수를 하나 만들어 현재 순회한 위치의 인덱스를 저장합니다.

``` cpp
int lastPushedId = 0;
```

그리고 현재 받아 올 수 있는 밀가루의 수량을 저장하는 ```suppliesRef```를 선언했습니다.

``` cpp
priority_queue<int, vector<int>, less<int>> suppliesRef;
```

가능한 시점에 가장 많은 양을 받아와야해서, 내림차순으로 정렬하게 했습니다.
그리고 현재 보유량이 보급이 가능한 날까지 유지할 수 있을 때까지 해외 공장에서 재고를 받아오도록 순회합니다.

``` cpp
while (stock < k) {
    ...
}
```

일단 현재 받아올 수 있는 재고량을 모두 ```suppliesRef```에 추가합니다.
``` cpp
for (int i = lastPushedId; i < dates.size() && stock >= dates[i]; i++) {
    suppliesRef.push(supplies[i]);
    lastPushedId = i + 1;
}
```

그리고 현재 받아올 수 있는 재고량 중 가장 많은 양의 재고를 가져옵니다.
``` cpp
stock += suppliesRef.top();
suppliesRef.pop();
answer++;
```


***

완성된 코드입니다.

``` cpp
#include <vector>
#include <queue>
#include <string>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int lastPushedId = 0;
    priority_queue<int, vector<int>, less<int>> suppliesRef;
    
    while (stock < k) {
        for (int i = lastPushedId; i < dates.size() && stock >= dates[i]; i++) {
            suppliesRef.push(supplies[i]);
            lastPushedId = i + 1;
        }
        
        stock += suppliesRef.top();
        suppliesRef.pop();
        answer++;
    }

    return answer;
}
```