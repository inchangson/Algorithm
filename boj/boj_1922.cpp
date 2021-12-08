#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

constexpr int MX_N = 1000;
constexpr int MX_M = 100000;
constexpr int NODE1 = 0;
constexpr int NODE2 = 1;
constexpr int COST = 2;

int n;
int m;
int costs[MX_M][3];
int parents[MX_N + 1];
int ans;

void initData(){
	ans = 0;
	//make parents arr
	for(int idx = 0; idx < n; ++idx){
		parents[idx] = idx;
	}
}

void inputData(){
	scanf("%d %d", &n, &m);
	
	for(int idx = 0; idx < m; ++idx){
		scanf("%d %d %d", &costs[idx][NODE1], &costs[idx][NODE2], &costs[idx][COST]);	
	}
}

int getParent(int child){
	if(parents[child] = child)	return child;
	else return getParent(parents[child]);
}

void solve(){
	//sort(costs, costs + m, myCmp);
	
	std::qsort(costs, 10, sizeof(*costs),
        [](const void *arg1, const void *arg2)->int
        {
            int const *lhs = static_cast<int const*>(arg1);
            int const *rhs = static_cast<int const*>(arg2);
            return lhs[2] - rhs[2];
        });

	
	int totalCosts = 0;
	for(int idx = 0; idx < m; ++idx){
		int parentA = getParent(costs[idx][0]);
		int parentB = getParent(costs[idx][1]);
		if(parentA == parentB)	continue;
		totalCosts += costs[idx][2];
		
		if(parentA < parentB){
			parents[parentB] = parentA;
		}
		else{
			parents[parentA] = parentB;
		}
	}
	ans = totalCosts;
}

int main(){
	initData();
	inputData();
	solve();
	printf("%d\n", ans);	
	return 0;
}
