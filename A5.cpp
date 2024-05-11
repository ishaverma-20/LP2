//Implement Greedy Search algorithm on some application for :
//I.Kruskal’s Minimum Spanning Tree algorithm OR
//II.Dijkstra’s Minimum Spanning Tree algorithm

//Dijkstra’s Minimum Spanning Tree algorithm

#include <iostream>
#include <vector>
using namespace std;

class Dijkstra
{
	vector<vector<int>> AdjMatrix;
	int MAX = 100;
	int nodes;
	int minDistance(vector<int> distance, vector<bool> visited)
	{
		int min = MAX, minIndex = -1;
		for (int i = 0; i < nodes; i++)
		{
			if (visited[i] == false && distance[i] < min)
			{
				min = distance[i];
				minIndex = i;
			}
		}
		return minIndex;
	}
	void displaySolution(vector<int> distance, vector<bool> visited)
	{
		cout << ("Fixed: ");
		for (int i = 0; i < nodes; i++)
			if (visited[i])
				cout << i << " ";
		cout << endl;
		for (int i = 0; i < nodes; i++)
			cout << i << ": " << distance[i] << endl;
	}

public:
	void input()
	{
		cout << "Enter number of nodes: ";
		cin >> nodes;
		//AdjMatrix = new vector<vector<int>>(n, vector<int>(n, 0));
		for (int i = 0; i < nodes; i++)
		{
			vector<int> temp(nodes, 0);
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
	void dijkstras()
	{
		vector<bool> visited(nodes, false);
		vector<int> distance(nodes, MAX);
		int start;
		cout << "Enter source: ";
		cin >> start;

		distance[start] = 0;

		for (int i = 0; i < nodes - 1; i++)
		{
			int min = minDistance(distance, visited);
			if (min == -1)
			{
				cout << "Error" << endl;
				break;
			}
			else
			{
				visited[min] = true;
				for (int j = 0; j < nodes; j++)
				{
					if (visited[j] == false && AdjMatrix[min][j] != 0)//if the node is adjacent and not fixed
						if (distance[min] + AdjMatrix[min][j] < distance[j])	//if the distance through the min node is less than already distance of j then update
							distance[j] = distance[min] + AdjMatrix[min][j];
				}
				displaySolution(distance, visited);
			}
		}
		cout << "FINAL" << endl;
		displaySolution(distance, visited);
	}
};

int main()
{
	Dijkstra obj;
	int choice;
	while (true)
	{
		cout << "1. Input Graph" << endl;
		cout << "2. Display Graph" << endl;
		cout << "3. Dijkstra's Algorithm" << endl;
		cout << "Enter 0 to exit" << endl;
		cout << "Enter choice:";
		cin >> choice;
		if (choice == 0)
		{
			cout << "BYE" << endl;
			break;
		}
		else if (choice == 1)
			obj.input();
		else if (choice == 2)
			obj.display();
		else if (choice == 3)
			obj.dijkstras();
		else
			cout << "Invalid Input" << endl;
	}
	return 0;
}