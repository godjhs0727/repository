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

//DFS는 총 정점의 갯수만큼 실행
int dfs(int x)
{
	d[x] = ++id; //노드마다 고유한 번호 할당
	s.push(x);	//스택에 자기 자신을 삽입

	int parent = d[x];
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		//방문하지 않은 이웃
		if (d[y] == 0) parent = min(parent, dfs(y));
		//처리 중인 이웃
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
	//자신의 부모 값을 반환합니다.
	return parent;
}

int main()
{

	return 0;
}