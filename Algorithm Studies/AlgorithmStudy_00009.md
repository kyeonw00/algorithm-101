# Algorithm Study #10

## Problem title: **Stock Price**

## Problem description

초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때, 가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 solution 함수를 완성하세요.

**Limitation**  
- prices의 각 가격은 1 이상 10,000 이하인 자연수입니다.
- prices의 길이는 2 이상 100,000 이하입니다.

***

## Problem solving process

테스트용 입출력 값을 계산해보면서 알아낸 부분이 있습니다. 가격이 1초 뒤에 하락한다 하더라도, 1초동안 가격이 유지된다고 보는것 같더군요. 그래서 해당 부분까지 커버 할 수 있는 코드를 작성했습니다.

딱히 ```Stack```, ```Queue```를 쓰지 않아도 풀 수 있는 문제였습니다.

일단 초당 가격 변동을 알아야 하기 때문에 매개변수로 주어진 ```pirces```를 순회하며 가격이 떨어진 지점까지 순회합니다.

``` cpp
for (int i = 0; i < prices.size(); i++) {
}
```

각 지점에 대해서 가격이 떨어지는 지점까지 확인하는 코드입니다.

``` cpp
for (int r = i + 1; r < prices.size(); r++) {
if (prices[i] > prices[r]) {
    answer[i] = r - i;
    break;
}
```

예외적으로 가장 마지막 시점에서는 가격이 떨어지지 않았지만, 마감 전 1초 동안이라도 가격이 유지된 것으로 간주하고, 시간을 계산합니다.

``` cpp
if (r == (prices.size() - 1)) {
    answer[i] = r - i;
}
```

***

완성된 코드입니다.

``` cpp
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for (int i = 0; i < prices.size(); i++) {
        for (int r = i + 1; r < prices.size(); r++) {
            if (prices[i] > prices[r]) {
                answer[i] = r - i;
                break;
            }
            
            if (r == (prices.size() - 1)) {
                answer[i] = r - i;
            }
        }
    }
    
    return answer;
}
```