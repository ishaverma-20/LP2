//Implement depth first search (DFS) algorithm and breadth first search (BFS) algorithm.
//Use an application for undirected graph and develop a recursive algorithm for searching all the vertices of a graph or tree data structure.
//Also print the levels as it traverses for both algorithms.

#include <iostream>
#include <array>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Graph
{
	vector<int>* AdjList;
	vector<int> visited;
	queue<array<int, 2>> q;
	int n, el;
public:
	void createGraph()
	{
		cout << "Enter the number of nodes: ";
		cin >> n;
		AdjList = new vector<int>[n];
		for (int i = 0; i < n; i++)
		{
			cout << "Enter nodes adjacent to Node " << i << ": " << endl;
			cout << "Enter -1 to stop. " << endl;
			int ip;
			while (true)
			{
				cout << "Enter: ";
				cin >> ip;
				if (ip == -1)
					break;
				AdjList[i].push_back(ip);
			}
		}
	}
	void displayGraph()
	{
		for (int i = 0; i < n; i++)
		{
			cout << i << ": ";
			for (auto itr = AdjList[i].begin(); itr != AdjList[i].end(); itr++)
				cout << *itr << "->";
			cout << "null" << endl;
		}
	}
	void search()
	{
		int choice, start;
		visited.clear();
		while (!q.empty())
			q.pop();
		cout << "Enter number to be searched for: ";
		cin >> el;
		cout << "Select Method to search the element: " << endl;
		cout << "1. DFS" << endl;
		cout << "2. BFS" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		cout << "Enter starting node: ";
		cin >> start;
		if (choice == 1)
		{
			int l = 0;
			bool ans = DFS(start, l);
			if (ans)
				cout << "Element found" << endl;
			else
				cout << "Element not found" << endl;
		}
		else if (choice == 2)
		{

			int l = 0;
			bool ans = BFS(start, l);
			if (ans)
				cout << "Element found" << endl;
			else
				cout << "Element not found" << endl;
		}
	}
	bool DFS(int n, int l)
	{
		cout << "Level " << l << ": " << n << endl;
		visited.push_back(n);
		if (n == el)
			return true;
		for (auto itr = AdjList[n].begin(); itr != AdjList[n].end(); itr++)
		{
			if (visited.end() == find(visited.begin(), visited.end(), *itr))
			{
				if (DFS(*itr, ++l))
					return true;
				--l;
			}
		}
		return false;
	}
	bool BFS(int n, int l, int lev = 0)
	{
		if (visited.end() == find(visited.begin(), visited.end(), n))
		{
			cout << "Level " << lev << ": " << n << endl;
			visited.push_back(n);
		}
		if (n == el)
			return true;

		for (auto itr = AdjList[n].begin(); itr != AdjList[n].end(); itr++)
			if (visited.end() == find(visited.begin(), visited.end(), *itr))
				q.push({ *itr, lev + 1 });

		if (!q.empty())
		{
			int i = q.front()[0];
			lev = q.front()[1];
			q.pop();
			if (BFS(i, ++l, lev))
				return true;
			--l;
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
		cout << "1. Create a Graph: " << endl;
		cout << "2. Display the Graph: " << endl;
		cout << "3. Search: " << endl;
		cout << "Enter choice: ";
		cin >> choice;
		if (choice == 1)
			obj.createGraph();
		else if (choice == 2)
			obj.displayGraph();
		else if (choice == 3)
			obj.search();
		else
		{
			cout << "Invalid choice" << endl;
			break;
		}
	}
	return 0;
}