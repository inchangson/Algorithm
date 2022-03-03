#include <string>
#include <iostream>
#include <vector>
#include <cmath>

#define MX_M 500
#define MX_Q 20
#define MX_W 10
#define MX_N 100

using namespace std;

int m, q;
string words[MX_M];
double prob_first[MX_M];
double prob_next[MX_M][MX_M];
double prob_miss[MX_M][MX_M];

int test_size[MX_Q];
int test_cases[MX_Q][MX_N];

double cache[MX_M][MX_N];
int memo[MX_M][MX_N];

int _size;
int _tn;


void inputData()
{
	int i, j;
	cin >> m >> q;
	for(i = 0; i < m; i++)
		cin >> words[i];
	
	for(i = 0; i < m; i++)
	{
		cin >> prob_first[i];
		prob_first[i] = log(prob_first[i]);
	}
	
	for(i = 0; i < m; i++)
		for(j = 0; j < m; j++)
		{
			cin >> prob_next[i][j];
			prob_next[i][j] = log(prob_next[i][j]);
		}
	
	for(i = 0; i < m; i++)
		for(j = 0; j < m; j++)
		{
			cin >> prob_miss[i][j];
			prob_miss[i][j] = log(prob_miss[i][j]);
		} 
			
	for(i = 0; i < q; i++)
	{
		cin >> 	test_size[i];
		string tmp;
		for(j = 0; j < test_size[i]; j++)
		{
			cin >> tmp;
			for(int k = 0; k < m; k++)
			{
				if(tmp == words[k])
				{	
					test_cases[i][j] = k;
					break;
				}
			}
		}
	}		
}

void printData()
{
	cout << endl << "======" << endl;
	int i, j;
	cout << "m: " <<  m << " q: " << q << endl;
	
	cout << "<words>\n";
	for(i = 0; i < m; i++)
		cout << words[i] << " ";

	cout << "<prob_first>\n";
	for(i = 0; i < m; i++)
		cout << prob_first[i] << " ";
	cout << endl;
	
	cout << "<prob_next>\n";
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < m; j++)
			cout << prob_next[i][j] << " ";
		cout << endl;		
	}
	
	cout << "<prob_miss>\n";
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < m; j++)
			cout << prob_miss[i][j] << " ";
		cout << endl;		
	}
		
	cout << "<test_words & test_cases>\n";
	for(i = 0; i < q; i++)
	{
		cout <<"words: " <<	test_size[i] << endl;;
		for(j = 0; j < test_size[i]; j++)
			cout << test_cases[i][j] << " ";
		cout << endl;
	}
	
	cout << endl << "======" << endl;
}

void initData()
{
	for(int i = 0; i < m; i++ )
	{
		for(int j = 0; j < _size; j++)
		{
			cache[i][j] = 1.0;
		}
	}
}

double ocr(int past_word, int cur)
{
	if(cur == _size)
	{
		return 0.0;
	}
	
	int curChar = test_cases[_tn][cur];
	
	double &ret = cache[past_word][cur];
	
	if(ret != 1.0) return ret;
	
	ret = -1e200;
	
	double prob;
	for(int cand = 0; cand < m; cand++)
	{
		if(cur == 0)
		{			
			prob = prob_miss[cand][curChar] + prob_first[cand] + ocr(cand, cur + 1);
		}
		else
		{
			prob = prob_miss[cand][curChar] + prob_next[past_word][cand] + ocr(cand, cur + 1);
		}
		
		if(prob > ret) 
		{
			ret = prob;
			memo[past_word][cur] = cand;
		}
	}
	return ret;
}

void reconstruct(int pastWord, int idx, vector<string> & picked)
{
	if(idx == _size) return;
	
	int & selected = memo[pastWord][idx];
	picked.push_back(words[selected]);
	reconstruct(selected, idx + 1, picked);
}

int main()
{
	inputData();
	//printData();
	
	for(int i = 0; i < q; i++)
	{
		_size = test_size[i];
		_tn = i;
		
		initData();
		
		ocr(0, 0);
		
		vector<string> ans;
		reconstruct(0, 0, ans);
		for(string str : ans)
			cout << str << " ";
		cout << endl;
	}
	return 0;
}
