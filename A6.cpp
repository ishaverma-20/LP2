//Implement a solution for a Constraint Satisfaction Problem using Branch and Bound and Backtracking 
//for n–queens problem OR a graph coloring problem

//n-queens problem

#include <iostream>
#include <vector>
using namespace std;

class NQueens
{
	vector<vector<int>> board;
	vector<bool> rows, diagnols1, diagnols2;
	int n;
public:
	void input()
	{
		cout << "Enter n:";
		cin >> n;
		vector<vector<int>> b(n, vector<int>(n, 0));
		vector<bool> r(n, false), d1(n * 2 - 1, false), d2(n * 2 - 1, false);

		board = b;
		rows = r;
		diagnols1 = d1;
		diagnols2 = d2;
	}
	void display()
	{
		for (vector<int> row : board)
		{
			for (int i : row)
				cout << i << " ";
			cout << endl;
		}
	}
	bool isSafe(int row, int col)
	{
		if (rows[row] || diagnols1[row + col] || diagnols2[row - col + n - 1])
			return false;
		return true;
	}
	void place(int row, int col, bool type)
	{
		rows[row] = type;
		diagnols1[row + col] = type;
		diagnols2[row - col + n - 1] = type;
		board[row][col] = (type ? 1 : 0);
	}
	bool solve(int col)
	{
		if (col >= n)
			return true;
		for (int row = 0; row < n; row++)
		{
			if (isSafe(row, col))
			{
				place(row, col, true);
				if (solve(col + 1))
					return true;
				place(row, col, false);
			}
		}
		return false;
	}
};

int main()
{
	NQueens obj;
	obj.input();
	obj.display();
	cout << "-----------------------------------------------" << endl;
	obj.solve(0);
	obj.display();
	/*
	int choice;
	while (true)
	{
		cout << "1. Input" << endl;
		cout << "2. Display" << endl;
		cout << "3. Solve" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		if (choice == 1)
			obj.input();
		else if (choice == 2)
			obj.display();
		else if (choice == 3)
			obj.solve(0);
		else
			break;
	}
	*/
	return 0;
}