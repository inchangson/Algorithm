#include <map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	map<string, int> company;
	int n;
	cin >> n;
	for(; n > 0; --n)
	{
		string name;
		string state;
		cin >> name >> state;
		company[name]++;
	}
	
	map<string, int>::reverse_iterator iter;
	for(iter = company.rbegin(); iter != company.rend(); iter++)
	{
		if(iter->second % 2)
			cout << iter->first << "\n";
	}
	return 0;
}

