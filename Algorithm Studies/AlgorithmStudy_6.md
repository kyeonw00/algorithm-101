# Algorithm Study #6

## Problem title: **Syntax development**

## Problem description
프로그래머스 팀에서는 기능 개선 작업을 수행 중입니다. 각 기능은 진도가 100%일 때 서비스에 반영할 수 있습니다.

또, 각 기능의 개발속도는 모두 다르기 때문에 뒤에 있는 기능이 앞에 있는 기능보다 먼저 개발될 수 있고, 이때 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포됩니다.

먼저 배포되어야 하는 순서대로 작업의 진도가 적힌 정수 배열 progresses와 각 작업의 개발 속도가 적힌 정수 배열 speeds가 주어질 때 각 배포마다 몇 개의 기능이 배포되는지를 return 하도록 solution 함수를 완성하세요.

**Limitation**  
- 작업의 개수(progresses, speeds배열의 길이)는 100개 이하입니다.
- 작업 진도는 100 미만의 자연수입니다.
- 작업 속도는 100 이하의 자연수입니다.
- 배포는 하루에 한 번만 할 수 있으며, 하루의 끝에 이루어진다고 가정합니다. 예를 들어 진도율이 95%인 작업의 개발 속도가 하루에 4%라면 배포는 2일 뒤에 이루어집니다.

***

## Problem solving process

앞서 풀었던 트럭 문제처럼 queue에 먼저 매개 변수로 주어진 ```progresses```를 삽입하고 해당 작업이 끝나는 시간을 계산해서 각 배포마다 몇가지 기능이 배포되는지 계산했습니다.

```requiredTime```이라는 queue를 생성하고, 해당 queue에 각 기능마다 남은 작업량을 계산하여 삽입했습니다.
``` cpp
queue<int> requiredTime;

for (int i = 0; i < progresses.size(); i++)
{
    int remainProgress = 100 - progresses[i];
    int time = remainProgress / speeds[i];
    if (remainProgress % speeds[i] > 0)
    {
        time++;
    }
    requiredTime.push(time);
}
```

앞에서 만들어진 queue를 순회합니다.
``` cpp
while (!requiredTime.empty())
{
    int scheduled = 0;
    int longest = -1;
    while (!requiredTime.empty())
    {
        if (longest == -1)
        {
            longest = requiredTime.front();
            scheduled++;
            requiredTime.pop();
        }
        else if (longest >= requiredTime.front())
        {
            scheduled++;
            requiredTime.pop();
        }
        else {
            break;
        }
    }
    answer.push_back(scheduled);
}
```
현재 위치의 작업이 앞서 배포 예정으로 간주된 작업보다 남은 작업 기간이 더 길다면, loop문을 탈출하고 현재까지 배포 예정으로 간주된 기능들의 개수를 반환할 ```answer```에 추가합니다.

***

완성된 코드입니다.

``` cpp
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<int> requiredTime;

    for (int i = 0; i < progresses.size(); i++)
    {
        int remainProgress = 100 - progresses[i];
        int time = remainProgress / speeds[i];

        if (remainProgress % speeds[i] > 0)
        {
            time++;
        }

        requiredTime.push(time);
    }

    while (!requiredTime.empty())
    {
        int scheduled = 0;
        int longest = -1;
        while (!requiredTime.empty())
        {
            if (longest == -1)
            {
                longest = requiredTime.front();
                scheduled++;
                requiredTime.pop();
            }
            else if (longest >= requiredTime.front())
            {
                scheduled++;
                requiredTime.pop();
            }
            else {
                break;
            }
        }
        answer.push_back(scheduled);
    }

    return answer;
}
```