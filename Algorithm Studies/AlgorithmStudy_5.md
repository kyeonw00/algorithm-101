# Algorithm Study #6

## Problem title: **Trucks passing the bridge**

## Problem description
트럭 여러 대가 강을 가로지르는 일 차선 다리를 정해진 순으로 건너려 합니다. 모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지 알아내야 합니다. 트럭은 1초에 1만큼 움직이며, 다리 길이는 bridge_length이고 다리는 무게 weight까지 견딥니다.
※ 트럭이 다리에 완전히 오르지 않은 경우, 이 트럭의 무게는 고려하지 않습니다.

```solution``` 함수의 매개변수로 다리 길이 ```bridge_length```, 다리가 견딜 수 있는 무게 ```weight```, 트럭별 무게 ```truck_weights```가 주어집니다. 이때 모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지 return 하도록 ```solution``` 함수를 완성하세요.

**Limitation**  
- bridge_length는 1 이상 10,000 이하입니다.
- weight는 1 이상 10,000 이하입니다.
- truck_weights의 길이는 1 이상 10,000 이하입니다.
- 모든 트럭의 무게는 1 이상 weight 이하입니다.

***

## Problem solving process

트럭들이 지나가는 과정을 ```queue```에 push/pop 시키면서 문제를 풀었습니다.

1. ```queue```에 현재 다리 위를 지나가는 트럭들의 무게를 고려하여 요소를 추가한다.
2. ```queue```의 사이즈가 다리의 길이보다 길어지면 pop시키고, 무게를 계산한다.
3. 위의 과정을 ```truck_weights```의 크기만큼 반복한다.

풀고나보니까 과정 자체는 그렇게 복잡하진 않았네요.

```bridge```라는 queue를 만들어 주었습니다. 현재 다리위의 상태를 나타내는 용도로 사용 할겁니다.
그리고 ```truck_weights```안에 있는 모든 트럭들이 다리를 지나갈거니 아래와 같이 loop문을 사용합니다.
``` cpp
for (int i = 0; i < truck_weights.size(); i++) {
    ...
}
```

그리고 앞의 loop문 안으로 loop를 하나 더 만들었습니다.
다리의 무게보다 트럭들의 무게가 더 커지면 ```queue```에 -1을 집어넣어서 빈 공간이 있다는 걸 표시할게요.
``` cpp
while(1) {
    ...
}
```

일단 시작했을 때에는 ```bridge```에는 아무것도 삽입이 되지 않았으니 해당 상황을 예외처리 시켰습니다.
마지막에 ```break```로 ```while(true)``` 구문을 탈출하는 건 트럭이 다리 위로 올라갔으니, 이동이 한 번 일어났다고 가정해야 하기 때문입니다.
``` cpp
if (bridge.empty()) {
    bridge.push(i);
    birdgeWeight += truck_weight[i];
    answer++;
    break;
}
```

그리고 다리의 끝에 다다른 상태, 즉 ```bridge```의 크기가 ```bridge_length```와 같아졌을 때를 고려해야 합니다.
가장 앞에 있는 요소를 pop 시켜줍니다.
``` cpp
else if (bridge.size() == bridge_length) {
    if (bridge.front() != -1) {
        bridgeWeight -= truck_weights[bridge.front()];
    }
    bridge.pop();
}
```
이 때는 loop를 탈출하면 안됩니다. 그 다음 트럭이 진입하는 경우 또는 무게 때문에 아무 트럭도 올라오지 않는 경우도 생각해줘야 하니까요.

마지막으로 이미 다리를 지나가고 있는 상태이고, ```bridge```의 크기가 ```bridge_length```보다 작을 때를 처리합니다.

먼저 이제 ```bridge```에 추가 될 트럭의 무게와 현재 다리 위의 트럭들의 무게를 서로 합하여 ```weight```가 넘지 않는지 확인합니다.
넘어간다면 -1, 넘어가지 않는다면 현재 올라갈 트럭을 ```bridge```에 추가합니다.
``` cpp
if (bridgeWeight + truck_weights[i] > weight) {
    bridge.push(-1);
    answer++;
}
else
{
    bridge.push(i);
    bridgeWeight += truck_weights[i];
    answer++;
    break;
}
```

마지막으로 전체 과정을 진행한 단계 수 (트럭이 다리를 지나가는데 걸린 총 소요 시간)에 다리의 길이 만큼 더해서 반환시킵니다.
다리의 길이를 ```answer```에 더하는 건, 반복문에서는 마지막으로 다리를 지나는 트럭이 다리를 지나는데 걸리는 시간을 고려하지 않아서 더해주는 겁니다.
``` cpp
return answer + bridge_length;
```

***

완성된 코드입니다.

``` cpp
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge;
    int bridgeWeight = 0;

    for (int i = 0; i < truck_weights.size(); i++) {
        while (1) {
            if (bridge.empty()) {
                bridge.push(i);
                bridgeWeight += truck_weights[i];
                answer++;
                break;
            }
            else if (bridge.size() == bridge_length) {
                if (bridge.front() != -1) {
                    bridgeWeight -= truck_weights[bridge.front()];
                }

                bridge.pop();
            }
            else {
                if (bridgeWeight + truck_weights[i] > weight) {
                    bridge.push(-1);
                    answer++;
                }
                else
                {
                    bridge.push(i);
                    bridgeWeight += truck_weights[i];
                    answer++;
                    break;
                }
            }
        }
    }

    return answer + bridge_length;
}
```