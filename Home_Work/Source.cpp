#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include <exception>

using namespace std;

struct Node
{
	int x;
	int y;
	int value = 3;
	bool used;

	Node(int _x, int _y)
	{
		x = _x;
		y = _y;
		used = false;
		value = 3;
	}

	Node()
	{
		x = 0;
		y = 0;
		used = false;
		value = 3;
	}
};

void bfs(int i, int j, vector<vector<Node>>& v)
{
	queue<Node> q;
	q.push(Node(i,j));
	Node f = q.front();
	while (!q.empty())
	{
		q.pop();

		if (v[f.x+1][f.y].value == 0 && v[f.x+1][f.y].used==false)
		{
			q.push(Node(f.x+1,f.y));
			v[f.x + 1][f.y].used = true;
		}

		if(v[f.x-1][f.y].value==0 && v[f.x-1][f.y].used==false)
		{
			q.push(Node(f.x - 1, f.y));
			v[f.x - 1][f.y].used - true;
		}

		if (v[f.x][f.y+1].value == 0 && v[f.x + 1][f.y].used == false)
		{
			q.push(Node(f.x, f.y+1));
			v[f.x][f.y + 1].used = true;
		}

		if(v[f.x][f.y-1].value==0 && v[f.x][f.y-1].used==false)
		{
			q.push(Node(f.x , f.y-1));
			v[f.x][f.y - 1].used = true;
		}

		if(!q.empty())
		    f = q.front();
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<Node>> Array(n+2,vector<Node>(n+2));

	for (int i = 0; i <= n+1; i++)
	{
		for (int j = 0; j <= n+1; j++)
		{
			Array[i][j] = Node(i, j);
		}
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int t;
			cin >> t;
			Array[i][j].value = t;
		}
	}

	int count = 0;
	for (int i = 1;i <=n; i++)
	{
		for (int j = 1; j <=n; j++)
		{
			if (Array[i][j].value == 0 && Array[i][j].used == false)
			{
				bfs(i,j,Array);
				count++;
			}
		}
		
	}
	cout << count;
	return 0;
}