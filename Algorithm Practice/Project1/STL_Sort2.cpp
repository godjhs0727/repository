#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
{
	if (a.second.first == b.second.first)
	{
		return a.second.second > b.second.second;
	}
	else
	{
		return a.second.first > b.second.first;
	}
}

int main()
{
	vector<pair<string,pair<int, int>>>v;
	v.push_back(pair<string, pair<int, int>>("±è", pair<int, int>(79, 19930228)));
	v.push_back(pair<string, pair<int, int>>("ÀÌ", pair<int, int>(85, 19940122)));
	v.push_back(pair<string, pair<int, int>>("³ª", pair<int, int>(85, 19910122)));	
	v.push_back(pair<string, pair<int, int>>("°­", pair<int, int>(79, 19920122)));
	v.push_back(pair<string, pair<int, int>>("Á¤", pair<int, int>(90, 19940122)));

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << ' ';
	}
	return 0;
}