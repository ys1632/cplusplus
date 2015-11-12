#include <iostream>

using namespace std;

int **rotate (int **arr, int rows, int cols, bool flag){
	//int res[cols][rows];
	int **res = new int*[cols];
	for (int i = 0; i < cols; i++) {
		res[i] = new int[rows];
	}
	//clockwise
	if (flag) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				res[j][rows - 1 - i] = arr[i][j];
			}
		}
	} //counterclockwise
	else {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				res[cols - 1 - j][i] = arr[i][j];
			}
		}
	}

	return res;
}

int main() {
	int rows = 2;
	int cols = 3;
	int **a = new int *[rows];
	for (int i = 0; i < rows; i++) {
		a[i] = new int[cols];
	}

	a[0][0] = 3;
	a[0][1] = 2;
	a[0][2] = 1;
	a[1][0] = 6;
	a[1][1] = 4;
	a[1][2] = 7;
	
	int **b = rotate(a,rows,cols,true);



	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	} 
	return 0;
}