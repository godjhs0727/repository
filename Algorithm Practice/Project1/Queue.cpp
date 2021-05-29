#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int number = 7;
int c[7]; //방문처리를 위한 하나의 배열
vector<int> a[8]; //7에서 1을 더해준 8개의 벡터가 들어간 배열

void bfs(int start)
{
	queue<int> q; //큐를 만들어준다
	q.push(start); //1
	c[start] = true; // 1개의 배열 방문
	while (!q.empty())
	{
		int x = q.front(); //x는 1이고 큐에 1없어지고 방문처리에 c[1];
		q.pop();
		printf("%d ", x); //1출력
		for (int i = 0; i < a[x].size() /*1 배열 사이즈만큼*/; i++)
		{
			int y = a[x][i]; //a[1][0] == y 2, 3
			if (!c[y])
			{
				q.push(y);
				c[y] = true;
			}
		}
	}
}

int main()
{
	vector<int> v[2];
	v[1].push_back(5);
	v[1].push_back(2);
	cout << v[1].size() << endl;

	a[1].push_back(2);
	a[2].push_back(1);
	a[2].push_back(3);
	a[2].push_back(4);
	a[4].push_back(2);
	a[2].push_back(5);
	a[5].push_back(2);
	a[4].push_back(5);
	a[5].push_back(4);

	a[1].push_back(3);
	a[3].push_back(1);
	a[3].push_back(2);
	a[3].push_back(6);
	a[3].push_back(7);
	a[6].push_back(3);
	a[7].push_back(3);
	a[6].push_back(7);
	a[7].push_back(6);

	bfs(1);

	return 0;
}