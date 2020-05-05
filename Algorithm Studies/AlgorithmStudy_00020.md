# Algorithm Study #19

## Problem title: **Daily Traffic**

## Problem description

이번 추석에도 시스템 장애가 없는 명절을 보내고 싶은 어피치는 서버를 증설해야 할지 고민이다. 장애 대비용 서버 증설 여부를 결정하기 위해 작년 추석 기간인 9월 15일 로그 데이터를 분석한 후 초당 최대 처리량을 계산해보기로 했다. 초당 최대 처리량은 요청의 응답 완료 여부에 관계없이 임의 시간부터 1초(=1,000밀리초)간 처리하는 요청의 최대 개수를 의미한다.

### 입력 형식

- solution 함수에 전달되는 lines 배열은 N(1 ≦ N ≦ 2,000)개의 로그 문자열로 되어 있으며, 각 로그 문자열마다 요청에 대한 응답완료시간 S와 처리시간 T가 공백으로 구분되어 있다.
- 응답완료시간 S는 작년 추석인 2016년 9월 15일만 포함하여 고정 길이 2016-09-15 hh:mm:ss.sss 형식으로 되어 있다.
- 처리시간 T는 0.1s, 0.312s, 2s 와 같이 최대 소수점 셋째 자리까지 기록하며 뒤에는 초 단위를 의미하는 s로 끝난다.
- 예를 들어, 로그 문자열 2016-09-15 03:10:33.020 0.011s은 2016년 9월 15일 오전 3시 10분 **33.010초**부터 2016년 9월 15일 오전 3시 10분 **33.020초**까지 **0.011초** 동안 처리된 요청을 의미한다. (처리시간은 시작시간과 끝시간을 포함)
- 서버에는 타임아웃이 3초로 적용되어 있기 때문에 처리시간은 0.001 ≦ T ≦ 3.000이다.
- lines 배열은 응답완료시간 S를 기준으로 오름차순 정렬되어 있다.

### 출력 형식

- solution 함수에서는 로그 데이터 lines 배열에 대해 초당 최대 처리량을 리턴한다.

***

## Problem solving process

결과 자체는 ```1초간 처리하는 요청이 가장 많은 구간에서 요청의 최대 개수를 반환하면 되는 문제```입니다. 처리시간이 요청 시간, 응답 완료 시간이 둘 다 처리 시간에 포함되기 때문에, 어떤 구간의 처리량을 계산 할 때, 걸치는 경우라도 하나의 처리량으로 간주한다고 생각해야 한다합니다.

완성된 코드입니다.
``` cpp
#include <string>
#include <vector>

#define abs(x) x < 0 ? -x : x
#define epsilon 0.001

using namespace std;

vector<string> splitString(string str, char splitFactor){
	vector<string> result;
	int prev=0;
	for(int i=0;i<str.size();i++){
		if(str[i]==splitFactor){
			result.push_back(str.substr(prev,i-prev));
			prev=i+1;
		}
	}
	if(str.size()!=prev)
		result.push_back(str.substr(prev,str.size()-prev));

	return result;
}

int solution(vector<string> lines) {
    int answer = 0;
    
    vector<vector<double>> result;
    for(int i = 0; i < lines.size(); i++){
    	vector<string> splitedLine = splitString(lines[i], ' ');

    	vector<string> sRaw = splitString(splitedLine[1], ':');
    	double s = stod(sRaw[0]) * 3600 + stod(sRaw[1]) * 60 + stod(sRaw[2]);
    	double t = stod(splitString(splitedLine[2], 's')[0]);
    
        result.push_back({s - t + 0.001, s});
    }

    for(int i = 0; i < result.size(); i++){
    	double begin = result[i][1];
    	double end = begin + 0.999;

    	int temp=0;
    	for(int j = i; j < result.size(); j++) {
    		if (abs(result[j][1] - begin) >= epsilon && abs(result[j][0] - end) <= epsilon)
                temp++;
    	}

    	if(answer < temp) answer = temp;
    }

    return answer;
}
```