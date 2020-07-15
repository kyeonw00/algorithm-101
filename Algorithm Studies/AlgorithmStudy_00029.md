# Algorithm Study #28

요즘에 릴리즈 준비 때문에 문제는 풀고 있는데 문서를 못쓰고 있네요...
주말이나 아침 시간에도 문제 쓰는걸 고려해봐야 할 것 같습니다.

## 택시 기하학

19세기 독일 수학자 헤르만 민코프스키는 비유클리드 기하학 중 택시 기하학을 고안했다.

택시 기하학에서 두 점 T1(x1,y1), T2(x2,y2) 사이의 거리는 다음과 같이 구할 수 있다.

D(T1,T2) = |x1-x2| + |y1-y2|

두 점 사이의 거리를 제외한 나머지 정의는 유클리드 기하학에서의 정의와 같다.

따라서 택시 기하학에서 원의 정의는 유클리드 기하학에서 원의 정의와 같다.

원: 평면 상의 어떤 점에서 거리가 일정한 점들의 집합

반지름 R이 주어졌을 때, 유클리드 기하학에서 원의 넓이와, 택시 기하학에서 원의 넓이를 구하는 프로그램을 작성하시오.

#### 입력

첫째 줄에 반지름 R이 주어진다. R은 10,000보다 작거나 같은 자연수이다.

#### 출력

첫째 줄에는 유클리드 기하학에서 반지름이 R인 원의 넓이를, 둘째 줄에는 택시 기하학에서 반지름이 R인 원의 넓이를 출력한다. 정답과의 오차는 0.0001까지 허용한다.

### 문제 풀이

``` cpp
#include <iostream>
#include <cmath>

#define _USE_MATH_DEFINES

using namespace std;

int main() {
    double radius, dimensionU, dimensionT;
    
    cin >> radius;
    
    dimensionU = M_PI * radius * radius;
    dimensionT = 2 * radius * radius;
    
    cout << fixed;
    cout.precision(6);
    cout << dimensionU << "\n";
    cout << dimensionT;
    
    return 0;
}
```