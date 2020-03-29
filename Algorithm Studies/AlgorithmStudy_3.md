# Algorithm Study #4

## Problem title: **Best Album**

## Problem description
스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시하려 합니다. 노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.

1. 속한 노래가 많이 재생된 장르를 먼저 수록합니다.
2. 장르 내에서 많이 재생된 노래를 먼저 수록합니다.
3. 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.

노래의 장르를 나타내는 문자열 배열 genres와 노래별 재생 횟수를 나타내는 정수 배열 plays가 주어질 때, 베스트 앨범에 들어갈 노래의 고유 번호를 순서대로 return 하도록 solution 함수를 완성하세요.

**Limitation**  
- genres[i]는 고유번호가 i인 노래의 장르입니다.
- plays[i]는 고유번호가 i인 노래가 재생된 횟수입니다.
- genres와 plays의 길이는 같으며, 이는 1 이상 10,000 이하입니다.
- 장르 종류는 100개 미만입니다.
- 장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
- 모든 장르는 재생된 횟수가 다릅니다.

***

## Problem solving process

일단 장르 별로 재생된 횟수를 구해야 했습니다. 그 다음에 장르별로 많이 재생된 횟수 순서로 반환해야 할 ```answer```에 삽입해줬습니다.

***

완성된 코드입니다.

``` cpp
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> countMap;
	vector <pair<string, int>> compMap;

	for (int i = 0; i < genres.size(); i++) {
		countMap[genres[i]] += plays[i];
    }
    
    for (auto e : countMap) {
        compMap.push_back(make_pair(e.first, e.second));
    }

	sort(compMap.begin(), compMap.end(), cmp);
    
	for (int i = 0; i < compMap.size(); i++) {

		int first = 0;
        int firstId = 0;
        int second = 0; 
        int secondId = 0;

		for (int j = 0; j < genres.size(); j++) {
			if (genres[j] == compMap[i].first) {
				if (plays[j] > first) {
					second = first;
					secondId = firstId;
					first = plays[j];
					firstId = j;
				}
				else if (plays[j] > second) {
					second = plays[j];
					secondId = j;
				}
			}
		}
        
		answer.push_back(firstId);
		if (second > 0) {
			answer.push_back(secondId);
        }
	}
	return answer;
}
```

일단 각 장르 별로 재생 횟수를 구했습니다.

``` cpp
for (int i = 0; i < genres.size(); i++) {
	countMap[genres[i]] += plays[i];
}
```

처음에 만들었던 재생 횟수 계산용 ```Hash Map```이 정렬이 까다로워서 ```vector<pair<string, int>>```로 값을 복사하여 정렬했습니다.

``` cpp    
for (auto e : countMap) {
    compMap.push_back(make_pair(e.first, e.second));
}

sort(compMap.begin(), compMap.end(), cmp);
```

이제 매개변수로 주어진 ```genre``` 배열을 순회하면서 장르별 재생 횟수를 기준으로 반환할 배열 ```answer```을 채웠습니다.

``` cpp
for (int j = 0; j < genres.size(); j++) {
	if (genres[j] == compMap[i].first) {
		if (plays[j] > first) {
			second = first;
			secondId = firstId;
			first = plays[j];
			firstId = j;
		}
		else if (plays[j] > second) {
			second = plays[j];
			secondId = j;
		}
	}
}

answer.push_back(firstId);
if (second > 0) {
	answer.push_back(secondId);
}
```

조건 중에 장르 내에 같은 재생 수를 가진 노래가 있으면, 고유 번호가 낮은 노래를 우선적으로 추가하라는 조건이 있었는데, 해당 조건은 마지막에 배열을 순환하면서 걸러지기 때문에 상관없습니다.