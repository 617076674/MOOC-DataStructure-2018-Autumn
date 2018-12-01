#include<iostream>
#include<map>
#include<vector>

using namespace std;

int N;
long long num1, num2;
map<long long, int> countMap;
vector<long long> maxCallTimesPeople;

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%lld %lld", &num1, &num2);
		countMap[num1]++;
		countMap[num2]++;
	}
	int maxCallTimes = 0;
	for(map<long long, int>::iterator it = countMap.begin(); it != countMap.end(); it++){
		if(it->second > maxCallTimes){
			maxCallTimes = it->second;
		}
	}
	for(map<long long, int>::iterator it = countMap.begin(); it != countMap.end(); it++){
		if(it->second == maxCallTimes){
			maxCallTimesPeople.push_back(it->first);
		}
	}
	if(maxCallTimesPeople.size() == 1){
		printf("%lld %d\n", maxCallTimesPeople[0], maxCallTimes);
	}else{
		printf("%lld %d %d\n", maxCallTimesPeople[0], maxCallTimes, maxCallTimesPeople.size());
	}
	return 0;
} 
