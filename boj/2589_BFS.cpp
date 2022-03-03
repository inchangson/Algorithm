#include <iostream>
#include <stdio.h>
#define _MX 50
using namespace std;

int height, width;
char map[_MX][_MX];

void input_data()
{
	cin >> height >> width;
	for(int r = 0; r < height; r++)
		for(int c = 0; c < width; c++)
			cin >> map[r][c];
}
void print_data()
{
	
	cout << "height: " << height << " width: " << width << endl;
	for(int r = 0; r < height; r++)
	{
		for(int c = 0; c < width; c++)
			cout << map[r][c];
		cout << endl;
	}
}
int main()
{
	input_data();
	print_data();
	return 0;
}
