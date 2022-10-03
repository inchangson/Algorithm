#include <stdio.h>
#include <iostream>
#include <algorithm>

#define _MX 500000

using namespace std;
int n, m;
int cards[_MX];
int targets[_MX];

void input_data()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		scanf("%d", &cards[i]);
	cin >> m;
	for(int i = 0; i < m; i++)
		scanf("%d", &targets[i]);
	sort(cards, cards + n);
}

void print_data()
{
	cout << n;
	for(int i = 0; i < n; i++)
		printf(" %d", cards[i]);
	printf("\n");
	cout << m;
	for(int i = 0; i < m; i++)
		printf(" %d", targets[i]);
	printf("\n");
}


int get_lower_bound(int target)
{
	int lo = 0;
	int hi = n - 1;
	int mid;
	int first_idx = -1;
	
	for(;lo <= hi;)
	{
		mid = (lo + hi) / 2;
		
		if(target > cards[mid])
		{
			lo = mid + 1;
		}
		else if(target < cards[mid])
		{
			hi = mid - 1;
		}
		else
		{
			hi = mid - 1; 
			first_idx = mid;
		}
	}
	return first_idx;
}


int get_upper_bound(int target)
{
	int lo = 0;
	int hi = n - 1;
	int mid;
	int first_idx = -1;
	
	for(;lo <= hi;)
	{
		mid = (lo + hi) / 2;
		
		if(target > cards[mid])
		{
			lo = mid + 1;
		}
		else if(target < cards[mid])
		{
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1; 
			first_idx = mid;
		}
	}
	return first_idx;
}

int get_counts(int target)
{
	int first_idx;
	int last_idx;
	
	first_idx = get_lower_bound(target);
	
	if(first_idx == -1) return 0;
	
	last_idx = get_upper_bound(target);
	
	int cnt = last_idx - first_idx + 1;
	
	return cnt;
}

int main()
{
	input_data();
	//print_data();	
	
	for(int i = 0; i < m; i++)
		printf("%d ", get_counts(targets[i]));
	printf("\n");
	
	return 0;
}
