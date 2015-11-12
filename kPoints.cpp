#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

struct CPoint
{
	double x;
	double y;
	CPoint(double a, double b) : x(a), y(b) {}
};

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


void findKPoints(vector<CPoint> &nums, int k) {
	map<double, int> mp;
	vector<double> dist;
	for (int i = 0; i < nums.size(); i++) {
		dist.push_back(pow(nums[i].x, 2) + pow(nums[i].y, 2));
		mp[dist[i]] = i;
	}
	//nlog(n) 
	//sort(dist.begin(), dist.end());
	
	//can be O(n) using quick-select
	quickSelect(dist, 0, 2, k);

	for (int i = 0; i < k; i++) {
		cout << mp[dist[i]] << endl;
		
	}
	
}

int main() {
	vector<CPoint> nums;

	nums.push_back(CPoint(1.5, 1.5));
	nums.push_back(CPoint(0.5, -0.5));
	nums.push_back(CPoint(-1.0, -1.0));

	findKPoints(nums, 2);
	return 0;
}