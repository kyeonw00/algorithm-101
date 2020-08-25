# Algorithm Study #34

## 어린 왕자

어린 왕자는 소혹성 B-664에서 자신이 사랑하는 한 송이 장미를 위해 살아간다. 어느 날 장미가 위험에 빠지게 된 것을 알게 된 어린 왕자는, 장미를 구하기 위해 은하수를 따라 긴 여행을 하기 시작했다. 하지만 어린 왕자의 우주선은 그렇게 좋지 않아서 행성계 간의 이동을 최대한 피해서 여행해야 한다. 아래의 그림은 어린 왕자가 펼쳐본 은하수 지도의 일부이다.

![image](Images/algorithmStudy_34_0.gif)

빨간 실선은 어린 왕자가 출발점에서 도착점까지 도달하는데 있어서 필요한 행성계 진입/이탈 횟수를 최소화하는 경로이며, 원은 행성계의 경계를 의미한다. 이러한 경로는 여러 개 존재할 수 있지만 적어도 3번의 행성계 진입/이탈이 필요하다는 것을 알 수 있다.

위와 같은 은하수 지도, 출발점, 도착점이 주어졌을 때 어린 왕자에게 필요한 최소의 행성계 진입/이탈 횟수를 구하는 프로그램을 작성해 보자. (행성계의 경계가 맞닿거나 서로 교차하는 경우는 없다고 가정한다. 또한, 출발점이나 도착점이 행성계 경계에 걸쳐진 경우 역시 입력으로 주어지지 않는다.)

#### 입력

입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다. 그 다음 줄부터 각각의 테스트케이스에 대해 첫째 줄에 출발점 (x1, y1)과 도착점 (x2, y2)이 주어진다. 두 번째 줄에는 행성계의 개수 n이 주어지며, 세 번째 줄부터 n줄에 걸쳐 행성계의 중점과 반지름 (cx, cy, r)이 주어진다. 입력제한은 다음과 같다. (-1000 ≤ x1, y1, x2, y2, cx, cy ≤ 1000, 1 ≤ r ≤ 1000, 1 ≤ n ≤ 50)

좌표와 반지름은 모두 정수이다.

#### 출력

각 테스트 케이스에 대해 어린 왕자가 거쳐야 할 최소의 행성계 진입/이탈 횟수를 출력한다.

### 문제 풀이

문제를 보니까 뭔가 어려워서 다른 분들이 올려놓은 풀이들을 참고하면서 풀었습니다. 막상 보고나니까 제한 사항에 어렵다고 생각했던 것들은 가정하지 않는다고 적혀있어서 쉽게 풀었습니다.

문제의 제한사항에 다음과 같았습니다:
- 행성계의 경계들은 서로 맞닿지 않는다
- 행성계의 경계가 서로 교차하지 않는다고 가정한다.
- 출발점이나 도착점이 행성계의 경계선에 걸쳐지지 않는다.

위와 같은 제한사항이 있다면, 단순히 도착점과 출발점이 각 행성계의 경계 밖에 위치하는지만 확인하면 됩니다. 가장 짧은 경로로 가는게 아니라, 멀리 돌아가더라도 가장 적게 행성계의 경계를 지나면 되니까요.

그래서 도착점과 시작점이 입력된 행성계의 위치까지의 거리가 행성계의 반지름보다 긴지를 확인해서 답을 도출했습니다.

``` cpp
#include <iostream>

using namespace std;

int magnitude(int x, int y, int tx, int ty) { return (x - tx) * (x - tx) + (y - ty) * (y - ty); }

int main() {
    int t, n;
    int x, y, r;
    int answer, count;
    int x1, y1, x2, y2;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        answer = 0;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &n);
        
        for (int j = 0; j < n; j++) {
            count = 0;
            scanf("%d %d %d", &x, &y, &r);
            
            if (magnitude(x, y, x1, y1) < r * r)
                count++;
            
            if (magnitude(x, y, x2, y2) < r * r)
                count++;
                
            if (count == 1)
                answer++;
        }
        
        printf("%d\n", answer);
    }
}
```