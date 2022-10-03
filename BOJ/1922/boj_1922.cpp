//kruskal

#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Network{
	int from;
	int to;
	int cost;
};

constexpr int INF = 0X7FFFFFFF;
constexpr int MX_N = 1000;
constexpr int MX_M = 100000;

int N;
int M;
Network networks[MX_M];
int parents[MX_N + 1];

void inputData(){
	scanf("%d %d", &N, &M);

	for(int idx = 0; idx <= N; ++idx){
		parents[idx] = idx;
	}
	for(int idx = 0; idx < M; ++idx){
		scanf("%d %d %d", &networks[idx].from, &networks[idx].to, &networks[idx].cost);
		if(networks[idx].from == networks[idx].to){
			networks[idx].cost = INF;
		}
	}
}

int getParent(int child){
	if(parents[child] == child)	return child;
	else return getParent(parents[child]);
}

bool myCmp(Network n1, Network n2){
	return n1.cost < n2.cost;
}

int solve(){
	sort(networks, networks + M, myCmp);
	
	int totalCost = 0;
	int endFlag = 0;
	for(int idx = 0; idx < M; ++idx){
		if(endFlag == N)    return totalCost;
		
		int parentA = getParent(networks[idx].from);
		int parentB = getParent(networks[idx].to);

		if(parentA == parentB)	continue;
		totalCost += networks[idx].cost;
		endFlag++;
		
		if(parentA < parentB){
			parents[parentB] = parentA;
		}
		else{
			parents[parentA] = parentB;
		}
	}
	
	return totalCost;
}

int main(){
	
	inputData();
	printf("%d\n", solve());
	
	return 0;
}
