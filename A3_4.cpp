//Implement Greedy Search algorithm on some application for :
//I.Minimum Spanning Tree OR
//II.Single–Source Shortest Path Problem

//Implement Greedy Search algorithm on some application for :
//I.Job Scheduling Problem OR
//II.Prim’s Minimal Spanning Tree algorithm

//Minimum Spanning Tree using Prim's Algorithm

#include <iostream>
#include <vector>
using namespace std;

class Prims
{
	vector<vector<int>> AdjMatrix;
	int n;
public:
	void input()
	{
		cout << "Enter number of nodes: ";
		cin >> n;
		//AdjMatrix = new vector<vector<int>>(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
		{
			vector<int> temp(n, 0);
			AdjMatrix.push_back(temp);
		}
		cout << "Enter edges: " << endl;
		cout << "Enter weight as -1 to stop." << endl;
		int w, v1, v2;
		while (true)
		{
			cout << "Enter weight: ";
			cin >> w;
			if (w == -1)
				break;
			cout << "Enter Vertex 1: ";
			cin >> v1;
			cout << "Enter Vertex 2: ";
			cin >> v2;
			AdjMatrix[v1][v2] = w;
			AdjMatrix[v2][v1] = w;
		}
	}
	void display()
	{
		for (auto itr = AdjMatrix.begin(); itr != AdjMatrix.end(); itr++)
		{
			for (int i : *itr)
				cout << i << " ";
			cout << endl;
		}
	}
	void prims()
	{
		vector<int> visited;
		int start, sumOfWeights = 0;
		cout << "Enter the starting point: ";
		cin >> start;
		visited.push_back(start);
		while (visited.size() < n)
		{
			int min = 100, minPos = -1;
			for (int v1 : visited)
			{
				for (int v2 = 0; v2 < n; v2++)
				{
					if (visited.end() == find(visited.begin(), visited.end(), v2) && AdjMatrix[v1][v2] < min && AdjMatrix[v1][v2] != 0)
					{
						min = AdjMatrix[v1][v2];
						minPos = v2;
					}
				}
			}
			visited.push_back(minPos);
			sumOfWeights += min;
			cout << minPos << ": " << min << endl;
		}
	}
};

int main()
{
	Prims obj;
	int choice;
	while (true)
	{
		cout << "1. Create Graph" << endl;
		cout << "2. Display Graph" << endl;
		cout << "3. Prims" << endl;
		cout << "Enter Choice: ";
		cin >> choice;
		if (choice == 1)
			obj.input();
		else if (choice == 2)
			obj.display();
		else if (choice == 3)
			obj.prims();
		else
			break;
	}
}