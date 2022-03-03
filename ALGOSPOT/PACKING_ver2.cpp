#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

#define _MX_N 100
#define _MX_W 1000

using namespace std;

int n, c, w;
string * names;
int stuff[_MX_N + 1][2];
int check[_MX_N + 1];
int memo[_MX_N + 1][_MX_W + 1];

void inputData()
{
	cin >> n >> w;
	names = new string[n + 1];
	memset(memo, -1, sizeof(memo));
	memset(stuff, 0, sizeof(stuff));
	
	names[0] = "";
	for(int i = 1; i <= n; i++)
	{
		cin >> names[i] >> stuff[i][0] >> stuff[i][1];
	}
}

int solve(int now, int spare)
{
	if(now == n + 1) return 0;
	int &ret = memo[now][spare];
	if(ret != -1) return ret;	
	ret = solve(now + 1, spare);
	if(spare < stuff[now][0]) return ret;
	ret = max(ret, solve(now + 1, spare - stuff[now][0]) + stuff[now][1]);
	return ret;
}

void reconstruct(int item, int capacity, vector<string> & picked)
{
	if(item == n + 1) return;
	if(solve(item, capacity) == solve(item + 1, capacity))
	{
		reconstruct(item + 1, capacity, picked);
	}
	else
	{
		picked.push_back(names[item]);
		reconstruct(item + 1, capacity - stuff[item][0], picked);
	}
}

int main()
{
	cin >> c;
	for(;c > 0; c--)
	{
		inputData();
		int score = solve(0, w);	
		vector<string> ans;
		reconstruct(0, w, ans);
		cout << score << " " << ans.size() << endl;
		for(string str : ans)
			cout << str << endl;
			
		{
		cout << "\n ======== "<< endl;
		int cnt(0);
		for(int i = 0; i <= n ; i++)
		{
			for(int j = 0; j <= w; j++)
			{
				cout << memo[i][j] << " ";
				if(memo[i][j] != -1) cnt++;				
			}
			cout << endl;
		}
		cout << "cnt: " << cnt<< endl;
		cout << " ======== "<< endl;
		}
		
		delete[] names;	
	}
	return 0;
}
