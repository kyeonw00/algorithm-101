# Algorithm Study #35

## 분산처리

재용이는 최신 컴퓨터 10대를 가지고 있다. 어느 날 재용이는 많은 데이터를 처리해야 될 일이 생겨서 각 컴퓨터에 1번부터 10번까지의 번호를 부여하고, 10대의 컴퓨터가 다음과 같은 방법으로 데이터들을 처리하기로 하였다.

1번 데이터는 1번 컴퓨터, 2번 데이터는 2번 컴퓨터, 3번 데이터는 3번 컴퓨터, ... ,

10번 데이터는 10번 컴퓨터, 11번 데이터는 1번 컴퓨터, 12번 데이터는 2번 컴퓨터, ...

총 데이터의 개수는 항상 a^b개의 형태로 주어진다. 재용이는 문득 마지막 데이터가 처리될 컴퓨터의 번호가 궁금해졌다. 이를 수행해주는 프로그램을 작성하라.

#### 입력

입력의 첫 줄에는 테스트 케이스의 개수 ```T```가 주어진다. 그 다음 줄부터 각각의 테스트 케이스에 대해 정수 ```a```와 ```b```가 주어진다. (1 ≤ ```a``` < 100, 1 ≤ ```b``` < 1,000,000)

#### 출력

각 테스트 케이스에 대해 마지막 데이터가 처리되는 컴퓨터의 번호를 출력한다.

### 문제 풀이

```a```를 ```b```번 제곱 한 수의 나머지를 출력하면 됩니다. 0인 경우에는 10이 되겠네요. 이 부분만 예외처리 시켜주었습니다.

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