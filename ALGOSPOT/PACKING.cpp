#include <iostream>
#include <cstring>
#include <string>
#include <vector>

#define _MX_N 100
#define _MX_W 1000

using namespace std;

int n, c, w;

string * names;
int stuff[_MX_N + 1][2];
int memo[_MX_N + 1][_MX_W + 1];
int bucket[_MX_N + 1][_MX_W + 1];

void inputData()
{
	cin >> n >> w;
	names = new string[n + 1];
	names[0] = "";
	memset(memo, -1, sizeof(memo));
	memset(stuff, 0, sizeof(stuff));
	memset(bucket, 0, sizeof(bucket));
	
	for(int i = 1; i <= n; i++)
	{
		cin >> names[i] >> stuff[i][0] >> stuff[i][1];
	}
}
void printData()
{
	cout << endl;
	cout << "n: " << n << " w: " << w << endl;
	
	for(int i = 0; i < n + 1; i++)
	{
		cout << names[i] << " " << stuff[i][0] << " "<< stuff[i][1] << endl;
	}
	for(int i = 0; i < n + 1; i++)
	{
		for(int j = 0 ; j < w + 1; j ++)
			cout << memo[i][j] << " ";
		cout << endl;
	}
}

int solve(int now, int spare)
{
	int &ret = memo[now][spare];
	if(ret != -1) return ret;
	
	ret = stuff[now][1];
	for(int next = now + 1; next <= n; next++)
	{
		if(spare < stuff[next][0]) continue;
		
		int cand = solve(next, spare - stuff[next][0]) + stuff[now][1];
		if(ret < cand)
		{
			bucket[now][spare] = next;
			ret = cand;
		}
	}
	return ret;
}

int main()
{
	cin >> c;
	for(;c > 0; c--)
	{
		inputData();
		cout << solve(0, w) << " ";
		
		vector<string> ans;
		
		int pi, pw;//present index and weight
		int leng = 0;
		for(pi = 0, pw = w;;)
		{
			pi = bucket[pi][pw];
			pw = pw - stuff[pi][0];
			if(pi == 0) break;
			ans.push_back(names[pi]);
			leng++;
		}
		
		cout << leng << endl;
		
		for(int i = 0; i < leng; i++)
			cout << ans[i] << endl;
		
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
