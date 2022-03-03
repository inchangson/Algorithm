#include <iostream>
#include <list>

using namespace std;

int n;//[3, 1000]
int k;//[1, 1000]

list <int> soldiers;
typedef list<int>::iterator listiter;

void josephus(int n, int k)
{
	list<int> survivors;
	for (int i = 1; i <= n; i++)
		survivors.push_back(i);
	listiter kill = survivors.begin();
	for (; n > 2; n--)
	{
		kill = survivors.erase(kill);
		if(kill == survivors.end())
			kill = survivors.begin();
		for(int i = 0 ; i < k - 1; i++)
		{
			kill++;
			if(kill == survivors.end())
				kill = survivors.begin();
		}
	}
	cout << survivors.front() << " " << survivors.back() << endl;
}

int main()
{
	int c;
	cin >> c;
	for (; c > 0; c--)
	{
		cin >> n >> k;
		josephus(n, k);
	}
	return 0;
}
