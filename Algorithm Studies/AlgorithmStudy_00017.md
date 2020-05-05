# Algorithm Study #18

## Problem title: **H-Index**

## Problem description

H-Index는 과학자의 생산성과 영향력을 나타내는 지표입니다. 어느 과학자의 H-Index를 나타내는 값인 h를 구하려고 합니다. 위키백과1에 따르면, H-Index는 다음과 같이 구합니다.

어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고 나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 이 과학자의 H-Index입니다.

어떤 과학자가 발표한 논문의 인용 횟수를 담은 배열 citations가 매개변수로 주어질 때, 이 과학자의 H-Index를 return 하도록 solution 함수를 작성해주세요.

**Limitation**
- 과학자가 발표한 논문의 수는 1편 이상 1,000편 이하입니다.
- 논문별 인용 횟수는 0회 이상 10,000회 이하입니다.

***

## Problem solving process

문제에 대한 설명이 애매해서 풀기 어려웠던 문제였던것 같습니다. 나중에 풀면서 보니 H-Index는 주어진 ```citations```에 포함된 값과 같을 필요가 없었습니다.

먼저 임시로 h-index를 저장할 변수 ```h```를 선언하고, ```h```번 이상 인용된 논문의 갯수를 계산합니다.
``` cpp
int h = 0;
while (h <= citations.size()) {
    int count = 0;
    for (int i = 0; i < citations.size(); i++)
        if (citations[i] >= h) count++;

    ...
}
```

그리고 ```h```번 이상 인용된 논문의 개수가 ```h```이상인지, ```h```가 매개변수 ```citations```의 길이보다 작은지 확인합니다. 앞의 조건을 만족하고, 지금 나온 h-index가 앞서 계산된 h-index 보다 더 큰지 확인하고, 크다면 지금 나온 값을 h-index로 간주하도록 합니다.
``` cpp
if (count >= h && citations.size() - count <= h)
    answer = answer > h ? answer : h;
```

완성된 코드입니다.
``` cpp
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    int h = 0;
    while (h <= citations.size()) {
        int count = 0;
        for (int i = 0; i < citations.size(); i++)
            if (citations[i] >= h) count++;

        if (count >= h && citations.size() - count <= h)
            answer = answer > h ? answer : h;
        
        h++;
    }

    return answer;
}
```