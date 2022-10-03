#include <iostream>
#include <algorithm>

using namespace std;

int n;
int m;
int arr[100000];

int IsExist(int num)
{
	int low = 0;
	int high = n - 1;
	int mid;
	
	for(;low <= high;)
	{
		mid = (low + high) / 2;
		if(arr[mid] == num)
			return 1;
		if(num > arr[mid])
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	
	return 0;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		cout << IsExist(num) << "\n";	
	}	
}
