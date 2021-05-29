#include <iostream>
#include <vector>
#include <stack>

#define MAX 10001;
const int max = 10001;
using namespace std;

int id, d[max];
bool finished[max];
vector<int> a[max];
vector<vector<int>> SCC;
stack<int> s;

//DFS�� �� ������ ������ŭ ����
int dfs(int x)
{
	d[x] = ++id; //��帶�� ������ ��ȣ �Ҵ�
	s.push(x);	//���ÿ� �ڱ� �ڽ��� ����

	int parent = d[x];
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		//�湮���� ���� �̿�
		if (d[y] == 0) parent = min(parent, dfs(y));
		//ó�� ���� �̿�
		else if (!finished[y]) parent = min(parent, d[y]);
	}
	if (parent == d[x])
	{
		vector<int> scc;
		while (1)
		{
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == x) break;
		}
		SCC.push_back(scc);
	}
	//�ڽ��� �θ� ���� ��ȯ�մϴ�.
	return parent;
}

int main()
{

	return 0;
}