# Algorithm Study #13

## Problem title: **Claw Machine Game**

## Problem description

게임개발자인 죠르디는 크레인 인형뽑기 기계를 모바일 게임으로 만들려고 합니다.
죠르디는 게임의 재미를 높이기 위해 화면 구성과 규칙을 다음과 같이 게임 로직에 반영하려고 합니다.

![image01](Images/algorithmStudy_12_image_0.png)

게임 화면은 1 x 1 크기의 칸들로 이루어진 N x N 크기의 정사각 격자이며 위쪽에는 크레인이 있고 오른쪽에는 바구니가 있습니다. (위 그림은 5 x 5 크기의 예시입니다). 각 격자 칸에는 다양한 인형이 들어 있으며 인형이 없는 칸은 빈칸입니다. 모든 인형은 1 x 1 크기의 격자 한 칸을 차지하며 격자의 가장 아래 칸부터 차곡차곡 쌓여 있습니다. 게임 사용자는 크레인을 좌우로 움직여서 멈춘 위치에서 가장 위에 있는 인형을 집어 올릴 수 있습니다. 집어 올린 인형은 바구니에 쌓이게 되는 데, 이때 바구니의 가장 아래 칸부터 인형이 순서대로 쌓이게 됩니다. 다음 그림은 [1번, 5번, 3번] 위치에서 순서대로 인형을 집어 올려 바구니에 담은 모습입니다.

![image01](Images/algorithmStudy_12_image_1.png)

만약 같은 모양의 인형 두 개가 바구니에 연속해서 쌓이게 되면 두 인형은 터뜨려지면서 바구니에서 사라지게 됩니다. 위 상태에서 이어서 [5번] 위치에서 인형을 집어 바구니에 쌓으면 같은 모양 인형 두 개가 없어집니다.

![image01](Images/algorithmStudy_12_image_2.gif)

크레인 작동 시 인형이 집어지지 않는 경우는 없으나 만약 인형이 없는 곳에서 크레인을 작동시키는 경우에는 아무런 일도 일어나지 않습니다. 또한 바구니는 모든 인형이 들어갈 수 있을 만큼 충분히 크다고 가정합니다. (그림에서는 화면표시 제약으로 5칸만으로 표현하였음)

게임 화면의 격자의 상태가 담긴 2차원 배열 board와 인형을 집기 위해 크레인을 작동시킨 위치가 담긴 배열 moves가 매개변수로 주어질 때, 크레인을 모두 작동시킨 후 터트려져 사라진 인형의 개수를 return 하도록 solution 함수를 완성해주세요.

**Limitation**
- board 배열은 2차원 배열로 크기는 5 x 5 이상 30 x 30 이하입니다.
- board의 각 칸에는 0 이상 100 이하인 정수가 담겨있습니다.
- 0은 빈 칸을 나타냅니다.
- 1 ~ 100의 각 숫자는 각기 다른 인형의 모양을 의미하며 같은 숫자는 같은 모양의 인형을 나타냅니다.
- moves 배열의 크기는 1 이상 1,000 이하입니다.
- moves 배열 각 원소들의 값은 1 이상이며 board 배열의 가로 크기 이하인 자연수입니다.

***

## Problem solving process

프로그래머스에 등록 되어있는 카카오 개발자 겨울 인턴십 코딩 문제입니다.

순서대로 처리를 한다 생각하고 문제를 풀었습니다.
1. 입력된 위치의 최상위에 있는 인형을 ```bucket```이라는 ```stack```에 삽입한다.
2. ```bucket```에 뽑은 인형을 삽입하기 전, ```bucket```의 ```top()```에 있는 인형과 비교한다.
3. 각 인형을 비교하여 서로 같은 인형이면 ```bucket.pop()```후, ```answer```값을 증가시킨다.

문제를 풀다보니 주의 해야할 부분이 있었습니다.
- 터진 인형의 개수를 return 해야 하기 때문에 인형을 터뜨릴 때마다 ```answer```에는 2를 더해주어야 한다.
- 크레인을 작동시킨 위치가 담긴 배열 ```moves```에 들어있는 값들은 배열 인덱스 값보다 1이 크다.

이외의 사항들은 제한 사항에 의해서 걸러지기 때문에 따로 걱정해야 할 부분들은 없었습니다. 코드 제출하려고 보니 이런 문제들이 보이더라구요.

일단 현재 뽑은 인형들을 담을 ```bucket```을 선언합니다.

``` cpp
stack<int> bucket;
```

그리고 매개변수 ```moves```를 순회하면서 크레인을 작동시킬 위치를 가져옵니다. 인덱스 값에서 1을 빼야합니다.

``` cpp
for (auto xPos : moves) {
    xPos--;
    ...
}
```

해당 위치에서 가장 위에 있는 인형을 가져옵니다. 해당 위치에 인형이 전혀 없는 경우는 순회를 돌면서 알아서 걸러집니다.

``` cpp
for (int yPos = 0; yPos < board.size(); yPos++) {
    if (board[yPos][xPos] == 0) continue;
    ...
}
```

현재 참조 중인 위치에 인형이 있으면, 해당 위치의 인형을 가져오고, ```bucket```에 최상단에 있는 인형과 비교합니다. 만약에 서로 같은 인형이면 ```bucket```에서 인형을 빼고, 아니라면 참조 중인 위치의 인형을 ```bucket```에 추가합니다.

``` cpp
int currentSelected = board[yPos][xPos];
board[yPos][xPos] = 0;
            
if (!bucket.empty() && bucket.top() == currentSelected) {
    bucket.pop();
    answer += 2;
}
else {
    bucket.push(currentSelected);
}
break;
```

***

완성된 코드입니다.

``` cpp
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    stack<int> bucket;
    
    for (auto xPos : moves) {
        xPos--;
        
        for (int yPos = 0; yPos < board.size(); yPos++) {
            if (board[yPos][xPos] == 0) continue;
            
            int currentSelected = board[yPos][xPos];
            board[yPos][xPos] = 0;
            
            if (!bucket.empty() && bucket.top() == currentSelected) {
                bucket.pop();
                answer += 2;
            }
            else {
                bucket.push(currentSelected);
            }
            break;
        }
    }

    return answer;
}
```