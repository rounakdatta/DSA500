// find all the possible solutions of N-Queen problem

#include <iostream>
#include <string.h>
using namespace std;

bool isSafe(char** board, int n, int row, int col)
{
	// check the same column for any queens
	for(int i = 0; i < row; i++)
	{
		if(board[i][col] == 'Q')
		{
			return false;
		}
	}

	// check the \ diagonal for any queens
	for(int i = 0, j = 0; i < row, j < col; i++, j++)
	{
		if(board[i][j] == 'Q')
		{
			return false;
		}
	}

	// check the / diagonal for any queens
	for(int i = 0, j = col - 1; i < row, j >= 0; i++, j--)
	{
		if(board[i][j] == 'Q')
		{
			return false;
		}
	}

	return true;
}

bool nqueen(char** board, int n, int row, int col)
{
	if(row >= n)
		return true;

	for(int i = 0; i < n; i++)
	{
		if(isSafe(board, n, row, i))
		{
			board[row][i] = 'Q';

			if(nqueen(board, n, row + 1, col))
			{
				return true;
			}

			board[row][i] = '-'; // backtrack back to null state of the cell
		}
	}

	return false;
}

int main()
{
	int n;
	cin >> n;

	char board[n][n];
	memset(board, '-', sizeof(board));

	nqueen((char**)board, n, 0, 0);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}