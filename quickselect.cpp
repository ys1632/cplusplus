#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

void quickSelect(vector<double> &dist, int left, int right, int k) {
	double pivot = dist[right];
	int p = left - 1;
	int q = left;
	while (q < right) {
		if (dist[q] < pivot) {
			p++;
			swap(dist[p], dist[q]);
		}
		q++;
	}

	swap(dist[p+1], dist[right]);

	if (p+1 == k - 1) return;
	else if (p+1 > k-1) quickSelect(dist, left, p, k);
	else quickSelect(dist, p+2, right, k);
}

int main() {
	vector<double> dist;
	dist.push_back(0.5);
	dist.push_back(3.5);
	dist.push_back(2.25);
	dist.push_back(1.5);
	dist.push_back(6.5);
	dist.push_back(4.5);
	dist.push_back(5.5);
	//sort(dist.begin(), dist.end());

	quickSelect(dist, 0, dist.size() - 1, 6);

	for (int i = 0; i < dist.size(); i++) 
		cout << dist[i] <<endl;
	return 0;
}