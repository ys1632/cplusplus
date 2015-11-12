#include <iostream>

using namespace std;

double SJF(int request[], int duration[], int len) {
	bool processed[len];
	int curEnd = 0;
	int total = 0;
	int minDuration = INT_MAX;
	int cnt = len;
	int index;

	// for (int i = 0; i < len; i++) {
	// 	processed[i] = false;
	// }
	 	
	while (cnt > 0) {
		//find out the shortest job
		for (int i = 0; i < len; i++) {
			if (!processed[i] && request[i] <= curEnd && duration[i] < minDuration) {
				index = i;
				minDuration = duration[i];
			}
		}
		processed[index] = true;
		total += curEnd - request[index];
		curEnd += duration[index];
		minDuration = INT_MAX;
		cnt--;
	}
	
	return (double) total / len;

}

int main() {
	int a[] = {0,2,5};
	int b[] = {7,4,1};
	cout << SJF(a, b, 3) << endl;
	return 0;
}