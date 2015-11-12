#include <iostream>

using namespace std;

void cellChange(int *cells, int len, int n) {
	if (len == 0 || n == 0)
		return;
	
	int temp[len];
	while (n > 0) {
		temp[0] = cells[1];
		temp[len - 1] = cells[len - 2];
		for (int i = 1; i < len - 1; i++) {
			temp[i] = cells[i-1] == cells[i+1] ? 0:1;
		}
		for (int i = 0; i < len; i++) {
			cells[i] = temp[i];
		}

		n--;
	}
}

int main() {
	int *a = new int [4];
	a[0] = 0;
	a[1] = 1;
	a[2] = 1;
	a[3] = 1;
	
	cellChange(a, 4, 1);
	for (int i = 0; i < 4; i++) {
		cout << a[i] << " ";
	}
	return 0;
}