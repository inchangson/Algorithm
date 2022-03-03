#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>

using namespace std;

int n, k;
int* arr;
int* cache;
int* cache2;

int arr_size;

const int MAX = 2000000000 + 1;

int klis(int idx)
{
	int & ret = cache[idx];
	if(ret != -1)
		return ret;
	
	ret = 1;
	int cand;
	for(int next = idx + 1; next < arr_size; ++next)
	{
		if(arr[idx] < arr[next])
		{
			cand = klis(next) + 1;
			ret = max(ret, cand);
		}
	}
	return ret;
}


int count_cases(int idx)
{
	int & ret = cache2[idx];
	if(ret != -1)
		return ret;
		
	int flag = klis(idx) - 1;
	if(flag == 0)
	{
		ret = 1;
		return ret;
	}
		
	ret = 0;	
	for(int next = idx + 1; next < arr_size; ++next)
	{
		if(arr[idx] < arr[next])
		{
			if(klis(next) == flag)
			{
				ret = min<long long> (MAX, (long long)ret + count_cases(next));							
			}
		}
	}	
	return ret;
}

void v_sort(vector<int> & v)
{
	int sz = (int)v.size();
	for(int i = 0; i < sz - 1; ++i)
	{
		for(int j = i + 1; j < sz; ++j)
		{
			if(arr[v[i]] > arr[v[j]])
			{
				swap(v[i], v[j]);
			}
		}
	}
}

void reconstruct(int idx, int order)
{
	int flag = klis(idx) - 1;
	if(flag == 0)
		return;

	vector<int> cand;
	int ret = 0;	
	for(int next = idx + 1; next < arr_size; ++next)
	{
		if(arr[idx] < arr[next])
		{
			if(klis(next) == flag)
			{
				cand.emplace_back(next);			
			}
		}
	}
	
	v_sort(cand);
	
	for(int i = 0; i < (int)cand.size(); i++)
	{
		int cnt = count_cases(cand[i]);
		if(order <= cnt)
		{
			cout << arr[cand[i]] << " ";
			reconstruct(cand[i], order);
			break;
		}
		order -= cnt;
	}
}


//교재 버 젼 
void reconstruct2(int idx, int order, vector <int> & ans)
{
	if(idx)  ans.push_back(arr[idx]);
	vector<pair<int, int>> followers;
	for(int next = idx + 1; next < arr_size; ++next)
	{
		if((idx == 0 || arr[idx] < arr[next])
		  && (klis(idx) == klis(next) + 1))
		  followers.push_back(make_pair(arr[next], next));
	}
	sort(follwers.begin(), followers.end());
	for(int i = 0; i < (int)followers.size(); i++)
	{
		int idx = followers[i].second;
		int cnt = count_cases(idx);
		if(order <= cnt)
		{
			reconstruct2(cand[i], order, ans);
			break;
		}
		order -= cnt;
	}
}

int main()
{
	int c;	
	cin >> c;
	for(;c > 0; --c)
	{
		cin >> n >> k;
		arr = new int[n + 1];
		cache = new int[n + 1];
		cache2 = new int[n + 1];
		arr_size = n + 1;
					
		arr[0] = 0;
		cache[0] = cache2[0] = -1;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &arr[i]);
			cache[i] = cache2[i] = -1;
		}
					
		//cout << endl << "<ans>" << endl;
		cout << klis(0) - 1 << endl;	
		//cout << count_cases(0) << endl;	
		reconstruct(0, k);
		cout << endl;
		
		delete [] arr;
		delete [] cache;
		delete [] cache2;
	}
}
