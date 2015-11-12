#include <iostream>
#include <vector>

using namespace std;

bool dfs(int i, int j, vector<vector<int> > maze, vector<vector<bool> > visited, int rows, int cols) {
	if (i < 0 || i >= rows || j < 0 || j >= cols) {
		return false;
	}
	if (visited[i][j]) return false;
	if (maze[i][j] == 0) return false;
	if (maze[i][j] == 9) return true;

	visited[i][j] = true;

	return dfs(i+1, j, maze, visited, rows, cols) || dfs(i-1, j, maze, visited, rows, cols) 
		|| dfs(i, j+1, maze, visited, rows, cols) || dfs(i, j-1, maze, visited, rows, cols);
}

bool find(vector<vector<int> > maze, int rows, int cols) {
	if (rows == 0 || cols == 0) return false;
	vector<vector<bool> > visited(rows, vector<bool>(cols, false));
	return dfs(0, 0, maze, visited, rows, cols);

}



int main() {
	vector<vector<int> > maze(3, vector<int> (3, 0));
	maze[0][0] = 1;
	maze[0][1] = 1;
	maze[0][2] = 1;
	maze[1][0] = 1;
	maze[1][1] = 1;
	maze[1][2] = 0;
	maze[2][0] = 1;
	maze[2][1] = 1;
	maze[2][2] = 9;
	cout << find(maze, 3, 3);
	return 0;
}