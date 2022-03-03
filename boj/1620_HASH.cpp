#include <map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, m;	
	cin >> n >> m;
	
	map<string, int> name_poke_list;
	string * num_poke_list;
	num_poke_list = new string[n + 1];
	
	string buf;
	for(int i = 1; i <= n ; ++i)
	{
		cin >> buf;
		name_poke_list[buf] = i;
		num_poke_list[i] = buf;
	}
	
	for(;m > 0; --m)
	{
		cin >> buf;
		if('0' <= buf[0] && buf[0] <= '9')
		{
			cout << num_poke_list[stoi(buf)] << "\n";
		}
		else
		{
			cout << name_poke_list[buf] << "\n";
		}
	}
	
	return 0;
}
