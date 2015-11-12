#include <iostream>

using namespace std;

int getGCD(int a, int b) {
	if (a == b) return a;
	int small = a < b ? a : b;
	int large = a > b ? a : b;
	if (small == 0) return 0;
	int temp;
	while (small != 0) {
		temp = small;
		small = large % small;
		large = temp;
	}
	return large;
}

int GCD(int arr[], int len) {
	int gcd = arr[0];
	for (int i = 1; i < len; i++) {
		if (gcd == 0) return INT_MAX;
		gcd = getGCD(gcd, arr[i]);
	}
	return gcd;
}

//without recursion
int GCD2(int arr[], int len) {
	int minValue = INT_MAX;
	for (int i = 0; i < len; i++) {
		if (arr[i] == 0) return INT_MAX;
		minValue = minValue < arr[i] ? minValue : arr[i];
	}
	while (minValue > 1) {
		int mod = 0;
		for (int i = 0; i < len; i++) {
			mod += arr[i] % minValue;
		}
		if (mod == 0) return minValue;
		minValue--;
	}
	return minValue;
}

int main() {
	int arr[] = {0,36,90,12};
	int len = sizeof(arr) / sizeof(arr[0]);
	
	cout << GCD2(arr, len) << endl;

}