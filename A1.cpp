#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>
using namespace std;

class Graph
{
	vector<vector<int>> AdjList;
	vector<bool> visited;
	queue<array<int, 2>> q;
	int n;
public:
	void reset()
	{
		vector<bool> v(n, false);
		visited = v;
		while (!q.empty())
			q.pop();
	}
	void input()
	{
		cout << "Enter number of nodes: ";
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cout << "Enter adjacent nodes of node " << i << " : " << endl;
			cout << "Enter -1 to quit" << endl;
			int num;
			vector<int> temp;
			while (true)
			{
				cout << "Enter: ";
				cin >> num;
				if (num == -1)
					break;
				temp.push_back(num);
			}
			AdjList.push_back(temp);
		}
	}
	void display()
	{
		for (int i = 0; i < n; i++)
		{
			cout << i << ": ";
			for (int j : AdjList[i])
				cout << j << "->";
			cout << "null" << endl;
		}
	}
	bool DFS(int node, int level = 0)
	{
		cout << "Level: " << level << "\t" << node << endl;
		visited[node] = true;
		for (int adj : AdjList[node])
		{
			if (visited[adj] == false)
			{
				if (DFS(adj, ++level))
					return true;
				level--;
			}
		}
		return false;

	}

	bool BFS(int node, int level = 0)
	{
		if (visited[node] == false)
		{
			cout << "Level: " << level << "\t" << node << endl;
			visited[node] = true;
		}

		for (int adj : AdjList[node])
			if (visited[adj] == false)
				q.push({ adj, level + 1 });

		while (!q.empty())
		{
			node = q.front()[0];
			level = q.front()[1];
			q.pop();
			if (BFS(node, level))
				return true;
		}
		return false;
	}

};

int main()
{
	Graph obj;
	int choice;
	while (true)
	{
		cout << "1. Input" << endl;
		cout << "2. Display" << endl;
		cout << "3. DFS" << endl;
		cout << "4. BFS" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		if (choice == -1)
			break;
		else if (choice == 1)
		{
			obj.input();
		}
		else if (choice == 2)
		{
			obj.display();
		}
		else if (choice == 3)
		{
			obj.reset();
			cout << "Enter start node: ";
			cin >> choice;
			obj.DFS(choice);
		}
		else if (choice == 4)
		{
			obj.reset();
			cout << "Enter start node: ";
			cin >> choice;
			obj.BFS(choice);
		}
	}
	return 0;
}